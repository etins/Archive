# -*- coding: utf-8 -*-
import os
import sys
import requests
import re
from lxml import etree

def save_file(save_path, file_name, data):
    if not os.path.exists(save_path):
        os.makedirs(save_path)
    path = save_path + '/' + file_name + '.txt'
    with open(path, 'w+') as fp:
        for s in data:
            fp.write('%s\t\t%s\n' % (s[0].encode('utf-8'), s[1].encode('utf-8')))

def page_info(page):
    dom = etree.HTML(page)
    new_items = dom.xpath('//div[@class="titleBar"]/h2/text()')
    new_urls = dom.xpath('//div[@class="more"]/a/@href')
    assert(len(new_items) == len(new_urls))
    return zip(new_items, new_urls)

def cat_page_info(page):
    dom = etree.HTML(page)
    items = dom.xpath('//tr/td/a/text()')
    urls = dom.xpath('//tr/td/a/@href')
    return zip(items, urls)

def spider(url):
    i = 0
    print 'downloading ', url
    my_page = requests.get(url).content.decode('gbk')
    my_page_result = page_info(my_page)
    save_path = u'网易新闻'
    file_name = str(i) + '_' + u'新闻排行榜'
    save_file(save_path, file_name, my_page_result)
    i += 1
    for item, url in my_page_result:
        i += 1
        print "downloading", url
        file_name = str(i) + '_' + item
        new_page = requests.get(url).content.decode('gbk')
        cat_page_result = cat_page_info(new_page)
        save_file(save_path, file_name, cat_page_result)

if __name__ == '__main__':
    print "start"
    start_url = "http://news.163.com/rank/"
    spider(start_url)
    print "end"