package typeinfo.toys;

public class GenericToyTest {
    public static void main(String[] args) {
        Class<FancyToy> ftClass = FancyToy.class;
//        FancyToy facyToy = ftClass.newInstance();
        Class<? super FancyToy> up = ftClass.getSuperclass();
//        Object obj = up.newInstance();
    }
}
