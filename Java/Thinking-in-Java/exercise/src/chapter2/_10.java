package chapter2;

import java.io.*;

public class _10 {
    public static void main(String args[]) {
        try {
            InputStreamReader isr = new InputStreamReader(System.in);
            System.out.println("args[0] = " +args[0]+ ", args[1] = "+ args[1] +", args[2] ="+ args[2]);
        }
        catch(Exception e) {
            System.out.println("这是一个异常测试");
            e.printStackTrace();
        }
    }
}
