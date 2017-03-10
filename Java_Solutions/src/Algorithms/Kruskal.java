package Algorithms;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Kruskal {
     static int total;
     static int[] parent;

     private static class Edge implements Comparable<Edge> {
        public int u, v, w;

        public Edge(int u, int v, int w) {
            this.u = u;
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Edge e) {
            Integer w1 = this.w;
            return w1.compareTo(e.w);
        }

        @Override
        public boolean equals(Object e) {
            if (this == e) return true;
            if (e == null) return false;
            if (e.getClass() != getClass()) return false;
            Edge that = (Edge) e;
            if (that.u != this.u || that.v != this.v || that.w != this.w) return false;
            return true;
        }

        @Override
        public int hashCode() {
            return Arrays.hashCode(new Object[]{u, v, w});
        }

    }

    private static void Kruskal(List<Edge> graph) { //actually for simplicity sake just do the comparator thing...
         Collections.sort(graph);
         for (Edge e : graph) {
             if(union(e.u, e.v)) {
                 total += e.w;
             }
         }
    }

    private static void init(int n){
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    private static int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    private static boolean union(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu != pv) {
            parent[pu] = parent[pv];
            return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<Edge> graph = new ArrayList<Edge>();

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            int w = Integer.parseInt(st.nextToken());
            Edge e = new Edge(u, v, w);
            Edge e2 = new Edge(v, u, w);
            graph.add(e);
            graph.add(e2);
        }

        init(n);
        Kruskal(graph);
        System.out.println(total);
    }
}
