//: chapter2/_9
// show the max and min number by float and double e
package chapter3;

public class _9 {
    public static void main(String[] args) {
        float fMax = Float.MAX_VALUE;
        float fMin = Float.MIN_VALUE;

        double dMax = Double.MAX_VALUE;
        double dMin = Double.MIN_VALUE;

        System.out.println("float max is: " + fMax);
        System.out.println("float min is: " + fMin);
        System.out.println("double max is: " + dMax);
        System.out.println("double min is: " + dMin);
    }
}
/**
 * Output:
 * float max is: 3.4028235E38
 * float min is: 1.4E-45
 * double max is: 1.7976931348623157E308
 * double min is: 4.9E-324
 */
