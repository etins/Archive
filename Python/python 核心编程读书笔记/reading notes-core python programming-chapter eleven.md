---
title: Reading notes-core python programming-chapter eleven
categories: tech
tags: python
---

## 第11章 函数和函数式编程 ##

### 什么是函数？

函数是对程序逻辑进行结构化或过程化的一种编程方法。能将整块代码巧妙地分隔成易于管理的小块，把重复代码放到函数中而不是进行大量的拷贝--这样既能节省空间又能保持一致性。

#### 函数vs过程 ###

Python的过程就是函数，因为解释器会隐士地返回默认值None

#### 返回值与函数类型 ###

函数会向调用者返回一个值，而实际编程中大部分偏函数更接近过程，不显示地返回任何东西。在python中，对应的返回对象类型none。

	>>> def hello():
	...     print 'hello world'
	>>> res = hello()
	hello world
	>>> res
	>>> print res
	None
	>>> type(res)
	<type 'NoneType'>

	>>> def bar():
	...     return 'abc', [42, 'python'], 'Guido'
	...

### 调用函数 ###

#### 函数操作符 ####

同大多数语言相同，我们用一对圆括号调用函数。

#### 关键字参数 ####

关键字参数的概念仅仅针对函数的调用。这种理念是让调用者通过函数调用中的参数名字来区分参数。这种理念是让调用者通过函数中的参数名字来区分参数。这样规范允许参数缺失或者不按顺序，因为解释器能通过给出的关键字来匹配参数的值。

#### 默认参数 ####

> pass

#### 参数组 ####

Python同样允许程序执行一个美誉显式定义参数的函数，相同的方法是通过一个元组或字典作为参数传递给函数。基本上你可以把所有参数放进一个元组或字典中，仅仅用这些有参数的容器来调用一个函数，而不必现实地将它们放在函数调用里。

	func(*tuple_grp_nonkw_args, **dict_grp_kw_args)

其中 *tuple_grep_nonkw_args是以元组形式体现的非关键字参数组，dict_grp_kw_args是装有关键字参数的字典。存在这样的特性允许把变量放在元组或者字典里。

### 创建函数 ###

#### def语句 ####

    def function_name(arguments):
        "function_documetation_string"
        function_body_suite

#### 声明与定义比较 ####

在某些编程语言里，函数声明和函数定义是区分开的。一个函数声明包括提供对函数名，参数的名字，但不必给出函数的任何代码，具体的代码通常属于函数定义的范畴。Python中将这两者视为一体。

#### 前向引用 ####

>pass

#### 函数属性 ####

命令空间，尤其是它们与变量作用域的关系。

可以获取每个python模块，类和函数中任意的名称空间。可以在模块foo和bar里都有名为x的一个变量，但是在将这两个模块导入你的程序后，任然可以使用这两个变量。

    import foo, bar
    print foo.x + bar.x


    def foo():
        'foo() --properly created doc string'
    def bar():
        pass
    bar.__doc__ = 'Oops, fogrot the doc str above'
    bar.version = 0.2

可以在函数声明之外定义一个文档字符串，然后可以像往常一样，在运行时刻访问它。

#### 内部/内嵌函数 ####

在函数体内创建另外一个函数是完全合法的。这种函数叫做内部/内嵌函数。

    def foo():
        def bar():
            print 'bar() called'
        print 'foo() called'
        bar()
    foo()
    bar()

内嵌函数一个有趣的方面在于整个函数都在外部函数的作用域之内，如果没有任何对内部函数的外部引用，那么除了在函数体内，任何地方都不能对其调用。

#### 函数装饰器 ####

装饰器背后的主要动机源自Python面向对象编程。装饰器实在函数调用之上的修饰。这些修饰仅是当声明一个函数或者方法的时候，才会应用的额外调用。

    @decorator(dec_opt_args)
    def func2Bdecorated(func_opt_args):


装饰器语法如何产生的呢？当背后的灵感是什么？

    class MyClass(object):
        def staticFoo():
            :
            staticFoo = staticmethod(staticFoo)
            :

