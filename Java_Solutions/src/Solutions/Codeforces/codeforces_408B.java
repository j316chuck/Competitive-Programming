package Solutions.Codeforces;

import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

/**
 * Created by chuck on 4/19/2017.
 */
public class codeforces_408B {
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        HashSet<Integer> holes = new HashSet<Integer>();
        for (int i = 0; i < m; i++) {
            holes.add(Integer.parseInt(st.nextToken()));
        }
        boolean fellintohole = false;
        int position = 1;
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            if (holes.contains(position)) {
                fellintohole = true;
                continue;
            }
            if (u == position) {
                position = v;
            } else if (v == position) {
                position = u;
            }
        }
        out.println(position);
        out.close();
        System.exit(0);
    }
}
