package Algorithms;

import java.util.*;

public class EulerianTour {
    //to make it a euler's path/cycle in an undirected graph/directed graph all you have to do is make sure
    //you are starting on the right edge...
    //Use coding conventions List<Integer> function is small name, queue, stack names, res, circuit etc. isEmpty()

    public static List<Integer> eulerCycleDirected(List<Integer>[] g, int u) {
        int n = g.length;
        int[] curEdge = new int[n];
        Stack<Integer> s = new Stack<Integer>();
        List<Integer> circuit = new ArrayList<Integer>();
        s.add(u);
        while (!s.isEmpty()) {
            int v = s.pop();
            while (curEdge[v] < g[v].size()) {
                s.push(v);
                v = g[v].get(curEdge[v]++);
            }
            circuit.add(v);
        }
        Collections.reverse(circuit);
        return circuit;
    }
    public static List<Integer> eulerCycleDirected2(List<Integer>[] g, int u) {
        int n = g.length;
        int[] curEdge = new int[n];
        List<Integer> res = new ArrayList<Integer>();
        dfs(res, u, curEdge, g);
        Collections.reverse(res);
        return res;
    }
    public static void dfs(List<Integer> res, int u, int[] curEdge, List<Integer>[] g) {
        while (curEdge[u] < g[u].size()) {
            int v = g[u].get(curEdge[u]);
            curEdge[u]++;
            dfs(res, v, curEdge, g);
        }
        res.add(u);
    }

    public static List<Integer> eulerCycleDirected3(List<Integer>[] g, int u) {
        Stack<Integer> s = new Stack<Integer>();
        s.add(u);
        int[] curEdge = new int[g.length];
        ArrayList<Integer> circuit = new ArrayList<Integer>();
        while (!s.isEmpty()) {
            int v = s.pop();
            while(curEdge[v] < g[v].size()) {
                s.push(v);
                v = g[v].get(curEdge[v]++);
            }
            circuit.add(v);
        }
        Collections.reverse(circuit);
        return circuit;
    }

    public static List<Integer> eulerCycleUndirected(List<Integer>[] g, int u) {
        int n = g.length;
        int[] curEdge = new int[n];
        Stack<Integer> stack = new Stack<Integer>();
        stack.add(u);
        Set<Long> usededges = new HashSet<Long>();
        List<Integer> res = new ArrayList<Integer>();
        while (!stack.isEmpty()) {
            u = stack.pop();
            while (curEdge[u] < g[u].size()) {
                int v = g[u].get(curEdge[u]++);
                //long hashsum = ((long) (Math.min(u, v) << 32) + Math.max(u, v)); // if you go v, u you will never go u, v
                if (usededges.add((((long) Math.min(u, v) << 32) + Math.max(u, v)))) {
                    stack.push(u);
                    u = v;
                }
            }
            res.add(u);
        }
        Collections.reverse(res);
        return res;
    }

    public static List<Integer> eulerCycleUndirected2(List<Integer>[] g, int u) {
        int n = g.length;
        int[] curEdge = new int[n];
        Set<Long> usededges = new HashSet<Long>();
        List<Integer> result = new ArrayList<Integer>();
        dfs(g, result, usededges, curEdge, u);
        Collections.reverse(result);
        return result;
    }

    public static void dfs(List<Integer>[] g, List<Integer> result, Set<Long> usededges, int[] curEdge, int u) {
        while (curEdge[u] < g[u].size()) {
            int v = g[u].get(curEdge[u]++);
            long hashsum = ((long) Math.min(u, v) << 31) + Math.max(u, v);
            if (usededges.add(hashsum)) {
                dfs(g, result, usededges, curEdge, v);
            }
        }
        result.add(u);
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
        System.out.println(eulerCycleDirected2(g, 0));
        System.out.println(eulerCycleDirected3(g, 0));
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
        System.out.println(eulerCycleUndirected2(g, 2));
    }

}