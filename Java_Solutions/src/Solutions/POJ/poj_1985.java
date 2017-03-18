package Solutions.POJ;
import java.util.*;
import java.io.*;

public class poj_1985 {

    private static class pp  {
        public int v, w;
        public pp(int v, int w) {
            this.v = v;
            this.w = w;
        }
    }


    private static int dfs(int u, int prev_dir, pp[][] graph, int mem[][]) {
        if (prev_dir != -1 && mem[u][prev_dir] != -1) {
            return mem[u][prev_dir];
        }
        int result = 0;
        int dir[] = new int[4];
        for (int i = 0; i < 4; i++) {
            if (graph[u][i] == null || prev_dir == i) {
                continue;
            }
            dir[i] = graph[u][i].w + dfs(graph[u][i].v, (i + 2) % 4, graph, mem);
        }
        Arrays.sort(dir);
        result = result + dir[3] + (prev_dir == -1 ? dir[2] : 0);
        if (prev_dir != -1) {
            mem[u][prev_dir] = result;
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        HashMap<Character, Integer> mp = new HashMap<Character, Integer>();
        mp.put('N', 0); mp.put('E', 1); mp.put('S', 2); mp.put('W', 3);
        pp[][] graph = new pp[40010][4];
        int u, v, w, dd; char d;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());
            d = (st.nextToken().toCharArray())[0];
            dd = mp.get(d);
            graph[u][dd] = new pp(v, w);
            graph[v][(dd + 2) % 4] = new pp(u, w);
        }
        int mem[][] = new int[40010][4];
        for (int i = 0; i < 40010; i++) {
            Arrays.fill(mem[i], -1);
        }
        int ret = 0;
        for (int i = 1; i <= n; i++) {
            ret = Math.max(dfs(i, -1, graph, mem), ret);
        }
        out.println(ret);
        out.close();
    }
}
