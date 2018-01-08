//: this is test initial order
package reusing;

import static net.mindview.util.Print.*;

class Insect {
    private int i = 9;
    protected int j;
    Insect() {
        print("i = " + i + ", j = " + j );
        j = 39;
    }
    private static int x1 =
            printInit("static Insect.x1 initialized");
    static int printInit(final String s) {
        print(s);
        return 47;
    }
}

public class Beetle extends Insect {
    private int k = printInit("Bettle.k initialized");
    public Beetle() {
        print("K = " + k);
        print("j = " + j);
    }
    private static int x2 =
            printInit("static Bettle.x2 initialized");
    public static void main(final String[] args) {
        print("Bettle constructor");
        Beetle b = new Beetle();
    }
}
/* Output:
static Insect.x1 initialized
static Bettle.x2 initialized
Bettle constructor
i = 9, j = 0
Bettle.k initialized
K = 47
j = 39
*///:~
