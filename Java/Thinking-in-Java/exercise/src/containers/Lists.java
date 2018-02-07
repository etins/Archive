package containers;

import java.util.*;
import net.mindview.util.*;
import static net.mindview.util.Print.*;

public class Lists {
    private static boolean b;
    private static String s;
    private static int i;
    private static Iterator<String> it;
    private static ListIterator<String> lit;
    public static void basicTest(List<String> a) {
        a.add(1, "x"); // Add at location 1
        a.add("x");    // Add at the end
        a.addAll(Countries.names(25));
        a.addAll(3, Countries.names(25));
        b = a.contains("1");
        b = a.containsAll(Countries.names(25));
        // List allow random access, which is cheap
        // for ArrayList, expensive for LinkkedList:
        s = a.get(1);
        i = a.indexOf(s);
        b = a.isEmpty();
        it = a.iterator();
        lit = a.listIterator();
        lit = a.listIterator(3);
        i = a.lastIndexOf("1");
        a.remove(1);
        a.remove(3);
        a.set(1, "y");
        a.retainAll(Countries.names(25));
        a.removeAll(Countries.names(25));
        i = a.size();
        a.clear();
    }
    public static void iterMotion(List<String> a) {
        ListIterator<String> it = a.listIterator();
        b = it.hasNext();
        b = it.hasPrevious();
        s = it.next();
        i = it.nextIndex();
        s = it.previous();
        i = it.previousIndex();
    }
    public static void iterManipulation(List<String> a) {
        ListIterator<String> it = a.listIterator();
        it.add("47");
        it.next();
        it.remove();
        it.next();
        it.set("47");
    }
    public static void testVisual(List<String> a) {
        print(a);
        List<String> b = Countries.names(25);
        print("b = " + b);
        a.addAll(b);
        a.addAll(b);
        print(a);
        ListIterator<String> x = a.listIterator(a.size() / 2);
        x.add("one");
        print(a);
        print(x.next());
        x.remove();
        print(x.next());
        x.set("47");
        print(a);
        x = a.listIterator(a.size());
        while(x.hasPrevious())
            printnb(x.previous() + " ");
        print();
        print("testVisual finished");
    }
    // There are some things that only LinkedList can do:
    public static void testLinkedList() {
        LinkedList<String> ll = new LinkedList<String>();
        ll.addAll(Countries.names(25));
        print(11);
        ll.addFirst("one");
        ll.addFirst("two");
        print(ll);
        print(ll.getFirst());
        print(ll.removeFirst());
        print(ll.removeFirst());
        print(ll.removeLast());
        print(ll);
    }
}
