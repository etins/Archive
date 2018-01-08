---
title: Reading notes-core python programming-chapter six
categories: tech
tags: python
---

## 第6章 序列：字符串，列表和元组 ##

它的成员是有序排列的，并且可以通过下标偏移量访问到它的一个或者几个成员，这类Python称为序列，包括字符串，列表和元祖。

### 6.1 序列 ###

序列类型有着相同的访问模式：它的每一个元素可以通过指定一个偏移量的方式得到。而多个元素可以通过切片操作的方式一次得到，切片操作会在接下来的内容中讲到。下标偏移量是从0开始到总元素数-1结束。

#### 6.1.1 标准类型操作符 ###

便准类型操作符，一般都适用于所有的序列类型。当然如果复合类型的对象比较的话，这样说可能是需要有所保留，不过其他的操作是完全适用的。

#### 6.1.2 序列类型操作符 ####

1. 成员关系操作符(in, not in)

成员关系操作符就是用来判断一个元素是否属于一个序列的。

2. 连接操作符(+)

连接操作符允许我们把一个序列和另一个相同的序列做连接。

对于字符串来说，推荐用join方法，对于列表，推荐使用extend()方法。

3. 重复操作符(*)

4. 切片操作([], [:], [::])

    sequence[index]
	sequence[starting_index:ending_index]
	sequence[starting_index:ending_index:step]

	>>> ('Faye', 'Leanna', 'Daylen')[-100:100]
	('Faye', 'Leanna', 'Daylen')

#### 6.1.3 内建函数(BIF)

1. 类型转换

内建函数list(), str()和tuple()被用作在各种序列之间转换。这些转换实际上是工厂函数，将对象作为参数，并将其内容拷贝到新对象中。

一旦一个Python对象被建立，就不能更改其类型了

2. 可操作

enumerate(), len(), max(), min(), reversed(), soted(), sum()

### 6.2 字符串 ###

Python里面单引号和双引号的作用是相同的，这一点不同于其它的脚本语言。

Python实际上有三类字符串， 字符串(str)和Unicode字符串(unicode)实际上是抽象类basestring的子类。

    >>> s = str(range(4))
	>>> s
	'[1, 1, 2, 3]'

	>>> aString = "Hello World!"
	>>> aString = ""
	''
	>>> del aString

### 6.3 字符串和操作符 ###

#### 6.3.1 标准类型操作符 ####

> pass

#### 6.3.2 序列操作符切片([],[:])

> pass

### 6.4 只适用于字符串的操作符 ###

- 格式化操作符(%)
- 字符串模板
- 原始字符串操作符(r/R)
- Unicode 字符串操作符（u/U）

### 6.5 内建函数 ###

#### 6.5.1 标准类型行数 ####

cmp()，根据字符串的ASCII码值进行比较。

    >>> cmp('abc', 'xyz')
	-1
	>>> cmp('abcd', 'xyz')
	-1
	>>> cmp('xyz', 'abc')
	1
	>>> cmp('xb', 'aa')
	1
	>>> cmp('xb', 'az')
	1
	>>> cmp('xb', 'xz')
	-1
	>>> cmp('xb', 'ya')
	-1

#### 6.5.2 序列类型函数 ####

len(),max() and min()

    >>> str1 = 'abc'
	>>> str2 = 'xya'
	>>> max(str2)
	'y'
	>>> min(str2)
	'a'

enumetate() 提供一个可同时迭代对象和值的函数

	>>> s = 'foobar'
	>>> for i,t in enumerate(s):
	... 	print i, t
	...
	0 f
	1 o
	2 o
	3 b
	4 a
	5 r

zip()

	>>> z, t = 'foa', 'obr'
	>>> zip(s, t)
	[('f', 'o'), ('o', 'b'), ('o', 'r')]

#### 6.5.3 字符串类型函数 ####

raw_input()使用字符串提示用户输入并将这个输入返回

str() and unicode() 都是工厂函数， 就是说产生对应的类型的对象。

    >>> isinstance(u'\0xAB', str)
	False
	>>> isinstance(u'\0xAB', unicode)
	True
	>>> isinstance(u'\0xAB', basestring)
	True

chr()函数用范围在256以内的整数作为参数，返回一个对应的字符串。unichr()跟它一样，只不过返回的是Unicode字符。ord()函数或者unichr()函数返回一个字符对应的ACSII数值或者Unicode数值。

