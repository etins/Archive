package initialization;

class Apple {

    static String str2;
    static {
        str2 = "World";
    }
    static String str1 = "Hello";
    public static void pp() {
        System.out.println(str1);
        System.out.println(str2);
    }
}

public class _14 {
    public static void main(String[] args) {
        Apple.pp();
    }
}
