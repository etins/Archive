package initialization;

class Ban {
    String str1;
    String str2;
    {
        str1 = "Hello";
        str2 = "World";
    }
    public void pp() {
        System.out.println(str1);
        System.out.println(str2);
    }
}

public class _15 {
    public static void main(String[] args) {
        Ban ban = new Ban();
        ban.pp();
    }
}/* Output:
Hello
World
*///:~
