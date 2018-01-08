import requests

headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.22 Safari/537.36 SE 2.X MetaSr 1.0',
    'X-requested-with': 'ShockwaveFlash/26.0.0.151',
    'referer': 'http://v.youku.com/v_show/id_XNzk2NTI0MzMy.html',
    'cookie': '__ysuid=1494080302688KY3; juid=01bfquf53bmbl; yseid=1503542802281NjGRl2; yseidcount=3; seid=01bo924trd1h9t; __aysvstp=3; cna=LsmUEfhxqwECAW/B4fMkfpc8; __ayscnt=1; __arcms=cms-00-1519-23042-0; __aypstp=3; logCookieKey=@1@%3Ftp%3D1%26cp%3D4004713%26cpp%3D1000217%5E; __ayft=1503542806096; __ayspstp=4; __yscnt=1; __aysid=1503542806096IDn; __ayvstp=4; isg=Ar6-xZXea_cEV78Gv1Z2XqkBD9TAVxj4xPeHmWjFWoHsC1rl142_iN2r9-A9; ypvid=1503543397108xurjIR; ysestep=4; yseidtimeout=1503550597110; ycid=0; ystep=9; referhost=; seidtimeout=1503545197118; P_ck_ctl=5DE5F692A1C5816540A266192CE80E10'

}

url = 'https://ups.youku.com/ups/get.json?vid=XNzk2NTI0MzMy&ccode=0401&client_ip=192.168.1.1&utid=LsmUEfhxqwECAW%2FB4fMkfpc8&client_ts=1503543401'

res = requests.get(url, headers=headers)
print res.json()

