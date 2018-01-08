---
title: Reading notes-core python programming-chapter thirteen
categories: tech
tags: python
---

## 第13章 面向对象 ##

### 多重集成 ###

目前位置我接触的语言都是OOP，Java, PHP，Python,Python是支持多重继承的，允许子类继承多个基类。

    class P1: #(object):
        def foo(self):
            print 'called P1-foo()'

    class P2: #(object):
        def foo(self):
            print 'called P2-foo()'

        def bar(self):
            print 'called P2-bar()'

    class C1(P1, P2):
        pass

    class C2(P1, P2):
        def bar(self):
            print 'called C2-bar()'

    class GC(C1, C2):
        pass

如果是经典类，深度优先，从左至右

    >>> gc = GC()
    >>> gc.foo()       # GC=>C1=>P1
    called P1-foo()
    >>> gc.bar()       #GC=>C1=>P1=>P2
    called P2-bar()

当调用foo()时，它首先在当前类（GC）中查找，如果没找到，就向上查找最亲的父类，从C1。如果没有，就继续向上访问到父类P1.foo()被找到。

同样对于bar()，通过搜索GC,C1,P1然后找到P2。因为这种解释顺序的缘故，C2.bar()根本不会被搜索到。

如果要调用C2的bar()方法，需要如下操作：

    >>> gc = GC()
    >>> C2.bar(gc)
    called C2-bar()

如果是新式类,则会采用广度优先的方式：

    >>> gc = GC()
    >>> gc.foo()       # GC=>C1=>C2=>P1
    called P1-foo()
    >>> gc.bar()       #GC=>C1=>C2
    called P2-bar()

这个就不过多解释了。有一个__mro__属性，告诉你查找顺序时怎样的。

### 一些内建函数 ###

#### issubclass() ####

issubclass()布尔函数判断一个类是另一个类的子孙类

#### supper() ####

supper()函数可以找出相应的父类，然后调用相关的属性

### 属性的私有化 ###

#### 双下划线 ####

Python为类元素的死游行提供初步的形式。由双下划线开始的属性在运行时被‘混淆’，所以直接访问是不允许的。可以理解为private。

#### 单下划线 ####

简单的模块私有化只需要在属性名前使用一个单下划线字符。可以理解为protected。
