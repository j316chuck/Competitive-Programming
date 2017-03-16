package Solutions.POJ;

import java.util.*;
import java.io.*;

public class poj_3177B {
    //public class Main {
    private static class Edge {
        public int u, v;
        public Edge(int u, int v) {
            this.u = u;
            this.v = v;
        }

        @Override
        public boolean equals(Object o) {
            if (o == this) return true;
            if (o == null) return false;
            if (o.getClass() != getClass()) return false;
            Edge e = (Edge) o;
            return e.u == u && e.v == v;
        }

        @Override
        public String toString() {
            return u + "->" + v;
        }
    }

    static int[][] graph;
    static int[] low;
    static boolean[] visited;
    static int[] tin;
    static int time;
    static int[] bcc;
    static int[] indegree;
    static List<Edge> bridges;

    private static void findBiconnectedComponents() {
        int n = graph.length;
        low = new int[n];
        tin = new int[n];
        time = 0;
        visited = new boolean[n];
        bcc = new int[n];
        indegree = new int[n];
        bridges = new ArrayList<Edge>();
        Arrays.fill(low, 1<<30);
        Arrays.fill(tin, -1);
        Arrays.fill(bcc, -1);
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs(i, -1);
        }
    }

    private static void dfs(int u, int p) {
        visited[u] = true;
        low[u] = tin[u] = time++;
        for (int i = 0; i < graph[u].length; i++) {
            if (graph[u][i] != 0) {
                int v = i;
                if (v == p) {
                    continue;
                } if (visited[v]) {
                    low[u] = Math.min(low[u], tin[v]);
                } else {
                    dfs(v, u);
                    low[u] = Math.min(low[u], low[v]);
                    if (low[v] > tin[u]) {
                        bridges.add(new Edge(u, v));
                    }
                }
            }
        }
    }

    private static void dfs2(int u, int bcount) {
        bcc[u] = bcount;
        for (int v = 0; v < graph.length; v++) {
            if (graph[u][v] != 0) {
                if (bcc[v] == -1) {
                    dfs2(v, bcount);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        graph = new int[n][n];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        /*for (List<Integer> u : graph) {
            System.out.println(u);
        }*/
        findBiconnectedComponents();

        for (Edge e: bridges) {
            int u = e.u;
            int v = e.v;
            graph[u][v] = 0;
            graph[v][u] = 0;
        }

        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (bcc[i] == -1) {
                dfs2(i, cc++);
            }
            //System.out.println(bcc[i]);
        }

        for (Edge e: bridges) {
            int u = e.u;
            int v = e.v;
            indegree[bcc[u]]++;
            indegree[bcc[v]]++;
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1)
                total++;
        }
        out.println((total+1)/2);
        out.close();
        System.exit(0);
    }
}
