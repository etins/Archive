//: initlization/_11.java

package initialization;

public class _11 {

    protected void finalize() {
        System.out.print("this is finalize() method");
    }

    public static void main(String[] args) {
        new _11();
        System.gc();
    }
}/*
this is finalize() method
force execute system gc
*///:~
