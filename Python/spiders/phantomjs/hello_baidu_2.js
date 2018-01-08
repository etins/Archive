var web_page = require('webpage');
var page = web_page.create();

var fs = require('fs');
var path = 'url.txt';

// 执行js函数时候不能直接调用Phantom的方法
page.onAlert = function(msg) {
    fs.write(path, msg, 'w')
}

page.injectJs("http://apps.bdimg.com/libs/jquery/2.1.4/jquery.min.js");


page.open("https://www.baidu.com", function(status) {
    //当打开成功后。输入检索内容并点击搜索
    //注意这两个按钮的的ID还是需要人为去看一下的
    if ( status === "success" ) {
        page.evaluate(function(text) {
            $("#kw").val(text);
            $("#su").click();
        }, "hello world");
    }
});


//我们需要获取资源加载成功的方法并重写
page.onResourceReceived = function (res) {
    if (res.stage == "end") {
        //我们仍然需要知道baidu搜索后的结束条件
        if (res.url.indexOf("https://www.baidu.com/s?ie=utf-8")>=0) {
            // console.log(res.url)
            //获取左边的所有标签并打印出text和链接
            page.evaluate(function() {
                var result="";
                $("#content_left a").each(function(){

                    // result=result+$(this).text()+"   "+$(this).attr("href")+"\n";
                });
                alert(result);
            });

            page.render('baidu.jpeg');
            phantom.exit();
        }
    }
};

