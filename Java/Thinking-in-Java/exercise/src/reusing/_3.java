package reusing;

import static net.mindview.util.Print.*;

class Arts {
    Arts() { print("Art constructor"); }
}

class Drawings extends Arts {
    Drawings() { print("Drawing constructor"); }
}

/**
 * class _3 没有构造器，却依旧调用了父类的构造器
 * 同时也可以说明 练习4， 总会被调用，并且在子类之前调用
 */
public class _3 extends Drawings {
    public static void main(String[] args) {
        new _3();
    }
}/*
Art constructor
Drawing constructor
*///:~
