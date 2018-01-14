package exceptions;

class MyException extends Exception {
    String msg;
    MyException(String msg) {
        super(msg);
        this.msg = msg;
    }
    public void echo () {
        System.out.println(msg);
    }
}

public class _4 {
    public static void main(String[] args) {
        try {
            throw new MyException("This is msg");
        } catch (MyException e) {
            e.echo();
        }
    }
}
