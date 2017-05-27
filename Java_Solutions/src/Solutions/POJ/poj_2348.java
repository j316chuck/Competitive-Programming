package Solutions.POJ;

import java.io.IOException;
import java.util.Scanner;

public class poj_2348 {

    static long gcd(long a, long b) {
        if (a == 0 || b == 0) {
            return 1;
        }
        return 1 + gcd(b, a - b);
    }

    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(new FileReader("input.in"));
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            long a = in.nextLong();
            long b = in.nextLong();
            if (a == 0 && b == 0) {
                in.close();
                System.exit(0);
            }
            int xor = 0;
            while (true) {
                if (a < b) {
                    long temp = a;
                    a = b;
                    b = temp;
                }
                if (a % b == 0 || a > 2 * b)
                    break;
                a -= b;
                xor ^= 1;
            }

            if (xor == 0) {
                System.out.println("Stan wins");
            } else {
                System.out.println("Ollie wins");
            }
        }
        in.close();
        System.exit(0);
    }
}
