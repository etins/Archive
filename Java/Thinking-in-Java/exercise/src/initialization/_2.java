//: initialization/_2.java

package initialization;

class Tstring2 {
    String str1 = "str1";
    Tstring2(String str2) {
        System.out.println(str2);
    }
}

public class _2 {
    public static void main(String[] args) {
        Tstring2 ts = new Tstring2("str2");
        System.out.println(ts.str1);
    }
}/* Output:
str2
str1
*///:~
