---
title: Reading notes-core python programming-chapter two
categories: tech
tags: python
---

## 第2章 快速入门 ##

### 2.1 Hello World ###

	>>> myString = 'Hello World!"
	>>> print myString
	Hello World!
	>>> myString
	'Hello World!'

在仅用变量名时，输出的字符串用单引号括起来的。为了时让非字符串对象也能以字符串的方式显示在屏幕上---既它显示的是该对象的字符串表示。事实上，print语句调用str()函数显示对象，而交互式解释器则用repr()函数显示对象。

下划线(_)在解释器中表示最后一个表达式的值。

    >>> printf "%s is number %d!" % ("Python", 1)
    python is number 1!

> 这个C语言中print是一个意思

	# 将结果输出到标准错误，也可以输出到文件
    import sys
	print >> sys.stderr, 'Fatal error: invalid input!'

### 2.2 程序输入和raw_input()内建函数

raw_input()读取标准输入，并将读取到的数据赋值给制定的变量。
int() 将数值字符串换成整型值，这样方便做数学运算。

    >>> num = raw_input('Now enter a number: ')
    Now enter a number: 1024
	>>> print 'Doubling your number: %d' % (int(num) * 2)
	Doubling your number: 2048

help() 函数可以得到相应的帮助信息。

	>>> help(raw_input)

### 2.3 注释 ###

	# one comment
	"This is a doc string"

### 2.4 操作符 ###

> pass

### 2.5 变量和赋值 ###

> pass

### 2.6 数字 ###

Python支持五种基本数字类型，其中三种是整型类型。

- 有符号整型
	- 长整型
	- 布尔值
- 浮点值
- 复数

### 2.7 字符串 ###

Python中字符串被定义为引号之间的字符集合。Python支持使用成对的单引号或者双引号，三引号可以用来包含特殊字符。使用索引操作符([])和切片操作符([])可以得到字符串。字符串尤其特有的索引规则：第一个字符的索引是0，最后一个字符的索引是-1。

加号(+)用于字符串连接运算， 星号(*)则用于字符串重复。下面是几个例子。

    >>> pystr = 'Python'
    >>> iscool = 'is cool!'
    >>> pystr[0]
    'P'
	>>> pystr[2:5]
	'tho'
	>>> iscool[:2]
	'is'
	>>> pystr + iscool
	'Pythonis cool!'
	>>> pystr * 2
	'PythonPython'
	>>> '-'*20
	'--------------------'
	>>> pystr = '''python
	...	is cool'''
	>>> 'python\nis cool'
	>>> print pystr
	python
	is cool
	>>>

### 2.8 列表和元祖 ###

可以把列表和元祖当成普通的“数组”，它能保存任意数量任意类型的Python对象。和数组一样，通过0开始的数字访问元素，但是列表和元祖可以存储不同类型的对象。

列表和元祖有几处重要的区别。列表元素用中括号（[]）包裹，元素的个数及元素的值可以改变。元祖元素用小括号（()）包裹，不可更改。可以将元祖视为只读的列表。通过切片运算可以得到子集，同字符串的使用方法一样。

    >>> aList = [1, 2, 3, 4]
	>>> aList
	[1, 2, 3, 4]
	>>> aList[0]
	1
	>>> aList[2:]
	[3, 4]
	>>> aList[:3]
	[1, 2, 3]
	>>> aList[1] = 5
	>>> aList
	[1, 5, 3, 4]

	>>> aTuple = (1, 2)
	>>> aTuple[1] = 5
	Traceback (most recent call last):
	  File "<stdin>", line 1, in <module>
	TypeError: 'tuple' object does not support item assignment

### 2.9 字典 ###

字典是Python中的映射数据类型，工作原理类似perl中的关联数组或者哈希表（PHP中同样是关联数组），由键值对构成。 几乎所有类型的Python对象都可以作为键，不过一般还是数字或者字符串最为常用。

值可以是任意类型的Python对象，字典元素用大括号（{}）包裹。

    >>> aDict = {'host': 'earth'}
	>>> aDict['port'] = 80
	>>> aDict
	{'host': 'earth', 'port': 80}
	>>> aDict,keys()
	Traceback (most recent call last):
	  File "<stdin>", line 1, in <module>
	NameError: name 'keys' is not defined
	>>> aDict.keys()
	['host', 'port']
	# 未缩进代码，所以报错
	>>> for key in aDict:
	... print key, aDict[key]
	  File "<stdin>", line 2
	    print key, aDict[key]
	        ^
	IndentationError: expected an indented block
	>>> for key in aDict:
	...     print key, aDict[key]
	...
	host earth
	port 80

### 2.10 代码库及缩进对齐 ###

> pass

### 2.11 if 语句 ###

> pass

### 2.12 while 循环 ###

> pass

### 2.13 for循环和range()内建函数 ###

Python中的for循环与传统的for循环不太一样， 它更像shell脚本里的foreach迭代。 Python中的for循环接受可迭代对象（例如序列或迭代器）作为其参数，每次迭代其中一个元素。

	# 迭代循环(循环元素)
    >>> for item in ['e-mail', 'net-sufing', 'homework', 'chat']:
	...     print item,
	...
	e-mail net-sufing homework chat

	# 计数循环
	>>> for eachNum in range(3):
	...     print eachNum,
	...
	0 1 2

	# range() 和 len() 函数用于字符串索引 （循环索引）
	>>> foo = 'abc'
	>>> for i in range(len(foo)):
	...     print foo[i], '(%d)' %i
	...
	a (0)
	b (1)
	c (2)

	# 同时循环元素和索引
	>>> for i, ch in enumerate(foo):
	...     print ch, '(%d)' % i
	...
	a (0)
	b (1)
	c (2)

### 2.14 列表解析 ###


	>>> squared = [x ** 2 for x in range(4)]
	>>> for i in squared:
	...     print i,
	...
	0 1 4 9
	# 挑选出 0-7 之间可以被2整出的数字，然后再将其平方作为一个列表
	>>> sqdEvens = [x ** 2 for x in range(8) if not x % 2]
	>>> for i in sqdEvens:
	...     print i,
	...
	0 4 16 36

### 2.15 文件和内建函数open(), file()

> pass

### 2.16 错误和异常 ###
	$ vim try.py
	  1 #!usr/bin/python
	  2
	  3 try:
	  4     filename = raw_input('Enter a file name: ')
	  5     fobj = open(filename, 'r')
	  6     for eachLine in fobj:
	  7         print eachLine
	  8     fobj.close()
	  9 except IOError, e:
	 10     print 'file open error:', e

    $ python try.py
	Enter a file name: test
	file open error: [Errno 2] No such file or directory: 'test'

### 2.17 函数 ###

函数在调用之前必须定义。 如果函数中没有return语句， 就会自动返回None对象。

Python是通过**引用调用**。这意味着函数内对参数的该表会影响到原始对象。但只有可变对象会受此影响，对不可变对象来说，它的行为类似按值调用。

### 2.18 类 ###

要指明的是,Python类中的__init__()方法不创建实例--它仅仅是创建对象之后执行的第一个方法。它的目的是执行一些该对象的必要的初始化工作。

### 2.19 模块 ###

一旦导入完成，一个模块的属性可以通过熟悉的句点属性标识访问。

module.function()

module.variable

### 2.20 实用的函数 ###

> pass

---EOF---
