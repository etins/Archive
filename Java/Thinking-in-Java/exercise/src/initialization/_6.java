//: initialization/_6.java

package initialization;

public class _6 {
    _6(int i, String str) {
        System.out.println("barking " + i);
    }
    _6(String str, int i) {
        System.out.println("howling " + str);
    }

    public static void main(String[] args) {
        new _6(3, "hello");
        new _6("hello", 3);
    }
}/* Output:
barking 3
howling hello
*///:~
