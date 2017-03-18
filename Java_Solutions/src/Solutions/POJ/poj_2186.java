package Solutions.POJ;

import java.io.*;
import java.util.*;

public class poj_2186 {

    private static int find(int x, int parent[]) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }

    private static int bfs(int start, List<Integer>[] graph, int n) {
        Queue<Integer> queue = new LinkedList<Integer>();
        int total = 0;
        boolean[] visited = new boolean[n+1];
        queue.add(start);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            visited[u] = true;
            total++;
            for (int v : graph[u]) {
                if (!visited[v]) {
                    queue.add(v);
                }
            }
        }
        return total;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<Integer>[] graph = (List<Integer>[]) new List[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<Integer>();
        }

        int parent[] = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            graph[u].add(v);
            int pu = find(u, parent);
            int pv = find(v, parent);
            if (pu != pv) {
                parent[pu] = parent[pv];
            }
        }

        for (int i = 1; i < n; i++) {
            if (find(i, parent) != find(i+1, parent)) {
                out.println(0);
                System.exit(0);
            }
        }
        out.println(bfs(parent[1], graph, n));
        out.close();
        System.exit(0);
    }
}
