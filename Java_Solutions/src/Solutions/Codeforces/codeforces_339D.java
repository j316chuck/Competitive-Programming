package Solutions.Codeforces;
import java.util.*;
import java.io.*;

public class codeforces_339D {
    static class Node {
        int value;
        boolean or;
        public Node(int v, boolean x) {
            value = v;
            or = x;
        }
    }
    static int A[];
    static Node tree[];

    static void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = new Node(A[start], false);
            return;
        }
        int mid = (start + end)/2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        if (tree[2 * node].or) {
            tree[node] = new Node(tree[2 * node].value ^ tree[2 * node + 1].value, false);
        } else {
            tree[node] = new Node(tree[2 * node].value | tree[2 * node + 1].value, true);
        }
        return;
    }

    static void update(int node, int start, int end, int val, int idx) {
        if (start == end) {
            A[idx] = val;
            tree[node].value = val;
            return;
        }
        int mid = (start + end)/2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, val, idx);
        } else {
            update(2 * node + 1, mid+1, end, val, idx);
        }
        if (tree[node].or) {
            tree[node].value = tree[2 * node].value | tree[2 * node + 1].value;
        } else {
            tree[node].value = tree[2 * node].value ^ tree[2 * node + 1].value;
        }
    }

    public static void main(String[] args) throws IOException {
        /*
        1. read in input
        2. build tree with nodes true/false dictating or
        3. update tree with old values... return true/false;
        */
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        n = 1 << n;
        A = new int[n]; //0 indexed array, 1 indexed tree.
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        tree = new Node[4 * (n + 1)];
        build(1, 0, n-1);
        //out.println(tree[1].value);

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int p = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            update(1, 0, n-1, b, p-1);
            out.println(tree[1].value);
        }
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



