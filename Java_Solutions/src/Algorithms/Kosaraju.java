package Algorithms;

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
//best and clearest article/implementation http://e-maxx.ru/algo/strong_connected_components

public class Kosaraju {

    public static void dfs(ArrayList<Integer> order, boolean[] used, int u, List<Integer>[] g) {
        used[u] = true;
        for (int v : g[u]) {
            if (!used[v]) {
                dfs(order, used, v, g);
            }
        }
        order.add(u);
    }

    //use static for competitive programming but not projects
    public static List<List<Integer>> stronglyConnectedComponents(List<Integer>[] g, List<Integer>[] gr) {
        int n = g.length - 1;
        ArrayList<Integer> order = new ArrayList<Integer>();
        boolean[] used = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                dfs(order, used, i, g);
            }
        }
        Collections.reverse(order);
        List<List<Integer>> components = new ArrayList<List<Integer>>();
        Arrays.fill(used, false);

        for (int u : order) {
            if (!used[u]) {
                ArrayList<Integer> component = new ArrayList<Integer>(); //be very careful with clear and components
                dfs(component, used, u, gr);
                components.add(component);
            }
        }
        return components;
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        String line = in.readLine();
        String[] ln = line.split(" ");
        int n = Integer.parseInt(ln[0]);
        int m = Integer.parseInt(ln[1]);
        //List<List<Integer>> g = new ArrayList<List<Integer>>();
        List<Integer>[] g = new List[n + 1];
        List<Integer>[] gr = new List[n + 1];

        for (int i = 0; i <= n; i++) {
            g[i] = new ArrayList<Integer>();
            gr[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < m; i++) {
            ln = in.readLine().split(" ");
            int a = Integer.parseInt(ln[0]);
            int b = Integer.parseInt(ln[1]);
            g[a].add(b);
            gr[b].add(a);
        }
        List<List<Integer>> scc = stronglyConnectedComponents(g, gr);
        int C = 0, D = 0;
        for (List<Integer> components: scc) {
            int sizeofscc = components.size();
            if (sizeofscc % 2 == 0) {
                D += sizeofscc;
            } else {
                C += sizeofscc;
            }
        }

        System.out.println(C - D);
        in.close();
        System.exit(0);
    }
}
