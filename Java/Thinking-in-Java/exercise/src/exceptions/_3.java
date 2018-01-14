package exceptions;

import java.util.ArrayList;

public class _3 {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4 };
        try {
            Integer x = arr[5];
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e);
        } finally {

        }
    }
}
