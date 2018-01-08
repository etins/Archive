package initialization;

enum Money {
    ONE, TWO, FIVE
}

public class _21 {
    public static void main(String[] args) {
        for (Money m : Money.values()) {
            System.out.println(m + ", ordinal " + m.ordinal());
        }
    }
}/* Output:
ONE, ordinal 0
TWO, ordinal 1
FIVE, ordinal 2
*///:~
