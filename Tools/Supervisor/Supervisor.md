### 简介

Supervisor 是一个基于 Python 编写的后台进程管理工具，可以把普通的命令变为后台 daemon，并且监控进程状态，异常退出时能自动重启。

### 安装方式

通用安装方式```pip install supervisor```

常见Linux发行版本：
Ubuntu：```sudo apt install supervisor```
Centos  ```sudo yum install supervisor```

### 配置

不同的方式有微小的差别，但影响不大。

如果是以通用方式安装的，需要手动的将 supervisor 的配置文件放到 /etc 目录下，如果已经有就不要做下面这个操作了。
```
echo_supervisord_conf > /etc/supervisor/supervisord.conf
```
简单粗暴地贴下配置：
```
 ; supervisor config file

 [unix_http_server]
 file=/var/run/supervisor.sock   ; (the path to the socket file)
 chmod=0700                       ; sockef file mode (default 0700)

 [supervisord]
 logfile=/var/log/supervisor/supervisord.log ; (main log file;default $CWD/supervisord.log)
 pidfile=/var/run/supervisord.pid ; (supervisord pidfile;default supervisord.pid)
 childlogdir=/var/log/supervisor            ; ('AUTO' child log dir, default $TEMP)

 ; the below section must remain in the config file for RPC
 ; (supervisorctl/web interface) to work, additional interfaces may be
 ; added by defining them in separate rpcinterface: sections
 [rpcinterface:supervisor]
 supervisor.rpcinterface_factory = supervisor.rpcinterface:make_main_rpcinterface

 [supervisorctl]
 serverurl=unix:///var/run/supervisor.sock ; use a unix:// URL  for a unix socket

 ; The [include] section can just contain the "files" setting.  This
 ; setting can list multiple files (separated by whitespace or
 ; newlines).  It can also contain wildcards.  The filenames are
 ; interpreted as relative to this file.  Included files *cannot*
 ; include files themselves.

 [include]
 files = /etc/supervisor/conf.d/*.conf
```

要守护的进程单独配置到 /etc/supervisor/conf.d/*.conf 此文件，比如 example.conf

```
 [program:queue_server] ;项目名称
 directory = /www/swoole/ ; 程序的启动目录
 command = php /www/swoole/index.php  ; 启动命令，可以看出与手动在命令行启动的命令是一样
 autostart = true     ; 在 supervisord 启动的时候也自动启动
 startsecs = 5        ; 启动 5 秒后没有异常退出，就当作已经正常启动了
 autorestart = true   ; 程序异常退出后自动重启
 startretries = 3     ; 启动失败自动重试次数，默认是 3
 ; user = etins         ; 用哪个用户启动
 redirect_stderr = true  ; 把 stderr 重定向到 stdout，默认 false
 stdout_logfile_maxbytes = 50MB  ; stdout 日志文件大小，默认 50MB
 stdout_logfile_backups = 20     ; stdout 日志文件备份数
 ; stdout 日志文件，需要注意当指定目录不存在时无法正常启动，所以需要手动创建目录（supervisord               会自动创建日志文件）
 stdout_logfile = /wxb/www/swoole/logs/supervisor.log
 loglevel=info
 ;
 [supervisorctl]
 serverurl=unix:///var/run/supervisor.sock ; use a unix:// URL  for a unix socket
 ;
 [unix_http_server]
 file=var/run/supervisor.sock   ; (the path to the socket file)
 chmod=0777                 ; socket file mode (default 0700)
 ; chown=nobody:nogroup       ; socket file uid:gid owner
 ; ;username=shimeng              ; (default is no username (open server))
 ; ;password=123               ; (default is no password (open server))
 ;
 [inet_http_server]         ; inet (TCP) server disabled by defaul
 ; port=127.0.0.1:9001        ; (ip_address:port specifier, *:port for all iface)
 ; username=shimeng              ; (default is no username (open server))
 ; password=123

```

### 相关命令

supervisord 的命令很简单，有两类：一是和自身的管理相关的 supervisord ；而是和其所管理进程相关的 supervisorctrl

```
// 开启 supervisord 服务
supervisord -c /etc/supervisor/supervisord.conf 
// 查看所管理进程的装状态
supervisorctl status
// 启动进程
supervisorctl start queue_server
// 关闭进程
supervisorctl stop queue_server
```

### supervisor 的好处

也就是我们为什么要使用 supervisor 这样的进程管理工具？首先我们看下我们可以持久化运行的方式。

方案一：nohup,这个最简单方便，但是不稳定，异常推出后不能重启，这样的话是不能满足我们的需求的。

方案二：将我们要管理的进程安装为系统服务，那么这样我们有5个要管理的，就要写5个。

将要管理的进程作为系统服务，也可以很好的完成这个需求。但是这样的话系统和该进程之间关联太多了。那么此时部署项目的时候，就麻烦了。如果我们只是使用 supervisor，这样就在系统和要管理之间加了一层，可以方便地迁移以及部署。

