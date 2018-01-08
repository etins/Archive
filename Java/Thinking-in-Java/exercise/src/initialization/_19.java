package initialization;

import java.util.Arrays;

public class _19 {
    _19(String[]... args) {
        for(String[] str : args) {
            System.out.println(Arrays.toString(str));
        }
    }

    public static void main(String[] args) {
        String[] str1 = {"a", ""};
        String[] str2 = {"a", "c"};
        new _19(str1, str2);
    }
}/* Output:
[a, ]
[a, c]
*///:~
