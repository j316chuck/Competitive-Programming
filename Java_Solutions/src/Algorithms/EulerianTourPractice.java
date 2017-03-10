package Algorithms;
import java.util.*;

public class EulerianTourPractice {

    private static List<Integer> eulerCycleDirected(List<Integer>[] graph, int u) {
        int n = graph.length;
        int[] curEdge = new int[n];
        List<Integer> res = new ArrayList<Integer>();
        dfs(curEdge, u, graph, res);
        Collections.reverse(res);
        return res;
    }

    private static void dfs(int[] curEdge, int u, List<Integer>[] graph, List<Integer> res) {
        while (curEdge[u] < graph[u].size()) {
            int v = graph[u].get(curEdge[u]);
            curEdge[u]++;
            dfs(curEdge, v, graph, res);
        }
        res.add(u);
    }
    private static List<Integer> eulerCycleUndirected(List<Integer>[] graph, int u) {
        int n = graph.length;
        int[] curEdge = new int[n];
        List<Integer> res = new ArrayList<Integer>();
        Stack<Integer> stack = new Stack<Integer>();
        Set<Long> usedEdges = new HashSet<Long>();
        stack.add(u);
        while (!stack.isEmpty()) {
            u = stack.pop();
            while (curEdge[u] < graph[u].size()) {
                int v = graph[u].get(curEdge[u]);
                curEdge[u]++;
                long hashsum = (((long) Math.min(u, v) << 32) + Math.max(u, v));
                if (usedEdges.add(hashsum)) {
                    stack.push(u);
                    u = v;
                }
            }
            res.add(u);
        }
        Collections.reverse(res);
        return res;
    }

    public static void main(String[] args) {
        int n = 5;
        List<Integer>[] g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        g[0].add(1);
        g[1].add(2);
        g[2].add(0);

        g[1].add(3);
        g[3].add(4);
        g[4].add(1);

        System.out.println(eulerCycleDirected(g, 0));

        n = 5;
        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        g[0].add(1);
        g[1].add(0);
        g[1].add(2);
        g[2].add(1);
        g[2].add(3);
        g[3].add(2);
        g[0].add(3);
        g[3].add(0);

        g[0].add(4);
        g[4].add(0);
        g[1].add(4);
        g[4].add(1);

        g[0].add(2);
        g[2].add(0);
        g[1].add(3);
        g[3].add(1);

        System.out.println(eulerCycleUndirected(g, 2));
        //System.out.println(eulerCycleUndirected2(g, 2));
    }
}
