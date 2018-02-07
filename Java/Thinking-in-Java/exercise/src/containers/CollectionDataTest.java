package containers;

import net.mindview.util.CollectionData;
import net.mindview.util.Generator;

import java.util.*;

class Goverment implements Generator<String> {
    String[] foundation = ("strange women lying in ponds " +
        "distributing swords is no basics for a system of " +
        "goverment").split(" ");
    private int index;
    public String next() {
        return foundation[index++];
    }
}

public class CollectionDataTest {
    public static void main(String[] args) {
        Set<String> set = new LinkedHashSet<String>(
                new CollectionData<String>(new Goverment(), 15));
//        set.addAll(CollectionData.list(new Goverment(), 15));
        System.out.println(set);
    }
}
