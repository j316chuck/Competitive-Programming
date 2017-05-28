package Solutions.POJ;
import java.util.*;
import java.io.*;

public class poj_2186B {
    static int scc[];
    static int time;
    static int current_scc;
    static int componentsize[];

    private static void tarjan(List<Integer>[] graph) {
        int n = graph.length;
        time = 0;
        int current_scc = 0;
        scc = new int[n + 1];
        int dfn[] = new int[n + 1];
        int low[] = new int[n + 1];
        boolean stacked[] = new boolean[n + 1];
        Arrays.fill(dfn, -1);
        Stack<Integer> stack = new Stack<Integer>();
        componentsize = new int[n + 1];
        for (int i = 1; i < graph.length; i++) {
            if (dfn[i] == -1) {
                dfs(graph, dfn, low, stack, i, stacked);
            }
        }
    }

    private static void dfs(List<Integer>[] graph, int[] dfn, int low[], Stack<Integer> stack, int u, boolean[] stacked) {
        dfn[u] = low[u] = time++;
        stack.add(u);
        stacked[u] = true;
        for (int v: graph[u]) {
            if (dfn[v] == -1) {
                dfs(graph, dfn, low, stack, v, stacked);
                low[u] = Math.min(low[u], low[v]);
            } else if (stacked[v]){
                low[u] = Math.min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int x;
            do {
                x = stack.pop();
                stacked[x] = false;
                scc[x] = current_scc;
                componentsize[current_scc]++;
            } while (x != u);
            current_scc++;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        List<Integer>[] graph = (List<Integer>[]) new List[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
        }
        tarjan(graph);
        /*for (int i = 1; i <= n; i++) {
            System.out.print(scc[i] + " ");
        }*/
        int index[] = new int[current_scc];
        for (int u = 1; u <= n; u++) {
            for (int v : graph[u]) {
                if (scc[v] != scc[u]) {
                    index[scc[u]]++;
                }
            }
        }
        int flag = 0;
        int ret = -1;
        for (int i = 0; i < index.length; i++) {
            if (index[i] == 0) {
                flag++;
                ret = componentsize[i];
            }
        }
        if (flag != 1) {
            ret = 0;
        } else {
            out.println(ret);
        }

        out.close();
        System.exit(0);
    }
}
