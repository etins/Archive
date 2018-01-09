package interfaces;

abstract class Jabc {
    Jabc() {
        print();
    }
    abstract void print();

}

public class _3 extends Jabc{
    public int i = 10;
    @Override
    public void print() {
        System.out.println(i);
    }

    public static void main(String[] args) {
        _3 obj = new _3();
        obj.print();
    }
}/*
执行基类构造方法时，i被初始化为0，所以打印0
之后导出类执行 print 方法时，i已经初始化为 10，所以打印10
*///:~