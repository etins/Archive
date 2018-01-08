package reusing;

class Amphibian {
    static void run(Amphibian amp) {
        amp.play();
    }
    public void play() {
        System.out.println("play");
    }
}

public class Frog extends Amphibian{
    public static void main (String[] args) {
        Frog frog = new Frog();
        Amphibian.run(frog);
    }
}/*
play
*///:~