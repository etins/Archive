package initialization;

enum Moneys {
    ONE, TWO, FIVE
}

public class _22 {
    _22(Moneys moneys) {
        this.moneys = moneys;
    }
    Moneys moneys;
    public void describe() {
        switch (moneys) {
            case ONE:
                System.out.println("one");
                break;
            case TWO:
                System.out.println("two");
                break;
            case FIVE:
                System.out.println("five");
                break;
        }
    }
    public static void main(String[] args) {
        _22 obj = new _22(Moneys.ONE);
        _22 obj2 = new _22(Moneys.TWO);
        _22 obj3 = new _22(Moneys.FIVE);
        obj.describe();
        obj2.describe();
        obj3.describe();
    }
}/* Output:
one
two
five
*///:~
