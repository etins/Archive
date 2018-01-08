//: initialization/_4.java

package initialization;

public class _4 {
    _4(String str) {
        System.out.print("This is constructor, and you input" + str);
    }
    public static void main(String[] args) {
        new _4("new obj");
    }
}/* Output:
This is constructor, and you inputnew obj
*///:~