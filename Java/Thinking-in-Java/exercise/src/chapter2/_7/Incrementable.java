package chapter2._7;

public class Incrementable {
    static void increment() {
        StaticTest.i++;
        System.out.print(StaticTest.i);
    }

    public static void main(String[] args) {
        Incrementable sf = new Incrementable();
        sf.increment();
    }
}
