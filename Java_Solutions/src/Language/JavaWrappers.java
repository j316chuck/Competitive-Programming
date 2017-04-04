package Language;
import java.util.*;
import java.io.*;

public class JavaWrappers {

    /*static void f1(int a, int b) {
        System.out.println("f1");
    }
    static void f1(Integer a, int b) {
        System.out.println("f2");
    }
    static void f1(Integer a, Integer b) {
        System.out.println("f3");
    }
    static void f1(double a, double b) {
        System.out.println("f4");
    }
    static void f1(double a, int b) {
        System.out.println("f5");
    }
    static void f1(Double a, int b) {
        System.out.println("f6");
    }
    static void f1(Double a, Integer b) {
        System.out.println("f7");
    }
    static void f1(Double a, Double b) {
        System.out.println("f8");
    }*/
    static void f1(Long a) {
        System.out.println("1");
    }

    public static void main(String[] args) {
        //Integer wrapper class functions:
        //Integer.parseInt() .compareTo(), .hashCode(). toString() . equals();
        //Integer to int always fine
        //you can always go from smaller to wider...
        //cannot go from wider to smaller must cast...

        //Integer to int
        Integer int1 = 5;
        int int2 = int1;

        //same rules apply for functions function(int, int) means you have to pass in
        // two ints or Int, int or Integer, Integer
        //cannot cast from Integer to Double;

        //int to double, Integer to double, smaller to wider
        double d1 = int1;
        double d3 = int2;
        Double d4 = 12d; //key cannot do just 12 troll
        d3 = 12;
        //Integer a3 = (Integer) d4; error...

        //int to Double
        Double d2 = (double) int1.intValue(); //literal unbox -> cast
        d2 = (double) int1; //first unboxes then casts into double okay...
        d2 = (double) int2;
        //Double d3 = (Double) int1; error cannot cast Integer to Double

        //double/Double to int
        //on test just do .doubleValue()... .intValue();
        int2 = (int) d1;
        int2 = (int) d2.doubleValue();

        //double/Double to Integer
        int1 = (int) d1;
        int1 = (int) d2.doubleValue();

        //method overloading
        //f1(int2, int2);
        //f1(int1, int2);*/
        //f1(int1);
    }
}
