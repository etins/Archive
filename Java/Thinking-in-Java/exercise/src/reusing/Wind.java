package reusing;

class Instrument {
    public void play() {
        System.out.println("This is instrument");
    }
    static void tune(Instrument i) {
        i.play();
    }
}

public class Wind extends Instrument{
    @Override
    public void play() {
        System.out.println("This is wind");
    }
    public static void main(String[] args) {
        Wind flute = new Wind();
        Instrument.tune(flute);
    }
}/*
tune()方法可以接受Instument引用
*///:~