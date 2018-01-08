//: control/_9.java
// print fib number

package control;

import java.util.Arrays;

public class _9 {
    public static void fib(int n) {
        int[] fib = new int[n];
        fib[0] = 1;
        fib[1] = 1;
        fib[2] = 2;
        for(int i = 3; i < n; i++ ) {
            int fibn = fib[i - 1] + fib[i - 2];
            fib[i] = fibn;
        }
        System.out.print(Arrays.toString(fib));
    }
    public static void main(String[] args) {
        fib(5);
    }
}/* Output:
[1, 1, 2, 3, 5]
*///:~
