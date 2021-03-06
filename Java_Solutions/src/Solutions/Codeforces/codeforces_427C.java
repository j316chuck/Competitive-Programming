package Solutions.Codeforces;

import java.util.*;
import java.io.*;

public class codeforces_427C {
    static long cost[];
    static int dfn[];
    static int low[];
    static List<Integer>[] graph;
    static int time;
    static Stack<Integer> stack;
    static boolean instack[];
    static final long mod = 1000000007;
    static long money, ways;

    static void tarjan(int u) {
        dfn[u] = low[u] = ++time;
        instack[u] = true;
        stack.add(u);
        for (int v : graph[u]) {
            if (dfn[v] == -1) {
                tarjan(v);
                low[u] = Math.min(low[u], low[v]);
            } else if (instack[v]) {
                low[u] = Math.min(low[u], dfn[v]);
            }
        }
        if (low[u] == dfn[u]) {
            int x;
            long numways = 1;
            long mincost = Integer.MAX_VALUE;
            while (true) {
                x = stack.pop();
                instack[x] = false;
                if (mincost > cost[x]) {
                    mincost = cost[x];
                    numways = 1;
                } else if (mincost == cost[x]) {
                    numways++;
                }
                if (x == u) {
                    break;
                }
            }
            ways = ((ways * numways) % mod);
            money += mincost;
        }
    }
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        cost = new long[n];
        for (int i = 0; i < n; i++) {
            cost[i] = Long.parseLong(st.nextToken());
        }
        graph = (List<Integer>[]) new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        int m = Integer.parseInt(in.readLine());
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken()) - 1;
            int v = Integer.parseInt(st.nextToken()) - 1;
            graph[u].add(v);
        }
        dfn = new int[n];
        low = new int[n];
        Arrays.fill(dfn, -1);
        time = 0;
        stack = new Stack<Integer>();
        instack = new boolean[n];
        money = 0;
        ways = 1;
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                tarjan(i);
            }
        }
        out.println(money + " " + ways);
        out.close();
        System.exit(0);
    }

    static class Pair implements Comparable<Pair> {
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
    }
}


