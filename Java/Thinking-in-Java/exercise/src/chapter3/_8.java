//: chapter/_8
package chapter3;

public class _8 {
    public static void main(String[] args){
        long sixteen1 = 0x4f;
        long sixteen2 = 0x40;
        long sum = sixteen1 + sixteen2;
        System.out.println("两个十六数相加和的二进制为：" + Long.toBinaryString(sum));
        long eight1 = 07;
        long eight2 = 011;
        sum = eight1+eight2;

        System.out.println("两个八进制数相加的和的二进制为： " + Long.toBinaryString(sum));
    }
}
/**
 *  OutPut:
 *  两个十六数相加和的二进制为：10001111
 *  两个八进制数相加的和的二进制为： 10000
 */