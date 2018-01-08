//: control/_6.java

package control;

import static net.mindview.util.Print.*;

public class _6 {
    static int test(int testVal, int target, int begin, int end) {
        if ( testVal >= begin && testVal <= target) {
            print("it's in begin and end");
        } else {
            print("it's not in begin and end");
        }
        if (testVal > target)
            return +1;
        else if (testVal < target)
            return -1;
        else
            return 0;
    }

    public static void main(String[] args) {
        print(test(10, 5, 0, 10));
        print(test(5, 10, 0, 10));
        print(test(5, 5, 0, 10));
    }
}/* Output:
it's not in begin and end
1
it's in begin and end
-1
it's in begin and end
0
*///:~