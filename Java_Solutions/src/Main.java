import java.util.*;
import java.io.*;

public class Main {

    static int graph[][];
    static boolean visited[];
    static int n, m;
    static PrintWriter out;
    static void dfs(int u) {
        visited[u] = true;
        for (int i = 0; i <= n; i++) {
            if (graph[u][i] != 0) {
                graph[u][i] = 0;
                graph[i][u] = 0;
                if (u != 0 && i != 0) {
                    out.println(u + "  " + i);
                }
                dfs(i);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int t = Integer.parseInt(st.nextToken());

        while(t-- > 0) {
            st = new StringTokenizer(in.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            graph = new int[n + 1][n + 1];
            visited = new boolean[n + 1];
            for (int i = 0; i < m; i++) { //read in input both then graph construct odd then link to 0 after visited...
                st = new StringTokenizer(in.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                graph[u][v] = 1;
                graph[v][u] = 1;
            }
            int ans = n;
            for(int i = 1; i <= n; i++) {
                int degree = 0;
                for (int j = 1; j <= n; j++) {
                    if(graph[i][j] != 0) {
                        degree++;
                    }
                }
                if(degree % 2 == 1) {
                    ans--;
                    graph[0][i] = 1;
                    graph[i][0] = 1;
                }
            }
            out.println(ans);
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    dfs(i);
                }
            }
        }
        out.close();
        System.exit(0);
    }
}