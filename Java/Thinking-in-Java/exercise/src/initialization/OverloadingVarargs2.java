package initialization;

import java.lang.reflect.Type;

public class OverloadingVarargs2 {
    static void fucntion(Integer i, Character... args) {
        System.out.println(args.getClass());
        System.out.println("first");
    }
    static void fucntion(Character... args) {
        System.out.println("second");
    }
    public static void main(String[] args) {
        fucntion('a', 'b');
    }
}/* Output:
Error:(12, 9) java: 对f的引用不明确
  initialization.OverloadingVarargs2 中的方法 f(float,java.lang.Character...) 和 initialization.OverloadingVarargs2 中的方法 f(java.lang.Character...) 都匹配
*///:~