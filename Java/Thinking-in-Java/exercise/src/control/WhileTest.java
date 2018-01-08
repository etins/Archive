//: contro/WhileTest.java
// Demonstrates the while loop.

package control;

public class WhileTest {
    static boolean condition() {
        boolean result = Math.random() < 0.99;
        System.out.println(result + ", ");
        return result;
    }

    public static void main(String[] args) {
        while(condition()) {
            System.out.println("Inside 'while'");
        }
        System.out.println("Exited 'while'");
    }
}/* Outout:
true,
Inside 'while'
true,
Inside 'while'
true,
Inside 'while'
false,
Exited 'while'
*///:~
