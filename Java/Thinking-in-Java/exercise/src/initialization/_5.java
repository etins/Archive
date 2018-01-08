//: initialization/_5.java

package initialization;

public class _5 {
    _5(int i) {
        System.out.println("barking " + i);
    }
    _5(String str) {
        System.out.println("howling " + str);
    }

    public static void main(String[] args) {
        new _5(3);
        new _5("hello");
    }
}/* Output:
barking 3
howling hello
*///:~