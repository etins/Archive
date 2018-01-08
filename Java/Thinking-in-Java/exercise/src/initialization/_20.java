package initialization;

public class _20 {
    public static void main (String... args){
        printStr("H","e","l","l","o");
        printStr(
                new String[] {"H","e","l","l","o",}/** 最后的逗号可有可无 **/
        );
    }
    /**
     * 运行结果：
     Hello
     Hello
     */

    public static void printStr(String ... strs){
        for(String str:strs){
            System.out.print(str);
        }
        System.out.println();
    }
}
