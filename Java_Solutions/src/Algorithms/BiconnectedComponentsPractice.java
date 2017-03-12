package Algorithms;

import java.util.*;
import java.io.*;


public class BiconnectedComponentsPractice {

    static List<Integer>[] graph;
    static List<Integer> cutpoints;
    static List<String> bridges;
    static List<List<String>> components;
    static int[] parents;
    static int[] low;
    static int[] tin;
    static int time;
    static boolean[] visited;
    static Stack<String> stack; // should create an edge class that is just u, v may extend comparable may write by yourself

    static void init(int n) {
        parents = new int[n];
        low = new int[n];
        tin = new int[n];
        visited = new boolean[n];
        stack = new Stack<String>();
        time = 0;
        cutpoints = new ArrayList<Integer>();
        bridges = new ArrayList<String>();
        components = new ArrayList<List<String>>();
    }

    private static void findCutPoints(List<Integer>[] g) {
        graph = g;
        Arrays.fill(low, 1<<30);
        Arrays.fill(parents, -1);
        for (int i = 0; i < g.length; i++) {
            if (!visited[i]) {
                dfs(i);
            }
            addBiconnected("");
        }
    }

    private static void dfs(int u) {
        visited[u] = true;
        low[u] = tin[u] = time++;
        int child = 0;
        boolean cutpoint = false;
        for (int v : graph[u]) {
            if (v == parents[u]) {
                continue;
            } if (visited[v]) {
                stack.add(u + " " + v);
                low[u] = Math.min(low[u], tin[v]);
            } else {
                stack.add(u + " " + v);
                parents[v] = u;
                dfs(v);
                child++;
                low[u] = Math.min(low[u], low[v]);
                if ((parents[u] == -1 && child >= 2) ||
                        ((low[v] >= tin[u]) && (parents[u] != -1))) {
                    cutpoint = true;
                    addBiconnected(u + " " + v);
                }

                if (low[v] > tin[u]) {
                    if (u < v) bridges.add(u + " " + v);
                    else bridges.add(v + "  " + u);
                }
            }
        }

        if(cutpoint) {
            cutpoints.add(u);
        }
    }

    private static void addBiconnected(String s) {
        List<String> component = new ArrayList<String>();
        while (!stack.isEmpty()) {
            String x = stack.pop();
            component.add(x);
            if (x.equals(s)) {
                break;
            }
        }
        if (!component.isEmpty()) components.add(component);
    }
    /*private static void stackComponents(int u) {
        List<Integer> component = new ArrayList<Integer>();
        while (!stack.isEmpty()) {
            int x = stack.pop();
            component.add(x);
            if (x == u) {
                break;
            }
        }
        if (!component.isEmpty()) components.add(component);
    } */
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
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1; //for graphs that start from one not 0
            graph[a].add(b);
            graph[b].add(a);
    }
    init(n);
    findCutPoints(graph);

    /*Collections.sort(cutpoints);
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
        /*    }
        });
        System.out.println(bridges.size());
        for (String bridge : bridges) {
            System.out.println(bridge);
        }*/
        int odd = 0, even = 0;
        for (List<String> component: components) {
            System.out.println(component);
            if (component.size() % 2 == 0) {
                odd++;
            } else {
                even++;
            }
        }
        System.out.println(odd + " " + even);
        in.close();
        System.exit(0);
    }
}
