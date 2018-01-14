package exceptions;

public class _1 {
    public static void main(String[] args) {
        try {
            throw  new Exception("this is exception");
        } catch (Exception e) {
            System.out.println("Caught" + e);
        }
        finally {
            System.out.println("This is finally");
        }
    }
}
