package Algorithms;

import java.io.*;
import java.util.*;
import java.math.*;
//1. stack //2. d[v] //3. no parents... 4. do while loop

public class Tarjan {
    static Stack<Integer> stack;
    static int[] d;
    static int[] low;
    static int time;
    static boolean[] instack;
    static List<Integer>[] graph;
    static List<List<Integer>> components;

    private static void init(int n) {
        time = 0;
        low = new int[n];
        d = new int[n];
        Arrays.fill(d, -1);
        instack = new boolean[n];
        components = new ArrayList<List<Integer>>();
        stack = new Stack<Integer>();
    }

    private static void tarjan(int n) {
        for (int i = 0; i < n; i++) {
            if (d[i] == -1) {
                dfs(i);
            }
        }
    }

    private static void dfs(int u) {
        d[u] = low[u] = time++;
        stack.add(u);
        instack[u] = true;
        for (int v: graph[u]) {
            if (d[v] == -1) {
                dfs(v);
                low[u] = Math.min(low[u], low[v]);
            } else if (instack[v]) {
                low[u] = Math.min(low[u], d[v]);
            }
        }
        if (d[u] == low[u]) { // head found
            int x;
            List<Integer> component = new ArrayList<Integer>();
            do {
                x = stack.pop();
                component.add(x);
                instack[x] = false;
            } while (x != u);
            components.add(component);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
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
        }
        init(n);
        tarjan(n);
        int output = 0;
        for (List<Integer> component: components) {
            if (component.size() % 2 == 0) output -= component.size();
            else output += component.size();
        }
        System.out.println(output);
        in.close();
        System.exit(0);
    }
}
