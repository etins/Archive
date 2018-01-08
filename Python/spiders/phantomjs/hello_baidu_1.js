// 加载 webpage 模型
var web_page = require('webpage')
// 创建具体的使用对象page
var page = web_page.create()
// 打开百度的页面，再完成时候调用匿名函数start
page.open("https://www.baidu.com", function start(status) {
    page.render('baidu.png')
    phantom.exit()
})