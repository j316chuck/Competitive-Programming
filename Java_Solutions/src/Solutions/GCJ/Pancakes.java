package Solutions.GCJ;

/**
 * Created by chuck on 4/8/2017.
 * Problem: Pancakes
 * Origin: GCJ Qualification 2017
 */

import java.util.*;
import java.io.*;

public class Pancakes {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int t = Integer.parseInt(st.nextToken());
        for (int testcase = 1; testcase <= t; testcase++) {
            int flips = 0;
            st = new StringTokenizer(in.readLine());
            String s = st.nextToken();
            char[] strs = s.toCharArray();
            int k = Integer.parseInt(st.nextToken());
            int i;
            for (i = 0; i <= strs.length - k; i++) {
                if (strs[i] == '-') {
                    flips++;
                    for (int j = i; j < i + k; j++) {
                        if (strs[j] == '-') {
                            strs[j] = '+';
                        } else {
                            strs[j] = '-';
                        }
                    }
                }
            }
            String result = (new Integer(flips).toString());
            while (i < strs.length) {
                if (strs[i] == '-') {
                    result = "IMPOSSIBLE";
                    break;
                }
                i++;
            }
            out.printf("Case #%d: %s\n", testcase, result);
        }

        out.close();
        System.exit(0);
    }
}


