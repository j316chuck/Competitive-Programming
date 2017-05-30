package Solutions.POJ;
import java.util.*;
import java.io.*;

public class poj_1944 {
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int graph[][] = new int[m][2];
        int nodes[] = new int[2 * n + 2];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[i][0] = a;
            graph[i][1] = b;
        }
        int u, v;
        int rst = n;
        for (int i = 0; i < n; i++) {
            Arrays.fill(nodes, 0);
            for (int j = 0; j < m; j++) {
                u = graph[j][0];
                v = graph[j][1];
                if (u <= i) {
                    u += n;
                } if (v <= i) {
                    v += n;
                }
                if (u > v) {
                    int temp = v;
                    v = u;
                    u = temp;
                }
                nodes[u]++;
                nodes[v]--;
            }
            int current = 0;
            int ret = 0;
            for (int j = 1; j <= n; j++) {
                current += nodes[i+j];
                if (current > 0) {
                    ret++;
                }
            }
            rst = Math.min(rst, ret);
        }
        out.println(rst);
        out.close();
        System.exit(0);
    }
}
