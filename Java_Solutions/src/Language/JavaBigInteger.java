package Language;
import java.math.*;
import java.util.*;
import java.io.*;

public class JavaBigInteger {
    public static void main(String[] args) {
        BigInteger a = new BigInteger("123213425");
        System.out.println(a);
        a = a.add(a);
        System.out.println(a);
        System.out.println(a.bitCount());
        BigInteger b = new BigInteger("1111111");
        b = b.subtract(a);
        System.out.println(b);
        //compareTo(), gc(), hashCode(), intValue(), doubleValue();
        //mod, multiply, negate(), nextProbablePrime(), not(), pow(), divide()
        //remainder(), subtract(), toString();
    }
}
