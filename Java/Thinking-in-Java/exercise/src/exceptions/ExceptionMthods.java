package exceptions;

import static net.mindview.util.Print.*;

public class ExceptionMthods {
    public static void main(String[] args) {
        try {
            throw new Exception("My Exception");
        } catch (Exception e) {
            print("Caught Exception");
            print("getMessage" + e.getMessage());
            print("getLocalizedMessage(): " + e.getLocalizedMessage());
            print("toString(): " + e);
            print("printStackTrace(): ");
            e.printStackTrace(System.out);
        }
    }
}
