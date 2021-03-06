package Solutions.Codeforces;

import java.util.*;
import java.io.*;
public class codeforces_410A {
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        //StringTokenizer st = new StringTokenizer(in.readLine());
        String s = in.readLine();
        int n = s.length();
        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) != s.charAt(n - i - 1)) {
                counter++;
            }
        }
        if (counter == 2 || (counter == 0 && n % 2 == 1)) {
            out.println("YES");
        } else {
            out.println("NO");
        }
        out.close();
        System.exit(0);
    }
}
