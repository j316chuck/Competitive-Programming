package Solutions.Codeforces;
import java.util.*;
import java.io.*;

public class codeforces_207A {
    // three conditions in this segment tree
    // parent tree should be 1 indexed 1, N instead of 0, N-1...
    // node, start, end, l, r, val
    // change case start == end && start != val array[start] = val; change case visited[node] = true;
    // break case if visited[node] continue;
    // continue case  if (r < start || l > end) break
    // normal case query() query();
    // parent tree = visited[] then continue;

    static int A[];
    static int tree[];

    static void update(int node, int start, int end, int l, int r, int val) {
        if (tree[node] != 0) {
            return;
        }
        if (r < start || l > end) {
            return;
        }
        if (start == end) {
            if (start != val) {
                A[start] = val;
                tree[node] = 1;
            }
            return;
        }

        int mid = (start + end)/2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        if (tree[2 * node] == 1 && tree[2 * node + 1] == 1) {
            tree[node] = 1;
        }
        return;
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        A = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            A[i] = i;
        }
        tree = new int[4 * (n + 1)];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int l = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            update(1, 1, n, l, r, v);
        }
        for (int i = 1; i < A.length; i++) {
            if (A[i] != i) {
                out.print(A[i] + " ");
            } else {
                out.print(0 + " ");
            }
        }
        out.println();
        out.close();
        System.exit(0);
    }
}


