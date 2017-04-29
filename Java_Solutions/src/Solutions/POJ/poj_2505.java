package Solutions.POJ;

import java.io.IOException;
import java.util.Scanner;

/**
 * Created by chuck on 4/28/2017.
 */
public class poj_2505 {
    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(new FileReader("input.in"));
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            double m = in.nextDouble();
            while (m > 18) {
                m = m/18;
            }
            if (m > 9) {
                System.out.println("Ollie wins.");
            } else {
                System.out.println("Stan wins.");
            }
        }
        in.close();
        System.exit(0);
    }
}
