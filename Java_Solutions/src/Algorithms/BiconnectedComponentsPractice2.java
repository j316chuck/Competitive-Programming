package Algorithms;
import java.util.*;
import java.io.*;

public class BiconnectedComponentsPractice2 {

    static int[] low;
    static int[] disc;
    static int time;
    static Stack<Integer> stack;
    static List<List<Integer>> components;
    static boolean[] visited;
    static List<String> bridges;
    static List<Integer> cutpoints;

    public List<List<Integer>> biconnectedComponents(List<Integer>[] graph) {
        int n = graph.length;
        time = 0;
        stack = new Stack<Integer>();
        disc = new int[n];
        low = new int[n];
        visited = new boolean[n];
        bridges = new ArrayList<String>();
        cutpoints = new ArrayList<Integer>();
        components = new ArrayList<List<Integer>>();
        for (int i = 0; i < graph.length; i++) {
            if (!visited[i]) {
                dfs(i, -1, graph);
            }
        }
        return components;
    }

    public static void dfs(int u, int p, List<Integer>[] graph) {
        low[u] = disc[u] = time++;
        stack.add(u);
        boolean articulation = false;
        visited[u] = true;
        int child = 0;
        for (int v : graph[u]) {
            if (!visited[v]) {
                dfs(v, u, graph);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] > disc[u]) {
                    bridges.add(u + "  " + v);
                }
                articulation = articulation || low[v] >= disc[u];
                child++;
            } else if (v != p) {
                low[u] = Math.min(low[u], disc[v]);
            }
        }
        if (articulation || (child >= 2 && p == -1)) {
            cutpoints.add(u);
        }
        if (low[u] == disc[u]) {
            List<Integer> component = new ArrayList<Integer>();
            while (true) {
                int x = stack.pop();
                component.add(x);
                if (x == u) {
                    break;
                }
            }
            components.add(component);
        }
    }

    // Usage example
    public static void main(String[] args) {
        int n = 7;
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        int[][] edges = {{0, 1}, {1, 2}, {2, 3}, {1, 4}, {3,4}, {4, 5}, {4, 6}};
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        BiconnectedComponentsPractice2 bc = new BiconnectedComponentsPractice2();
        List<List<Integer>> components = bc.biconnectedComponents(graph);

        System.out.println("biconnected components:" + components);
        System.out.println("cutPoints: " + bc.cutpoints);
        System.out.println("bridges:" + bc.bridges);
    }
}
