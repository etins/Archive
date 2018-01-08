//: initialization/_12.java

package initialization;

public class _12 {
    boolean flag;

    _12(boolean flag) {
        this.flag = flag;
    }

    public void checkFlag() {
        flag = false;
    }

    protected void finalize() {
        if (flag == true) {
            System.out.println("Something error");
        }
        System.out.print("this is finalize() method");
    }

    public static void main(String[] args) {
        new _12(true);
        System.gc();
    }
}/* Output:
Something error
this is finalize() method
*///:~