### 6.6 字符串内建函数 ###

    >>> quest = 'what is your favorite color?'
	>>> quest.capitalize()
	'What is your favorite color?'
	>>> quest.center(40)
	'      what is your favorite color?      '
	>>> quest.count('or')
	2
	>>> quest.endswith('blue')
	False
	>>> quest.endswith('color?')
	True
	>>> quest.find('or', 30)
	-1
	>>> quest.find('or', 22)
	25
	>>> quest.index('or')
	16
	>>> ':'.join(quest.split())
	'what:is:your:favorite:color?'
	>>> quest.replace('favorite color', 'quest')
	'what is your quest?'
	>>> quest.upper()
	'WHAT IS YOUR FAVORITE COLOR?'

### 6.7 字符串的独特性 ###

> pass

### 6.8 Unicode ###

Unicode 是计算机可以支持这个星球上最多语言的秘密武器。Unicode之前，用的都是ASCII。

如果一个Unicode字符串作为参数传给了str()函数，它会首先你被转换成ASCII字符串然后再交给str()函数。如果Unicode字符串中包含任何不被ASCII字符串支持的字符，会导致str()函数报异常。

codec是COder/DECoder的首字母组合。它定义了文本跟二进制的转换方式，跟ASCII那种一个字符把字符串转换成数字的方式不同，Unicode用的是多字节。这样Unicode支持多种不同的编码方式。比如说：ASCII，ISO 8859-1/Latin-1, UTF-8和UTF-16

### 6.9 相关模块 ###

|模块	| 描述 				|
|----	|:-----------------:|
|string | 字符串操作相关		|
|re		| 正则表达式			|
|struet | 字符串和二进制之间的转换 |
|StringIO | 字符串缓冲对象 	|
|base64 |Base16, 32和64数据编码 |
|codecs | 解码器注册和基类	|
|crypt	| 进行单方面加密		|
|difflib| 找出序列的不同		|
|hashlib| 多种不同哈希算法	|
|hma	| HMAC信息鉴权算法的Python实现 |
|md5	| RSA的md5信息照耀鉴权|
|rotor 	| 提供多平台的加解密服务 |
|sha	| NIAT的安全哈希算法SHA|
|stringgrep | 提供用于IP协议的Unicode字符串 |
|textwrap | 文本包装和填充 |
|unicodedata | Unicode数据库 |

### 6.10 字符串关键点总结 ###

1. 一些引号的分隔符， 可以不适用转义符
2. 不可分字符类型
3. 字符操作格式化
4. 三引号
5. 原始字符对每个特殊字符都使用它的原意
6. Python字符串不是通过NULL或者'\0'结束的

### 6.11 列表 ###

列表也是序列式数据类型，可以通过下标或者切片操作来访问一个或者某一块连续的元素。

    >>> aList = ['123', 'abc', 4.56, ['inner', 'list'], 7-9j]
	>>> aList.append('hi')
	>>> aList
	['123', 'abc', 4.56, ['inner', 'list'], (7-9j), 'hi']

	>>> del aList[1]
	>>> aList
	['123', 4.56, ['inner', 'list'], (7-9j), 'hi']

	>>> aList.remove('123')
	>>> aList
	[4.56, ['inner', 'list'], (7-9j), 'hi']

还可以通过pop()方法来删除并从列表中返回一个特定对象。

### 6.12 操作符 ###

#### 6.12.1 标准操作符 ####

    >>> list1 = ['abc', 123]
	>>> list2 = ['xyz', 789]
	>>> list3 = ['abc', 123]
	>>> list1 < list2
	True
	>>> list2 < list3 and list1 == list3
	False
	>>> list2 > list3 and list1 == list3
	True
比较逻辑如下：两个列表的元素分别比较，直到有一方的元素胜出。

#### 6.12.2 序列类型操作符 ####

1. 切片（[]和[:]）
2. 成员关系操作(in and not in)
3. 链接操作符(+)
4. 重复操作符(*)

#### 6.12.3 列表类型操作符和列表解析 ####

    >>> [ i * 2 for i in [1, 2, 3, 4] ]
	[2, 4, 6, 8]
	>>> [ i * 2 for i in range(8)  if i % 2 == 0 ]
	[0, 4, 8, 12]

