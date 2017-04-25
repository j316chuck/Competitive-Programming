package Solutions.Codeforces;

import java.util.*;
import java.io.*;
public class codeforces_410B {
    static int editDistance(String first, String cmp) {
        String temp;
        for (int i = 0; i < cmp.length(); i++) {
            temp = first.substring(i) +  first.substring(0, i);
            if (temp.equals(cmp)) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.readLine();
            if (arr[i].length() != arr[0].length()) {
                out.println(-1);
                out.close();
                System.exit(0);
            }
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int moves = 0;
            for (int j = 0; j < n; j++) {
                int d = editDistance(arr[j], arr[i]);
                if (d == -1) {
                    out.println(-1);
                    out.close();
                    System.exit(0);
                } else {
                    moves += d;
                }
            }
            min = Math.min(min, moves);
        }
        out.println(min);
        out.close();
        System.exit(0);
    }

}
