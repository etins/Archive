package polymorphism.music3;
import polymorphism.music.Note;
import static net.mindview.util.Print.*;

class Instrument {
    void play(Note n) {
        print("Instrument.play()" + n);
    }
    void what() {
        System.out.println(this.getClass());
    }
    void adjust() {
        print("Adjusting Instrument");
    }
}

class Wind extends Instrument {
    void play(Note n) {
        print("Wind.play() " + n);
    }
    void what() {
        System.out.println(this.getClass());
    }
    void adjust() {
        print("Adjusting Wind");
    }
}

class Percussion extends Instrument {
    void play(Note n) {
        print("Percussion.play() " + n);
    }
    void what() {
        System.out.println(this.getClass());
    }
    void adjust() {
        print("Adjusting Percussion");
    }
}

class Stringed extends Instrument {
    void play (Note n) {
        print("Stringed.play() " + n);
    }
    void what () {
        System.out.println(this.getClass());
    }
    void adjuest() {
        print("Adjusting Stringed");
    }
}

class Brass extends Wind {
    void play(Note n) {
        print("Brass.play() " + n);
    }
    void what() {
        System.out.println(this.getClass());
    }
    void adjust() {
        print("Adjusting Brass");
    }
}

class Woodwind extends Wind {
    void play(Note n) {
        print("Woodwind.play() " + n);
    }
    void what() {
        System.out.println(this.getClass());
    }
}

public class Music3 {
    public static void tune(Instrument i) {
        i.play(Note.MIDDLE_C);
    }
    public static void tuneAll(Instrument[] e) {
        for (Instrument i : e) {
            tune(i);
        }
    }
    public static void main(String[] args) {
        Instrument[] orchestra = {
                new Wind(),

                new Percussion(),
                new Stringed(),
                new Brass(),
                new Woodwind(),
        };
        tuneAll(orchestra);
    }
}
