package Algorithms;
import java.util.*;
import java.io.*;

public class Prim {

    private static class Edge implements Comparable<Edge>{
        public int v, w;
        public Edge(int v, int w) {
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Edge e){
            Integer weight = this.w;
            return weight.compareTo(e.w);
        }
    }

    private static int prim(List<Edge>[] graph, int start) {
        PriorityQueue<Edge> q = new PriorityQueue<Edge>();
        q.add(new Edge(start, 0));
        int total = 0;
        boolean[] visited = new boolean[graph.length];
        while (!q.isEmpty()) {
            Edge currentedge = q.poll();
            int u = currentedge.v;
            int w = currentedge.w;
            if (visited[u] == true) {
                continue;
            }
            visited[u] = true;
            total += w;

            for (Edge e : graph[u]) {
                if (!visited[e.v]) {
                    q.add(e);
                }
            }
        }
        return total;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<Edge>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<Edge>();
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            int w = Integer.parseInt(st.nextToken());
            Edge e = new Edge(v, w);
            Edge e2 = new Edge(u, w);
            graph[u].add(e);
            graph[v].add(e2);
        }

        int total = prim(graph, 0);
        System.out.println(total);
    }

}
