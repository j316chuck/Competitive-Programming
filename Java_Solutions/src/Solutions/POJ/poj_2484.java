package Solutions.POJ;

import java.io.IOException;
import java.util.Scanner;

public class poj_2484 {
    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(new FileReader("input.in"));
        Scanner in = new Scanner(System.in);
        while (true) {
            int a = in.nextInt();
            if (a == 0) {
                break;
            }
            System.out.println(a > 2 ? "Bob" : "Alice");
        }
        System.exit(0);
    }
}
