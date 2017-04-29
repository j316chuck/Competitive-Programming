package Solutions.POJ;

import java.io.IOException;
import java.util.Scanner;

public class poj_3480 {

    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(new FileReader("input.in"));
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            int xor = 0; boolean allones = true;
            for (int i = 0; i < n; i++) {
                int a = in.nextInt();
                xor ^= a;
                allones &= (a == 1);
            }
            if (allones) {
                if (n % 2 == 0) {
                    System.out.println("John");
                } else {
                    System.out.println("Brother");
                }
            } else {
                if (xor != 0) {
                    System.out.println("John");
                } else {
                    System.out.println("Brother");
                }
            }
        }
        System.exit(0);
    }

}