在这个类的声明中，我们定义了叫staticFoo()的方法。现在因为打算让它成为静态方法，我们省去它的self参数。接着用staticmethod()内建函数来将这个函数转化为静态方法，但是在def staticFoo()后跟着staticFoo = staticmethod(staticFoo)显得多么臃肿。使用装饰器，你现在可以用如下的代码替换掉上面的：

    class MyClass(object):
        @staticmethod
        def staticFoo():
            :

装饰器可以如函数调用一样堆叠起来

    @deco2
    @deco1
    def func(arg1, arg2, ...) : pass

    def func(arg1, arg2, ...) : pass
    func = deco2( deco1(func) )

函数组合用数学来定义：(g.f)(x) = g( f(x) )。对于在Python中的一致性:

    @g
    @f
    def foo():
        :

等价于 foo = g( f(foo) )

装饰器实际就是函数，它们接受函数对象。从本质上，这些特征引入了Java开发者称之为AOP的概念。可以考虑在装饰器中置入通用功能的代码来降低程序复杂度。例如可以用装饰器来：

    - 引入日志
    - 增加计时逻辑来检测性能
    - 给函数加入事务的能力

### 传递函数 ###

当学习c时候，函数指针是一个高级话题，但对于Python来说，函数是可以被引用的，也可以作为参数传入函数，以及作为列表和字典等容器对象的元素函数有一个独一无二的特征使它同其它对象区分开来，那就是函数使可调用的。

所有的对象都是通过引用来传递的，函数也不例外。当对一个变量赋值时，实际时将相同的对象引用赋值给这个变量。如何对象时函数的话，这个对象所有的别名都是可调用的。

    >>> def foo():
    ...     print 'in foo()'
    ...
    >>> bar = foo
    >>> bar()
    in foo()
    >>> def bar(argfunc):
    ...     argfunc()
    ...
    >>> bar(foo)
    in foo()

### Formal Arguments

>pass

### 可变长度参数 ###
>pass

### 函数式编程 ###

#### 匿名函数与lambda

    lambda[arg1[, arg2, ... argN]] : expression
    >>> a = lambda x, y=2 : x + y
    >>> a(3)
    5
    >>> a(3, 5)
    8
    >>> a(0, 9)
    9

#### 内建函数apply(),filter(),map(),reduce()

fiter(), 给定一个对象的序列和一个过滤函数，每个序列元素通过这个过滤器进行筛选，保留函数返回真的对象

    >>> from random import randint
    >>>
    >>> def odd(n):
    ...     return n % 2
    ...
    >>> allNums = []
    >>> for eachNum in range(9):
    ...     allNums.append( randint(1, 99) )
    ... print filter(odd, allNums)

map(), 和filter()相似，因为也能通过函数处理序列。map()将函数调用映射到每个序列的元素上，并返回一个含有返回值的列表。

    >>> map( (lambda x: x + 2), [0,1,2,3,4,5] )
    [2,3,4,5,6,7]

reduce(),它去除序列的头两个元素，将它们传入二元函数获得一个单一的值来实现，然后有又用这个值和序列的下一个元素获得有一个值，然后继续直到整个序列的内容都遍历完毕以及最后的值会被计算出来为止。

    reduce(func, [1, 2, 3]) = func( func(1, 2), 3 )

#### 11.7.3 偏函数应用 ####

currying的概念将函数式编程的概念和默认参数以及可变参数结合在一起。一个带n的参数，curried函数固话第一个参数为固定参数，并返回另一个带n-1个参数函数对象。

1. 简单的函数式例子

    >>> from operator import add, mul
    >>> from functools import partial
    >>> add1 = partial(add, 1)       #add1(x) = add(1, x)
    >>> mul100 = partial(mul, 100)   #mul100(x) = mul(100, x)
    >>> add1(10)
    11
    >>> mul100(10)
    1000

### 变量作用于 ###

#### 闭包 ####

    >>> def counter(start_at = 0):
    ...     count = [start_at]
    ...     def incr():
    ...             count[0] += 1
    ...             return count[0]
    ...     return incr
    ...
    >>> count = counter(5)
    >>> print count()
    6

### 递归 ###

>pass

### 生成器 ###

>pass
















---EOF---
