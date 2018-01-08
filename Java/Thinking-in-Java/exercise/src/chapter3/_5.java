//： chapter2/_5.java
// show dog name and says
package chapter3;

public class _5 {
    String name;
    String says;

    public void show() {
        System.out.println("name is: " + this.name +
                    ", says is: " + this.says);
    }

    public static void main(String[] args) {
        _5 dog1 = new _5();
        dog1.name = "spot";
        dog1.says= "Ruff!";

        _5 dog2 = new _5();
        dog2.name = "scruffy";
        dog2.says = "Wurf!";

        dog1.show();
        dog2.show();
    }
}
/**
 * Output:
 * name is: spot, says is: Ruff!
 * name is: scruffy, says is: Wurf!
 */
