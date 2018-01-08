package chapter2._8;

public class Incrementable {
    static void increment() {
        StaticTest.i++;
        System.out.println(StaticTest.i);
    }

    static void increment2() {
        StaticTest.i++;
        System.out.println(StaticTest.i);
    }

    /**
     * @param args
     * 两次的输出分别为48， 49
     */
    public static void main(String[] args) {
        Incrementable sf = new Incrementable();
        sf.increment();
        sf.increment2();
    }
}
