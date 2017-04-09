import java.util.*;
import java.io.*;

public class temp {
    static int dfn[];
    static int low[];
    static List<Edge>[] graph;
    static int time;
    static Stack<Integer> stack;
    static boolean instack[];
    static int bcc;
    static int component[];

    static void tarjan(int u, int p) {
        low[u] = dfn[u] = ++time;
        stack.add(u);
        instack[u] = true;
        for (Edge v : graph[u]) {
            int v1 = v.v;
            if (v1 == p) {
                continue;
            } else if (dfn[v1] == -1) {
                tarjan(v1, u);
                low[u] = Math.min(low[u], low[v1]);
            } else {
                low[u] = Math.min(low[u], dfn[v1]);
            }
        }
        if (low[u] == dfn[u]) {
            int x;
            while (true) {
                x = stack.pop();
                component[x] = bcc;
                instack[x] = false;
                if(x == u) {
                    break;
                }
            }
            bcc++;
        }
    }

    public static class Edge {
        int v, w;
        public Edge(int v, int w) {
            this.v = v;
            this.w = w;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<Edge>();
        }
        component = new int[n];
        bcc = 0;
        time = 0;
        low = new int[n];
        dfn = new int[n];
        stack = new Stack<Integer>();
        instack = new boolean[n];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            graph[u].add(new Edge(v, c));
            graph[v].add(new Edge(u, c));
        }
        st = new StringTokenizer(in.readLine());
        int s = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        Arrays.fill(dfn, -1);
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1){
                tarjan(i, -1);
            }
        }
        /*for (int i = 0; i < component.length; i++) {
            System.out.println(component[i]);
        }*/
        List<Edge>[] g = new List[bcc];
        int[] val = new int[bcc];
        for (int i = 0; i < n; i++) {
            for (Edge e: graph[i]) {
                int i1 = component[i];
                int i2 = component[e.v];
                if (i1 != i2) {
                    g[i1].add(e);
                } if (i1 == i2) {
                    val[i1]+=e.w;
                }
            }
        }


        out.close();
        System.exit(0);
    }

    /*static class Pair implements Comparable<Pair> {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int compareTo(Pair p) {
            if (first != p.first)
                return Integer.compare(first, p.first);
            return Integer.compare(second, p.second);
        }

        public int hashCode() {
            return first * 1_000_003 + second;
        }

        public boolean equals(Object o) {
            if (o == null || !(o instanceof Pair))
                return false;
            Pair p = (Pair) o;
            return first == p.first && second == p.second;
        }
    }*/
}


