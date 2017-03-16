package Solutions.POJ;

import java.util.*;
import java.io.*;

public class poj_3177A {
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

    /*static List<Integer>[] graph;
    static List<List<Integer>> components;
    static int time;
    static int[] low;
    static boolean[] visited;
    static int[] tin;
    static int[] parent;
    static Stack<Integer> stack; */


    /*private static void findBiconnectedComponents() {
        components = new ArrayList<List<Integer>>();
        time = 0;
        int n = graph.length;
        low = new int[n];
        visited = new boolean[n];
        tin = new int[n];
        parent = new int[n];
        stack = new Stack<Integer>();
        Arrays.fill(parent, -1);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

    static void dfs(int u) {
        low[u] = tin[u] = time++;
        visited[u] = true;
        int child = 0;
        stack.add(u);

        for (int v : graph[u]) {
            if (v == parent[u]) continue;
            if (visited[v]) {
                low[u] = Math.min(low[u], tin[v]);
            } else {
                parent[v] = u;
                dfs(v);
                child++;
                low[u] = Math.min(low[u], low[v]);
                if ((child >= 2 && parent[u] == -1) || (low[v] >= tin[u]) && parent[u] != -1){
                    insertComponent(u);
                }
            }
        }
        if (low[u] == tin[u]) {
            insertComponent(u);
        }
    }

    static void insertComponent(int u) {
        List<Integer> component = new ArrayList<Integer>();
        while(!stack.isEmpty()) {
            int x = stack.pop();
            component.add(x);
            if (x == u) {
                break;
            }
        }
        if (component.size() != 0) {
            components.add(component);
        }
    }*/
    static List<Integer>[] graph;
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
        for (int v : graph[u]) {
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

    private static void dfs2(int u, int bcount) {
        bcc[u] = bcount;
        for (int v : graph[u]) {
            if (bcc[v] == -1) {
                dfs2(v, bcount);
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

        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            graph[a].add(b);
            graph[b].add(a);
        }
        /*for (List<Integer> u : graph) {
            System.out.println(u);
        }*/
        findBiconnectedComponents();
        for (Edge e: bridges) {
            int u = e.u;
            int v = e.v;
            int vi = graph[u].indexOf(v);
            graph[u].remove(vi);
            int ui = graph[v].indexOf(u);
            graph[v].remove(ui);
        }

        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (bcc[i] == -1) {
                dfs2(i, ++cc);
            }
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
