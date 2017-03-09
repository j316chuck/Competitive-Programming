package Algorithms;

import java.util.*;
import java.io.*;


public class BiconnectedComponentsPractice {

    static List<Integer>[] graph;
    static boolean[] visited;
    static Stack<Integer> stack;
    static int[] parents;
    static int time;
    static int[] low;
    static int[] tin;
    static List<Integer> cutpoints;
    static List<String> bridges;
    static List<List<Integer>> components;

    static void init(int n) {
        parents = new int[n];
        low = new int[n];
        tin = new int[n];
        visited = new boolean[n];
        stack = new Stack<Integer>();
        time = 0;
        cutpoints = new ArrayList<Integer>();
        bridges = new ArrayList<String>();
        components = new ArrayList<List<Integer>>();
    }

    private static void findCutPoints(List<Integer>[] g) {
        graph = g;
        Arrays.fill(low, 1<<30);
        Arrays.fill(parents, -1);
        for (int i = 0; i < g.length; i++) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
    }

    private static void dfs(int u, int p) {
        visited[u] = true;
        low[u] = tin[u] = time++;
        int child = 0;
        boolean cutpoint = false;
        for (int v : graph[u]) {
            if (v == p) {
                continue;
            } if (visited[v]) {
                low[u] = Math.min(low[u], tin[v]);
            } else {
                //parents[v] = u;
                dfs(v, u);
                child++;
                low[u] = Math.min(low[u], low[v]);
                cutpoint = cutpoint | (low[v] >= tin[u] && p != -1);
                if (low[v] > tin[u]) {
                    if (v > u) bridges.add(u + " " + v);
                    else bridges.add(v + " " + u);
                }
            }
        }
        if (child >= 2 && p == -1) {
            cutpoint = true;
        } if (cutpoint) {
            cutpoints.add(u);
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }
        init(n);
        findCutPoints(graph);

        Collections.sort(cutpoints);
        System.out.println(cutpoints.size());
        for (int cutpoint : cutpoints) {
            System.out.print(cutpoint + " ");
        }
        System.out.println();

        Collections.sort(bridges, new Comparator<String>() {
            public int compare(String s1, String s2) {
                return s1.compareTo(s2);
                /*int u1 = Integer.parseInt((s1.split(" "))[0]);
                int v1 = Integer.parseInt((s1.split(" "))[1]);
                int u2 = Integer.parseInt((s2.split(" "))[0]);
                int v2 = Integer.parseInt((s2.split(" "))[1]);
                if (u1 == v1)
                    return u2 - v2;
                else
                    return u1 - v2;*/
            }
        });
        System.out.println(bridges.size());
        for (String bridge : bridges) {
            System.out.println(bridge);
        }
        in.close();
        System.exit(0)  ;
    }
}
