//: polymorphism/shape/Circle.java

package polymorphism.Shape;
import static net.mindview.util.Print.print;

public class Circle extends Shape{
    @Override
    public void draw() { print("Circle.draw()"); }
    @Override
    public void erase() { print("Circle.erase()"); }
} ///:~


