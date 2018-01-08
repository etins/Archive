package chapter2;

//: object/HelloDate.java
import  java.util.*;

/**
 *  The first Thinking in Java exampler program
 *  Dispalys a string and today's date.
 *  @author etins
 *  @author www.MindView.net
 *  @version 4.0
 *
 */
public class _12 {
    /**
     *  Entry point to class and application.
     *  @param args array of string arguments
     *  @throws exceptions No exceptions thrown
     */
    public static void main(String[] args) {
        System.out.println("Hello, it's: ");
        System.out.print(new Date());
    }
}
/**
 *  OutPut: (55% match)
 *  Hello. it's:
 *  Wed Oct 05 14:39:36 MDT 2005
 */
