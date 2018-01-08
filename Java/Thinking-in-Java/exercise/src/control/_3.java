//: control/_3.java
// random 3 number, and judge it compoare to before of it

package control;

import java.util.ArrayList;
import java.util.Random;

public class _3 {
    public static int random() {
        Random rand = new Random();
        return rand.nextInt();
    }

    public static void main(String[] args) {
        ArrayList gt = new ArrayList();
        ArrayList eq = new ArrayList();
        ArrayList lt = new ArrayList();
        int current = random();
        while(true) {
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
    }
}/*
ok, please don't run this program
*///:~