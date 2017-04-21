package Solutions.Codeforces;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Created by chuck on 4/19/2017.
 */
public class codeforces_408A {
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken()) - 1;
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        int mindistance = 100000;
        for (int i = 0; i < n; i++) {
            int cost = Integer.parseInt(st.nextToken());
            int d = Math.abs(i - m) * 10;
            if (d >= mindistance || cost == 0) {
                continue;
            }
            if (cost <= k) {
                mindistance = d;
            }
        }
        System.out.println(mindistance);
        out.close();
        System.exit(0);
    }
}
