//: control/ifElse.java

package control;

import static net.mindview.util.Print.*;

public class IfElse {
    static int result = 0;
    static void test(int testVal, int target) {
        if (testVal > target)
            result += 1;
        else if (testVal < target)
            result = -1;
        else
            result = 0;
    }

    public static void main(String[] args) {
        test(10, 5);
        print(result);
        test(5, 10);
        print(result);
        test(5, 5);
        print(result);
    }
}/* Output:
1
-1
0
*///:~