//: initialization/_9.java

package initialization;

public class _9 {
    _9() {
        this(7);
        System.out.println("this is no parameters constructer");
    }

    _9(int i) {
        System.out.println("this is constructer whith paramter " + i);
    }

    public static void main(String[] args) {
        new _9();
    }
}/* Output:
this is constructer whith paramter 7
this is no parameters constructer
*///:~