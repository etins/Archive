//: initialization/_17.java

package initialization;

import java.util.Arrays;
import java.util.Random;

public class _17 {
    _17(String str) {
        System.out.print(str);
    }
    public static void main(String[] args) {
        Random random = new Random(47);
        _17[] cu = new _17[random.nextInt(10)];
        for (int i = 0; i < cu.length; i++) {
            cu[i] = new _17("cu" +
                    i);
        }
    }
}
