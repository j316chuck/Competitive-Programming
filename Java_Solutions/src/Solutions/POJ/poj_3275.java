package Solutions.POJ;
import java.io.*;
import java.util.*;

public class poj_3275 {
    private static boolean[] visited;
    private static List<Integer>[] graph;

    private static int dfs(int u) {
        visited[u] = true;
        int ret = 0;
        for (int v : graph[u]) {
            if (!visited[v]) {
                ret += dfs(v) + 1;
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        graph = new List[n + 1];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            graph[a].add(b);
        }
        int ret = 0;
        visited = new boolean[n + 1];
        for (int i = 0; i < n; i++) {
            Arrays.fill(visited, false);
            ret += dfs(i);
        }
        System.out.println((n * (n - 1) / 2) - ret);
        System.exit(0);
    }
}
