package Solutions.POJ;

import java.io.IOException;
import java.util.Scanner;

/**
 * Created by chuck on 4/26/2017.
 */
public class poj_2234 {
    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(new FileReader("input.in"));
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            String strs[] = in.nextLine().split("\\s+");
            int nim = 0;
            int number = Integer.parseInt(strs[0]);
            for (int i = 1; i < strs.length; i++) {
                nim ^= Integer.parseInt(strs[i]);
            }
            System.out.println(nim != 0 ? "YES" : "NO");
        }
    }
}
