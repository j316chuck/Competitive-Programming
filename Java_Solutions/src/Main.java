import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("input.in"));
        //Scanner in = new Scanner(System.in);
        char[] s1 = in.nextLine().toCharArray();
        char[] s2 = in.nextLine().toCharArray();
        Arrays.sort(s1);
        Arrays.sort(s2);
        int n = s1.length;

        int count = 0;
        String result = "";
        while (count < n) {
            result += s1[count/2];
            result += s2[n - 1 - count/2];
            count += 2;
        }
        if (result.length() > n) {
            System.out.println(result.substring(0, result.length() - 1));
        } else {
            System.out.println(result);
        }

        in.close();
        System.exit(0);
    }
}

