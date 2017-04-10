package Algorithms;
import java.util.*;
import java.io.*;

public class SegmentTreePractice {
    static int A[]; //n
    static int tree[]; // 4 * n

    static void build (int node, int start, int end) {
        if (start == end) {
            tree[node] = A[start];
            return;
        }
        int mid = (start + end)/2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = Math.min(tree[2 * node], tree[2 * node + 1]);
    }
    static void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            A[idx] = val;
            tree[node] = val;
            return;
        }
        int mid = (start + end)/2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = Math.min(tree[2 * node], tree[2 * node + 1]);
    }

    static int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return Integer.MAX_VALUE;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end)/2;
        return Math.min(query(2 * node, start, mid, l, r),
                query(2 * node + 1, mid + 1, end, l, r));
    }

    public static void main(String[] args) throws IOException{
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        A = new int[N];
        st = new StringTokenizer(in.readLine());
        tree = new int[4 * N];
        Arrays.fill(tree, Integer.MAX_VALUE);
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        build(1, 0, N-1);
        /*for (int i = 0; i < tree.length; i++) {
            out.println(tree[i]);
        }*/
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(in.readLine());
            String s = st.nextToken();
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if (s.equals("q")) {
                out.println(query(1, 0, N-1, x - 1, y - 1));
            } else {
                update(1, 0, N-1, x - 1, y);
            }
        }
        out.close();
        System.exit(0);
    }
}
