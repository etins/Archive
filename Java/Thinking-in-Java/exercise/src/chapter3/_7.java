//: chapter2/_6.java
// learn coins way
package chapter3;

import java.util.Random;

public class _7 {
    public static void main(String[] args) {
        Random rand = new Random();
        if (rand.nextInt(100) % 2 == 0) {
            System.out.println("This time is positive.");
        } else {
            System.out.println("This time is opposite.");
        }
    }
}
/**
 * Output:
 * This time is opposite.
 */
