//： chapter2/_5.java
// show dog name and says
package chapter3;

public class _6 {
    String name;
    String says;

    public void show() {
        System.out.println("name is: " + this.name +
                ", says is: " + this.says);
    }

    public boolean equeals(_6 dog) {
        return this.name == dog.name;
    }

    public static void main(String[] args) {
        _6 dog1 = new _6();
        dog1.name = "spot";
        dog1.says= "Ruff!";

        _6 newDog = new _6();
        newDog = dog1;

        System.out.print(newDog == dog1);
        System.out.print(newDog.equeals(dog1));

    }
}
/**
 * Output:
 * name is: spot, says is: Ruff!
 * name is: scruffy, says is: Wurf!
 */
