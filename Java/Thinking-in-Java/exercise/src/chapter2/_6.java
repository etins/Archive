package chapter2;

public class _6 {
    public int storage(String s) {
        return s.length() * 2;
    }

    public static void main(String[] args) {
        _6 obj = new _6();
        int len = obj.storage("etins");
        System.out.println(len);
    }
}
