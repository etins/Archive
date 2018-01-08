package reusing;

class Soup {
    Soup() {
        System.out.println("this is soup");
    }
}

public class _1 {
    private Soup soup;
    _1() {
        if (soup == null) {
            soup = new Soup();
        }
    }
    public static void main(String[] args) {
        new _1();
    }
}
