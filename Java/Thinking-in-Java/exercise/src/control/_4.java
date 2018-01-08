//: contro;/_4.java;
// use for find prime number

package control;

import java.util.ArrayList;

public class _4 {


    public static void main(String[] args) {
        for (int i = 2; i > 0; i++) {
            boolean flag = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    flag = false;
                }
            }
            if (flag == true) {
                System.out.println(i);
            }
        }
    }

}/*
...
*///:~
