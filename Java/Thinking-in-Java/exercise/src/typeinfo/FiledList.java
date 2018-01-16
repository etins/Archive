package typeinfo;

import java.util.*;

class CountInteger {
    private static long counter;
    private final long id = counter++;
    public String toString() {
        return Long.toString(id);
    }
}

public class FiledList<T> {
    private Class<T> type;
    public FiledList(Class<T> type) {
        this.type = type;
    }
    public List<T> create(int nElements) {
        List<T> result = new ArrayList<>();
        try {
            for (int i = 0; i < nElements; i++)
                result.add(type.newInstance());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return result;
    }
    public static void main(String[] args) {
        FiledList<CountInteger> f1 =
                new FiledList<CountInteger>(CountInteger.class);
        System.out.println(f1.create(15));
    }
}
