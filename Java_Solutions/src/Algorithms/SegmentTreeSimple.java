package Algorithms;
import java.util.*;
import java.io.*;

public class SegmentTreeSimple {
    /*
    Segment Tree rules
    1. Leaf Nodes are all A[6:6] which represent the array's value
    2. Root Node is Tree[1] = A[0 - N-1] sum
    3. Internal Nodes are the nodes with values A[i:j]
    4. You cannot add another A[7] to the array
    5. Only build O(N), update O(logN), and find range O(logN)
    6. Used to find the sum between certain ranges or find the minimum value within certain ranges (range minimum query)
    7. Also, it's inclusive 0, mid = 0 1 2 3 ... mid;
    8. To query on a given range, check 3 conditions.
    Range represented by a node is completely inside the given range, return range
    Range represented by a node is completely outside the given range, return 0
    Range represented by a node is partially inside and partially outside the given range, continue searching...
    9. TreeNode = 1 indexed...
     */
    static int A[];
    static int segTree[];

    public static int build(int start, int end, int node) {
        if (start == end) {
            segTree[node] = A[start];
            return segTree[node];
        }
        int mid = (start + end) / 2;
        segTree[node] = build(start, mid, 2 * node) + build(mid + 1, end, 2 * node + 1);
        return segTree[node];
    }

    public static void update(int start, int end, int node, int val, int id) {
        if (start == end) {
            A[id] = val;
            segTree[node] = A[id];
            return;
        }
        int mid = (start + end) / 2;
        if (start <= id && id <= mid) {
            update(start, mid, 2 * node, val, id);
        } else {
            update(mid + 1, end, 2 * node + 1, val, id);
        }
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }

    public static int query(int start, int end, int l, int r, int node) {
        if (l <= start && end <= r) {
            return segTree[node];
        }
        if (r < start || end < l) {
            return 0;
        }
        int mid = (start + end)/2;
        return query(start, mid, l, r, 2 * node) + query(mid + 1, end, l, r, 2 * node + 1);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken());
        int Q = Integer.parseInt(st.nextToken());
        A = new int[N];
        st = new StringTokenizer(in.readLine());
        int h = (int) Math.ceil(Math.log(N)/Math.log(2));
        //int x = 2 * (int) Math.pow(2, h) should be  2 * (int) Math.pow(2,h) - 1;
        segTree = new int[2 * (int) Math.pow(2, h)];
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        build(0, N-1, 1);
        /*update(0, N-1, 1, 100, 1);
        for (int i = 0; i < segTree.length; i++) {
            System.out.println(segTree[i]);
        }*/
        for (int i = 0; i < Q; i++) {
            st = new StringTokenizer(in.readLine());
            String cmd = st.nextToken();
            int x = Integer.parseInt(st.nextToken()); //start A[3]
            int y = Integer.parseInt(st.nextToken()); //end val,
            if (cmd.equals("u")) {
                update(0, N - 1, 1, y, x - 1); //remember it array is 0 indexed but segtree is not
            } else {
                out.println(query(0, N - 1, x - 1, y - 1, 1));
            }
        }
    }
}
