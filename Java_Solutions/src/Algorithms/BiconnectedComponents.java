package Algorithms;
import java.util.*;

public class BiconnectedComponents {

   List<Integer>[] graph;
   boolean[] visited;
   Stack<Integer> stack;
   int time;
   int[] tin;
   int[] lowlink;
   List<List<Integer>> components;
   List<Integer> cutPoints;
   List<String> bridges;

   public List<List<Integer>> biconnectedComponents(List<Integer>[] graph) {
       this.graph = graph;
       int n = graph.length;
       visited = new boolean[n];
       time = 0;
       stack = new Stack<Integer>();
       tin = new int[n];
       lowlink = new int[n];
       components = new ArrayList<List<Integer>>();
       cutPoints = new ArrayList<Integer>();
       bridges = new ArrayList<String>();
       for (int i = 0; i < n; i++) {
           if (!visited[i]) {
               dfs(i, -1);
           }
       }
       return components;
   }

   public void dfs(int u, int p) {
        visited[u] = true;
        lowlink[u] = tin[u] = time++;
        stack.add(u);
        int children = 0;
        boolean cutPoint = false;
        for (int v: graph[u]) {
            if (v == p) continue; //directed graph then same idea...
            if (visited[v]) {
                lowlink[u] = Math.min(lowlink[u], tin[v]);
            } else {
                dfs(v, u);
                lowlink[u] = Math.min(lowlink[u], tin[v]);
                cutPoint = cutPoint | lowlink[v] >= tin[u];
                if (lowlink[v] > tin[u]) {
                    bridges.add("(" + u + "," + v + ")");
                }
                ++children;
            }
        }
        if (p == -1)
            cutPoint = children >= 2;
        if (cutPoint)
            cutPoints.add(u);
        if (lowlink[u] == tin[u]) {
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
        int n = 3;
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        int[][] edges = {{0, 1}, {1, 2}};
        for (int[] edge : edges) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        BiconnectedComponents bc = new BiconnectedComponents();
        List<List<Integer>> components = bc.biconnectedComponents(graph);

        System.out.println("biconnected components:" + components);
        System.out.println("cutPoints: " + bc.cutPoints);
        System.out.println("bridges:" + bc.bridges);
    }
}