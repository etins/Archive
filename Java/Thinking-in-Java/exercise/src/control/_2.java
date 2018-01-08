//: control/_2.java
// random 2 number, and judge it compoare to before of it

package control;

import java.util.ArrayList;
import java.util.Random;

public class _2 {
    public static int random() {
        Random rand = new Random();
        return rand.nextInt();
    }

    public static void main(String[] args) {
        ArrayList gt = new ArrayList();
        ArrayList eq = new ArrayList();
        ArrayList lt = new ArrayList();
        int current = random();
        for (int i = 1; i < 25; i++) {
            int next = random();
            if (current > next) {
                gt.add(current);
            } else if (current < next) {
                lt.add(current);
            } else {
                eq.add(current);
            }
            current = next;
        }
        System.out.println("the gt list is: " + gt);
        System.out.println("the eq list is: " + eq);
        System.out.println("the lt list is: " + lt);
    }
}/*
...
*///:~
