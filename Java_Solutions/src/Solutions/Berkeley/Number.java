package Solutions.Berkeley;

import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

/**
 * Created by chuck on 10/13/2017.
 */
public class Number {


    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("input.in")); //probably need to comment this
        //Scanner in = new Scanner(System.in); probably need to uncomment this

        while (in.hasNext()) {
            int n = in.nextInt();
            String result = solve(n);
            System.out.println("The smallest good numeral of length " + n + " is " + result);
        }
        in.close();
        System.exit(0);
    }

    private static String solve(int n) {
        boolean valid[][] = new boolean[n + 5][4]; //boolean array storing the valid positions of index, number 1 - 3
        valid[1][1] = true;
        for (int i = 2; i <= n; i++) {

        }

        String result = "";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 3; j++) {
                if (valid[i][j]) {
                    result += i;
                }
            }
        }
        return result;
    }
}
