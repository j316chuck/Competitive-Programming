package Solutions.Codeforces;

import java.util.*;
import java.io.*;

public class codeforces_61E {
    static int n;
    static Pair A[], B[];//0 - n-1 indexed
    static int bit[];
    static void update(int index, int val) {
        while (index <= n) {
            bit[index] += val;
            index += (index & -index);
        }
    }

    static long sum(int index) {
        long result = 0;
        while (index > 0) {
            result += bit[index];
            index -= (index & -index);
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        A = new Pair[n];
        B = new Pair[n];
        bit = new int[n+1];
        for (int i = 0; i < n; i++) {
            A[i] = B[i] = new Pair(Integer.parseInt(st.nextToken()), i);
        }
        Arrays.sort(B);
        for (int i = 0; i < n; i++) {
            B[i].second = i + 1;
        }
        long result = 0;
        for (int i = 1; i <= n; i++) {
            long q = sum(A[i - 1].second);
            result += (i - q - 1) * (A[i - 1].second - 1 - q);
            update(A[i - 1].second, 1);
        }
        out.println(result);
        out.close();
        System.exit(0);
    }


    static class Pair implements Comparable<Pair> {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair p) {
            if (first != p.first)
                return Integer.compare(first, p.first);
            return Integer.compare(second, p.second);
        }

        public int hashCode() {
            return first * 1_000_003 + second;
        }

        public boolean equals(Object o) {
            if (o == null || !(o instanceof Pair))
                return false;
            Pair p = (Pair) o;
            return first == p.first && second == p.second;
        }
    }
}


