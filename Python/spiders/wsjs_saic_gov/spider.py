# -*- coding:utf-8 -*-

import time
import sys
from selenium import webdriver


# 输入具体的数值，以查询商标
def search(driver):
    try:
        driver.find_element_by_name("request:sn").clear()
        driver.find_element_by_name("request:sn").send_keys('20148825')
        driver.find_element_by_id("_searchButton").click()
    except Exception as e:
        print e
        time.sleep(0.2)
        driver.refresh()
        search(driver)
    print u'开始查询了，等待查询结果吧'
    time.sleep(6)

# 从商标页到商标状态检索
def band_to_search(driver):
    try:
        driver.find_element_by_id('txnS03').click()
    except Exception as e:
        print e
        time.sleep(0.2)
        driver.refresh()
        band_to_search(driver)
    time.sleep(5)
    print u'进入商标查询页'
    search(driver)

# 商标首页到商标页
def accept_to_band(driver):
    driver.find_element_by_xpath('//div[@class="TRS_Editor"]/p[1]').click() # 模拟点错
    time.sleep(0.2)
    driver.find_element_by_xpath('//div[@class="TRS_Editor"]/p[3]').click() # 模拟点错
    driver.find_element_by_xpath('//div[@class="TRS_Editor"]/p/a[@href]').click()
    print u'进入商标网上检索系统'
    time.sleep(5)
    band_to_search(driver)


# 开始爬
def spider(url):
    driver = webdriver.Chrome()
    driver.get(url)
    time.sleep(3)
    accept_to_band(driver)



if __name__ == '__main__':
    start_url = 'http://sbj.saic.gov.cn/sbcx/'
    # start_url = 'http://wsjs.saic.gov.cn'
    spider(start_url)