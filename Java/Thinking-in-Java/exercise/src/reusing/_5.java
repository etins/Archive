package reusing;

import static net.mindview.util.Print.*;

class A {
    A() { print("This is class A constructor"); }
}

class B {
    B() { print("This is class B constructor"); }
}
public class _5 extends A {
    private B b = new B();
    public static void main(String[] args) {
        new _5();
    }
}/*
This is class A constructor
This is class B constructor

先调用基类构造器，再初始化类成员
*///:~
