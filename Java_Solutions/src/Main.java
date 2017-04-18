import java.util.*;
import java.io.*;

public class Main {

    static String str;
    static Node tree[];
    static int m;
    static class Node {
        int pleft, pright, ptotal;
        Node(int pleft, int pright, int ptotal) {
            this.pleft = pleft;
            this.pright = pright;
            this.ptotal = ptotal;
        }
        /*@Override
        public int compareTo(Node a) {
            return
        }*/
        public String toString() {
            return "(" + pleft + "," + ptotal + "," + pright + ")";
        }
    }

    static Node combine(Node left, Node right) {
        Node result = new Node(0, 0, 0);
        int additional = Math.min(left.pleft, right.pright);
        result.ptotal += left.ptotal + right.ptotal + additional * 2;
        result.pright += left.pright + right.pright - additional;
        result.pleft += left.pleft + right.pleft - additional;
        return result;
    }

    static Node build(int node, int start, int end) {
        if (start == end) {
            if (str.charAt(start) == '(') {
                tree[node] = new Node(1, 0, 0);
            } else {
                tree[node] = new Node(0, 1, 0);
            }
            return tree[node];
        }
        int mid = (start + end) / 2;
        tree[node] = combine(build(2 * node, start, mid), build(2 * node + 1, mid + 1, end));
        return tree[node];
    }

    static Node query(int node, int start, int end, int l, int r) {
        if (l <= start && end <= r) {
            return tree[node];
        }
        if (r < start || l > end) {
            return new Node(0, 0, 0);
        }
        int mid = (start + end) / 2;
        return combine(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        str = st.nextToken();
        m = str.length();
        tree = new Node[4 * m];
        build(1, 0, m - 1);

        st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            Node res = query(1, 0, m - 1, l - 1, r - 1);
            out.println(res.ptotal);
        }
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


