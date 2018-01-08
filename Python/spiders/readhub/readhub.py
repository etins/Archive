# -*- coding:utf-8 -*-

import re
import sys
import requests
import pymongo
import datetime
import multiprocessing as mp

def json_to_utf(text):
    return text.decode('unicode_escape').encode('utf-8')


def save_mongo(data):
    save_content = {
        'title': data[2],
        'time': data[0],
        'summary': data[1]
    }
    client = pymongo.MongoClient()
    db = client.test
    collection = db.readhub
    collection.insert(save_content)


def spider(params):
    url = 'https://api.readhub.me/topic'
    r = requests.get(url, params=params)
    
    text = r.text
    items = re.findall('"order":.*?"publishDate":(.*?),"relatedTopicArray".*?"summary":(.*?),"title":(.*?),"updatedAt"', text)
    if len(items) == 0:
        print 'data is null'
    else:
        print 'downloading url ....  ', r.url
        for item in items:
            save_mongo(item)




if __name__ == '__main__':
    start = datetime.datetime.now()
    startCursor = 32
    endCursor = 4697
    # 单进程  last time ... 0:19:28.295000
    # for i in range(startCursor, endCursor):
    #     params = {
    #     'lastCursor': i,
    #     'pageSize': 1
    #     }
    #     spider(params)
    
    # 多进程  last time ... 0:04:49.166000
    L = []
    for i in range(startCursor, endCursor):
        params = {
        'lastCursor': i,
        'pageSize': 1
        }
        L.append(params)
    p = mp.Pool()
    p.map_async(spider, L)
    p.close()
    p.join()

    end = datetime.datetime.now()
    print 'last time ...', end - start