# -*- coding: utf-8 -*-

import time
import requests
from lxml import etree

def get_url(url):
    url_list = []
    for i in range(1, 10):
        url_new = url + str(i)
        url_list.append(url_new)
    return url_list

def get_content(url):     # 获取网页内容
    user_agent = 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.22 Safari/537.36 SE 2.X MetaSr 1.0'
    headers = {'User-Agent': user_agent}
    req = requests.get(url=url, headers=headers)
    content = req.content
    return content.decode('utf-8')

def get_info(content):      # 提取网页信息 / ip 端口
    datas_ip = etree.HTML(content).xpath('//table[contains(@id,"ip_list")]/tr/td[2]/text()')
    datas_port = etree.HTML(content).xpath('//table[contains(@id,"ip_list")]/tr/td[3]/text()')
    with open("data.txt", "w") as fd:
        for i in range(0,len(datas_ip)):
            out = u""
            out += u"" + datas_ip[i]
            out += u":" + datas_port[i]
            fd.write(out + u"\n")     # 所有ip和端口号写入data文件


def verif_ip(ip,port):    # 验证ip有效性
    user_agent ='Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.22 Safari/537.36 SE 2.X MetaSr 1.0'
    headers = {'User-Agent':user_agent}
    proxy = {'http':'http://%s:%s'%(ip,port)}
    print(proxy)
    test_url = "https://www.baidu.com/"
    
    time.sleep(6)
    try:
        req = requests.get(test_url, headers=headers, proxies=proxy)
        content = req.content
        if content:
            print('that is ok')
            with open("data2.txt", "a") as fd:       # 有效ip保存到data2文件夹
                fd.write(ip + u":" + port)
                fd.write("\n")
        else:
            print('its not ok')
    except Exception as e:
        print(e)

if __name__ == '__main__':
    url = 'http://www.xicidaili.com/nn/'
    url_list = get_url(url)
    for i in url_list:
        print(i)
        content = get_content(i)
        time.sleep(3)
        get_info(content)

    with open("data.txt", "r") as fd:
        datas = fd.readlines()
        for data in datas:
            print(data.split(u":")[0])
            verif_ip(data.split(u":")[0],data.split(u":")[1])