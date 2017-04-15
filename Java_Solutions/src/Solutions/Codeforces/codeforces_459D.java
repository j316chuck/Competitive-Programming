package Solutions.Codeforces;

import java.util.*;
import java.io.*;

public class codeforces_459D {
    static int n;
    static int A[]; //0 - n-1
    static int bit[]; //1 - n;
    static void update(int index, int val) {
        while (index <= n) {
            bit[index] += val;
            index += (index & -index);
        }
    }
    static long sum(int index) {
        long total = 0;
        while (index > 0) {
            total += (long) bit[index];
            index -= (index & -index);
        }
        return total;
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        n = Integer.parseInt(st.nextToken());
        A = new int[n];
        bit = new int[n + 1];
        st = new StringTokenizer(in.readLine());
        HashMap<Integer, Integer> mp = new HashMap<Integer, Integer>();
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
            if (mp.containsKey(A[i])) {
                mp.put(A[i], mp.get(A[i])+1);
            } else {
                mp.put(A[i], 1);
            }
            update(mp.get(A[i]), 1);
        }
        /*for (int i = 1; i <= n; i++) {
            out.print(bit[i] + " ");
        }*/
        HashMap<Integer, Integer> lt = new HashMap<Integer, Integer>();
        long result = 0;
        for (int i = 0; i < n; i++) {
            update(mp.get(A[i]), -1);
            mp.put(A[i], mp.get(A[i]) - 1);
            if (lt.containsKey(A[i])) {
                lt.put(A[i], lt.get(A[i]) + 1);
            } else {
                lt.put(A[i], 1);
            }
            result += sum(lt.get(A[i]) - 1);
        }
        out.println(result);
        out.close();
        System.exit(0);
    }


    /*static class Pair implements Comparable<Pair> {
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
    }*/
}



