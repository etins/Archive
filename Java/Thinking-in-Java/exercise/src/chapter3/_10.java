//: chapter2/_10
// bit cal
package chapter3;

public class _10 {
    public static void main(String[] args) {
        int i1 = 0xaaaaaaaa;
        int i2 = 0x55555555;
        System.out.println("i1 = " + Integer.toBinaryString(i1));
        System.out.println("i2 = " + Integer.toBinaryString(i2));
        System.out.println("~i1 = " + Integer.toBinaryString(~i1));
        System.out.println("~i2 = " + Integer.toBinaryString(~i2));
        System.out.println("i1 & i1 = " + Integer.toBinaryString(i1 & i1));
        System.out.println("i1 | i1 = " + Integer.toBinaryString(i1 | i1));
        System.out.println("i1 ^ i1 = " + Integer.toBinaryString(i1 ^ i1));
        System.out.println("i1 & i2 = " + Integer.toBinaryString(i1 & i2));
        System.out.println("i1 | i2 = " + Integer.toBinaryString(i1 | i2));
        System.out.println("i1 ^ i2 = " + Integer.toBinaryString(i1 ^ i2));
    }
}
/**
 * i1 = 10101010101010101010101010101010
 * i2 = 1010101010101010101010101010101
 * ~i1 = 1010101010101010101010101010101
 * ~i2 = 10101010101010101010101010101010
 * i1 & i1 = 10101010101010101010101010101010
 * i1 | i1 = 10101010101010101010101010101010
 * i1 ^ i1 = 0
 * i1 & i2 = 0
 * i1 | i2 = 11111111111111111111111111111111
 * i1 ^ i2 = 11111111111111111111111111111111
 */