//: initialization/Overloading.java
// Demostration of both constructor
// and ordinary method overloading

package initialization;

import static net.mindview.util.Print.*;

class Tree {
    int height;
    Tree() {
        print("Planting a seeding");
        height = 0;
    }
    Tree(int initialHeight) {
        height = initialHeight;
        print("Creating new Tree that is " + height + " feet tall");
    }
    void info() {
        print("Tree is " + height + " feet tall" );
    }

    void info(String s) {
        print(s + ": Tree is " + height + " feet tail");
    }
}

public class Overloading {
    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            Tree t = new Tree(i);
            t.info();
            t.info("overload method");
        }

        new Tree();
    }
}/*
        Creating new Tree that is 0 feet tall
Tree is 0 feet tall
overload method: Tree is 0 feet tail
Creating new Tree that is 1 feet tall
Tree is 1 feet tall
overload method: Tree is 1 feet tail
Creating new Tree that is 2 feet tall
Tree is 2 feet tall
overload method: Tree is 2 feet tail
Creating new Tree that is 3 feet tall
Tree is 3 feet tall
overload method: Tree is 3 feet tail
Creating new Tree that is 4 feet tall
Tree is 4 feet tall
overload method: Tree is 4 feet tail
Planting a seeding
*///:~