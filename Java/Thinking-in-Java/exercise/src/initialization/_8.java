//: initialization/_8.java

package initialization;

public class _8 {
    public void fun1() {
        fun2();
        this.fun2();
    }

    public void fun2() {
        System.out.println("i woked");
    }

    public static void main(String[] args) {
        new _8().fun1();
    }
}/* Output:
i woked
i woked
*///:~
