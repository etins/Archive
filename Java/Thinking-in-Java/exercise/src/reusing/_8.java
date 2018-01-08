package reusing;

class Base8 {
    Base8() {
        System.out.print("This is Base8 constructor");
    }
    Base8(int i) {
        System.out.print("This is Base8 constructor with paramter");
    }
}

public class _8 extends Base8{
    _8() {
        super();
    }
//    _8 (int i) {
//        super(i);
//    }
}/*
导出类都要调用基类的参数否早期
*///:~