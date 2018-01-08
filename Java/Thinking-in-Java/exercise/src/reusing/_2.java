package reusing;

import static net.mindview.util.Print.*;

class Cleanser {
    private String s = "Cleanser";
    public void append(String a) { s += a; }
    public void dilute() { append(" dilute() "); }
    public void apply() { append(" apply() "); }
    public void scrub() { append(" scrub() "); }
    public String toString() { return s; }
    public static void main(String[] args) {
        Cleanser x = new Cleanser();
        x.dilute(); x.apply(); x.scrub();
        print(x);
    }
}

class Detergent extends Cleanser {
    public void scrub() {
        append(" Detergent.scrub() ");
        super.scrub();
    }
    // Add methods to the interface:
    public void foam() { append(" foam() "); }
    // Test the new class:
    public static void main(String[] args) {
        Detergent x = new Detergent();
        x.dilute();
        x.apply();
        x.scrub();
        x.foam();
        print(x);
        print("Testing base class:");
        Cleanser.main(args);
    }
}

public class _2  extends  Detergent{
    public void scrub() {
        append("_2.scrub()");
    }
    public void sterilize() {
        append("_2.sterilize()");
    }
    public static void main(String[] args) {
        _2 obj = new _2();
        obj.scrub();
        obj.sterilize();
        print(obj);
    }
}
