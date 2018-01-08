---
title: Reading notes-core python programming-chapter ten
categories: tech
tags: python
---

## 第10章 文件和输入输出 ##

### 10.1 什么是异常 ###

#### 10.1.1 错误 ####

错误是语法或是逻辑上的。语法错误指示软件的结构上由错误，导致不能被解释器解释或编译器无法编译。

逻辑错误可能是由于不完整或是不合法的输入所致；其它情况下，还可能是逻辑无法生成，计算，或是输出结果需要的过程无法执行。这些错误统称为域错误和范围错误。

#### 10.1.2 异常 ####

它是因为程序出现了错误而正常控制流以外采取的行为。这个行为又分为两个阶段：首先是引起异常发生的错误，然后是检测阶段。

第一个阶段是在发生了一个异常条件后发生的。只要检测到错误并且意识到异常条件，解释器会引发一个异常。Python也允许程序员自己引发异常。无论是Python解释器还是程序员引发的，异常就是错误发生的信号。当前流被打断，用来处理这个错误并采取相应的操作。

第二个阶段，异常引发后，可以调用很多不同的操作。可以是忽略错误，或是减轻问题的影响后设没法继续执行程序。关键是程序员在错误发生时可以指示程序如何执行。

程序运行时发生的错误主要是由外部原因引起的，例如非法输入或者操作失败等。这些因素并不在程序员的直接控制下，而程序员只能预见一部分错误，编写常见的补救措施代码。

### 10.2 Python中的异常 ###

1. NameError:尝试访问一个未申明的变量
2. ZeroDivisionError: 除数为零
3. SyntaxError: Python解释器语法错误
4. IndexError:请求的索引超出序列范围
5. keyError:输入/输出错误
6. AttributeError:尝试访问未知的对象属性

### 10.3 检测和处理异常 ###

#### 10.3.1 try-except语句 ####

    try:
		try_suite	#监控这里的异常
	except	Exception[, reason]:
		except_suite #异常处理代码


#### 10.3.2 包装内建函数 ####

#### 10.3.4 处理多个异常的except语句 ####

      1 # !/usr/bin/python
	  2
	  3 def safe_float(obj):
	  4     try:
	  5         retval = float(obj)
	  6     except  (ValueError, TypeError):
	  7         retval = 'argument must be a number or numeric string'
	  8     return retval;

#### 10.3.5 捕获所有异常 ####

    try:
		:
	except BaseException, e:
		#handle all errors

一个不正确的使用方法就是把它作为一个大绷带绑定到一大片代码上，也就是说把一大段程序放入一个try块中，再用一个通用的except语句过滤到任何致命错误忽略它们。

这样就会忽略许多错误，这样的用法时缺乏工程实践的表现，不赞同。

底线： 避免把大片的代码装入try-except中然后使用pass忽略掉错误。你可以捕获特定的异常并忽略它们，或是捕获所有异常并采取特定的东许哦。不要捕获所有异常，然后忽略掉它们。

#### 10.3.6 异常参数

异常也可以由参数，异常引发后它会被传递给异常处理器。当异常被引发后参数时作为附加信息传递给异常处理器的。虽然异常原因时可选的，但标准内建异常提供至少一个参数，指示异常原因的一个字符串。

异常的参数可以再处理器里忽略，但Python提供了保存这个值的语法。

reason将会是一个包含来自导致异常的代码的诊断信息的类实例。异常参数自身会组成一个元祖，并存储为实例的属性。对于大多内建异常，这个元组只包含一个指示错误原因的字符串。一般来说，异常的名字已经是一个满意的线索了，但这个错误字符串会提供更多的信息。

    >>> try:
	...     float(['float() does not', 'like lists', 2])
	... except TypeError, diag:# capture diagnostic info
	...     pass
	...
	>>> type(diag)
	<type 'exceptions.TypeError'>
	>>> print diag
	float() argument must be a string or a number

我们首先再一个try语句中引发一个异常，随后忽略这个异常，但保留了错误的信息。

	>>> def safe_float(object):
	...     try:
	...             retval = float(object)
	...     except (ValueError, TypeError), diag:
	...             retval = str(diag)
	...     return retval
	...
	>>> safe_float('xyz')
	'could not convert string to float: xyz'
	>>> safe_float({})
	'float() argument must be a string or a number'

#### 10.3.7 应用 ####

> pass

#### 10.3.8 else子句 ####

> pass

#### 10.3.9 finally子句 ####

> pass

### 10.4 上下文管理 ###

with语句时简化代码的，try-except和try-finally的一种特定的配合用法是保证共享的资源的唯一分配，并在任务结束的时候释放它。比如文（数据、日志、数据库等等）、线程资源、简单同步、数据库连接，等等。with语句的目标就是应用在这种场景。

    with contxt_expr [as var]:
		with_suite

不能对Python的任意符号使用with语句，它仅仅能工作于支持上下文管理协议的对象。这显然意味着只有内建了上下文管理的对象可以和with一起工作。


- file
- decimal.Context
- thread.LockType
- threading.Lock
- threading.RLock
- threading.Condition
- threading.Semaphore
- threading.BoundedSemaphore

### 10.5 字符串作为异常 ###

> pass

### 10.6 触发异常 ###

异常都是解释器引发的。由于执行期间的错误而引发。程序员在编写API时也希望遇到错误的输入触发异常，为此Python提供了一中机制让程序员明确的触发异常，这就是raise语句。

    raise[SomeException [, args [, traceback]]]

第一个参数是出发异常的名字

第二个参数是可选的args，来传给异常。这可以是单独的对象也可以是一个对象的元组。

### 10.7 断言 ###

断言是一句必须等价于布尔值的判断；此外，发生异常也意味着表达式为假。这些工作类似于C语言预处理器中assert宏，但它们在Pyton运行时构建。

### 10.8 标准异常 ###

> pass

### 10.9 创建异常 ###

> pass

### 10.10 为什么用异常 ###
>
> pass

### 10.11 到底为什么要异常 ###

> pass

### 10.12 异常和sys模块 ###

> pass







































---EOF---
