package Solutions.USACO;

import java.io.*;
import java.util.*;

public class bovinegenomics {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("cownomics.in"));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("cownomics.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        long R[] = new long[m];
        for (int i = 0; i < m; i++) {
            R[i] = (long) (Math.random() * 1000000000);
        }
        long hash1[] = new long[n];
        long hash2[] = new long[n];
        String spot[] = new String[n];
        String plain[] = new String[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            spot[i] = st.nextToken();
        }
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            plain[i] = st.nextToken();
        }

        int j = 0, i = 0, dups = 1, best = m;
        while (j < m) { //invariant that when j > 0 then there can be no greater value
            if (dups == 0) {
                best = Math.min(best, j - i);
            }
            if (dups > 0) {
                dups = 0;
                Set<Long> set = new HashSet<Long>();
                for (int k = 0; k < n; k++) {
                    hash1[k] += R[j] * (spot[k].charAt(j));
                    set.add(hash1[k]);
                }
                for (int k = 0; k < n; k++) {
                    hash2[k] += R[j] * (plain[k].charAt(j));
                    if (set.contains(hash2[k])) {
                        dups++;
                    }
                }
                j++;
            } else {
                dups = 0;
                Set<Long> set = new HashSet<Long>();
                for (int k = 0; k < n; k++) {
                    hash1[k] -= R[i] * (spot[k].charAt(i));
                    set.add(hash1[k]);
                }
                for (int k = 0; k < n; k++) {
                    hash2[k] -= R[i] * (plain[k].charAt(i));
                    if (set.contains(hash2[k])) {
                        dups++;
                    }
                }
                i++;
            }
        }
        out.println(best);
        out.close();
        System.exit(0);
    }
}
