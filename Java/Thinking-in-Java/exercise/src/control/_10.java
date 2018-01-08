//: control/_10.java
// Vampire numbers

package control;

import java.lang.Byte;
import java.util.Arrays;

public class _10 {
    public static void main(String[] args) {
        String[] arrStr1 = null, arrStr2;
        for (int i = 10; i <= 99; i++) {
            for (int j = 10; j <= 99; j++) {
                int ret = i * j;
                if (ret >= 1000 && ret <= 9999) {
                    if ((i % 10 == 0 && j % 10 == 0) || (i > j)) {
                        continue;
                    }
                    arrStr1 = String.valueOf(ret).split("");
                    arrStr2 = (String.valueOf(i) + String.valueOf(j)).split("");
                    java.util.Arrays.sort(arrStr1);
                    java.util.Arrays.sort(arrStr2);
                    if (java.util.Arrays.equals(arrStr1, arrStr2)) {
                        System.out.println("the number is: " + ret + ", and i is: " + i  + ", j is: " + j);
                    }
                }
            }
        }
    }
}
