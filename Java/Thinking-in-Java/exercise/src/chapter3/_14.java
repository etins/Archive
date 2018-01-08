//: chapter2/_14
// try compare operator
package chapter3;

public class _14 {
    public void compare(String x, String y) {
        System.out.println(x.equals(y));
        System.out.println(x == y);
        System.out.println(x != y);
    }

    public static void main(String[] args) {
        _14 obj = new _14();
        String x = "123";
        String y = "123";
        obj.compare(x, y);
    }
}
