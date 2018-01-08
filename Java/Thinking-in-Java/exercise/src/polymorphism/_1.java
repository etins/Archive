package polymorphism;

class Cycle {
    public static void ride(Cycle cycle) {
        System.out.println("ride");
    }
}

class Unicycle extends Cycle {

}

class Bicycly extends Cycle {

}

class Tricycle extends Cycle {

}

public class _1 {
    public void main(String[] args) {
        Cycle.ride(new Unicycle());
        Cycle.ride(new Bicycly());
        Cycle.ride(new Tricycle());
    }

}
