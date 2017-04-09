import java.io.*;
import java.util.*;

public class temp2 {
    static class Node implements Comparable<Node> {
        long root;
        public Node(long r) {
            root = r;
        }
        @Override
        public int compareTo(Node a) {
            if (this.root > a.root) {
                return 1;
            } else if (this.root == a.root) {
                return 0;
            } else {
                return -1;
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int t = Integer.parseInt(st.nextToken());
        for (int testcase = 1; testcase <= t; testcase++) {
            st = new StringTokenizer(in.readLine());
            long n = Long.parseLong(st.nextToken());
            long k = Long.parseLong(st.nextToken());
            PriorityQueue<Node> pq = new PriorityQueue<Node>();
            pq.add(new Node(n));
            while (!pq.isEmpty()) {
                long top = pq.poll().root;
                if (k == 0) {
                    out.printf("Case #%d: %d %d\n", testcase, top/2, (top-1)/2);
                    out.close();
                    System.exit(0);
                }
                pq.add(new Node((top-1)/2));
                pq.add(new Node(top/2));
                k--;
            }
        }
        out.close();
        System.exit(0);
    }
}
