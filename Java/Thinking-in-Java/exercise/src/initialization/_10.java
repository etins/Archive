//: initialization/_10.java

package initialization;

public class _10 {

    protected void finalize() {
        System.out.print("this is finalize method");
    }

    public static void main(String[] args) {
        new _10();
    }
}
/* Output:
nothing happends, because there is no gc
*///:~
