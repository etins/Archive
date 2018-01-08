//: initialization/_13.java

package initialization;

import static net.mindview.util.Print.*;

class Cup {
    Cup(int marker) {
        print("Cup (" + marker + ")");
    }
    void f(int marker) {
        printf("f(" + marker + ")");
    }
}

class Cups {
    static Cup cup1 = new Cup(1);
    static Cup cup2;
    static {
        cup2 = new Cup(2);
    }
    Cups() {
        print("Cups()");
    }
}

public class _13 {
    public static void main(String[] args) {
        print("Inside main()");
//        Cups.cup1.f(99);
    }
    static Cups cups1 = new Cups();
    static Cups cups2 = new Cups();
}
