# -*- coding: utf-8 -*-

import re
import sys
import pymongo
import requests
import multiprocessing as mp
from lxml import etree


# 获取页面内容
def get_content(url):
    if ('http:' not in url ):
        url = 'http:' + url
    print 'downloading url...', url
    headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.22 Safari/537.36 SE 2.X MetaSr 1.0'
    }
    try:
        req = requests.get(url, headers=headers)
        return req.content
    except BaseException:
        return False

# 获取不同年份的url,返回列表
def url_by_year(content):
    dom = etree.HTML(content)
    return dom.xpath('//div[@id="filterPanel"]/div[4]/ul/li/a[@href]/@href')

# 获取下一页的url，返回列表
def url_by_page(content):
    dom = etree.HTML(content)
    last_page = dom.xpath('//ul[@class="yk-pages"]/li[last()-1]/a/text()')
    last_url = dom.xpath('//ul[@class="yk-pages"]/li[3]/a/@href')
    page_urls = []
    for i in range(int(last_page[0])):
        page_url = last_url[0][:-6] + str(i+1) +  '.html'
        page_urls.append(page_url)
    return page_urls

# 获取指定年份指定页数下影片列表的url
def url_video_detail(content):
    dom = etree.HTML(content)
    return dom.xpath('//div[@class="p-thumb"]/a/@href')


def default_xpath(dom, xpath):
    try:
        res = dom.xpath(xpath)[0]
    except IndexError as e:
        print e
        res = ' unknown'
    return res

# 获取影片具体信息
def video_detail(url):
    content = get_content(url)
    if content:
        try:
            dom_detail = etree.HTML(content)
            url_desc = default_xpath(dom_detail, '//a[@class="desc-link"]/@href')
        except ValueError as e:
            print e
            quit()
            
        else:
            video_desc = get_content(url_desc)
            if video_desc:
                dom_desc = etree.HTML(video_desc)
                name = default_xpath(dom_desc, '//li[@class="p-row p-title"]/text()')
                year = default_xpath(dom_desc, '//span[@class="pub"]/text()')
                alias = default_xpath(dom_desc, '//li[@class="p-alias"]/@title')
                performer = default_xpath(dom_desc, '//li[@class="p-performer"]/@title')
                director = default_xpath(dom_desc, '//div[@class="p-base"]/ul/li[7]/text()')
                area = default_xpath(dom_desc, '//div[@class="p-base"]/ul/li[8]/a/text()')
                desc = default_xpath(dom_desc, '//li[@class="p-row p-intro"]/span[@class="intro-more hide"]/text()')
                score = default_xpath(dom_desc, '//span[@class="star-num"]/text()')

                save_content = {
                    'url': url,
                    'name': name[1:],
                    'year': year,
                    'alias': alias,
                    'performer': performer,
                    'director': director,
                    'area': area,
                    'desc': desc,
                    'score': score
                }
                return save_content


def save_mongo(data):
    if data:
        client = pymongo.MongoClient()
        db = client.spiders
        collection = db.youku
        collection.insert(data)


# 爬取电影列表页url地址
def spider(url):
    content = get_content(url)
    url_years = url_by_year(content)
    for url_year in url_years:
        # 拼接url并获取内容
        content_year = get_content(url_year)
        if content_year:
            url_pages = url_by_page(content_year)
            for url_page in url_pages:
                content_page = get_content(url_page)
                if content_page:
                    url_videos =  url_video_detail(content_page)
                    for url_video in url_videos:
                        detail = video_detail(url_video)
                        save_mongo(detail)

if __name__ == '__main__':
    start_url = 'http://list.youku.com/category/show/c_96_r__pt_1_s_1_d_4.html?spm=a2h1n.8251845.filterPanel.5!4~1~3~A'
    spider(start_url)