### 6.13 内建函数 ###

cmp()

1. 对两个列表的元素进行比较
2. 如果比较的元素是同类型的，则比较其值，返回结果
3. 如果两个元素是不是同一种类型，则检查它们是否是数组
	1. 如果是数字，执行必要的强制类型转换，然后比较
	2. 如果有一方是数字，那么另一方的元素大(数字是最小的)
	3. 否则，通过类型名字的字幕顺序进行比较
4. 如果有一个列表先到末尾，则另一个长一点的列表大
5. 如果我们用尽了两个列表的元素而且所有元素都是相等的，那么结果就是平局

len()，返回列表或者元组的个数

max()和min()，混合对象的结构越复杂返回的结构准确性就越差

sorted() and reversed()，字符串排序使用的是字典序，而不是字幕序（字幕T的ASCII码值要比字母a的还要靠前）

enumerate() and zip()

sum()

list() and tuple()，这两个函数接受可迭代对象作为参数，并通过浅拷贝来创建一个新的列表或者元组。

### 6.14 列表类型的内建函数 ###

|	列表函数 	   | 	作用		|
|---------------   |:---------:|
|list.append(obj)  |向列表中添加一个对象 |
|list.count(obj)   |返回一个对象obj在列表中出现的次数 |
|list.extend(seq)  |把序列seq的内容添加到列表中 |
|list.index(obj,i=0,j=len(list)) | 返回在指定范围内的索引 |
|list.insert(index, obj) |在索引量为index的位置插入对象obj|
|list.prop(index=-1) | 删除并返回指定位置的对象，默认是最后一个对象 |
|list.remove(obj) | 从列表中删除对象obj|
|list.reverse() | 原地翻转列表 |
|list.sort() | 已制定的方式排序列表中的成员 |

在使用可变对象比如sort(), exntend()和reverse()时候，这些操作会在原地执行操作，也就是说列表的内容会改变，但是没有返回值。

### 6.15 列表的特殊性 ###

用列表构建其它数据结构

1. 堆栈
2. 队列

### 6.16 元组 ###

> pass

### 6.17 元组操作和内建函数 ###

> pass

### 6.18 元组的特殊特性 ###

> pass

### 6.19 相关模块 ###

|	模块		|		内容		|
|-----------|:-------------:|
|array		|一种受限制的可变序列类型，要求所有元素必须是相同的类型 |
|copy		|提供签拷贝和深拷贝的能力	|
|operator 	|包含函数调用形式的序列操作符	|
|re			|正则表达式	|
|StringIO	|把长字符当作文件来操作	|
|textwrap	|用作包装，填充文本的函数	|
|ytpes		|包含Python支持的所有类型	|
|colletions	|高性能容器数据类型		|

### 6.20 浅拷贝和深拷贝

对象赋值实际上是简单的对象引用。也就是说，当你创建一个对象，然后把它赋给另一个变量的时候，Python并没有拷贝这个对象，而是拷贝了这个对象的引用。

    >>> person = ['name', ['savings', 100.00]]
	>>> hubby = person[:]
	>>> wifey = list(person)
	>>> [id(x) for x in person, hubby, wifey]
	[7696579627704, 7696579738152, 7696579738512]
	>>> hubby[0] = 'joe'
	>>> wifey[0] = 'jane'
	>>> hubby, wifey
	(['joe', ['savings', 100.0]], ['jane', ['savings', 100.0]])
	>>> hubby[1][1] = 50.00
	>>> hubby, wifey
	(['joe', ['savings', 50.0]], ['jane', ['savings', 50.0]])

	>>> person = ['name', ['savings', 100]]
	>>> hubby = person
	>>> import copy
	>>> wifey = copy.deepcopy(person)
	>>> hubby[0] = 'joe'
	>>> wifey[0] = 'jane'
	>>> hubby, wifey
	(['joe', ['savings', 100]], ['jane', ['savings', 100]])
	>>> hubby[1][1] = 50.0
	>>> hubby, wifey
	(['joe', ['savings', 50.0]], ['jane', ['savings', 100]])

1. 非容器类型没有拷贝一说，浅拷贝是完全切片操作完成的
2. 如果元组变量只包含原子类型对象，对它的深拷贝不会进行

### 6.21 序列类型小结

> pass


---EOF---
