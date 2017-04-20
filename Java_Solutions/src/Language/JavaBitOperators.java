package Language;

/**
 * Created by chuck on 4/10/2017.
 */
public class JavaBitOperators {
    public static void main(String[] args) {
        int a = 31 & -31; // 0000110 11111010 -> 10 2
        int b = 31 & 30; //n & (n - 1) = n - (n & -n)
        System.out.println(a + " " + b);
        System.out.println((1|6) ^ (3|5));
        System.out.println(1<<5);
    }
}
