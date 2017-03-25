package Solutions.Codeforces;
import java.util.*;
import java.io.*;

public class codeforces_510C_2 {

    static boolean visited[];
    static List<Integer>[] graph;
    static boolean cycle[];
    static PrintWriter out;
    static ArrayList<Integer> res;

    static void dfs(int u) {
        visited[u] = cycle[u] = true;
        for (int v : graph[u]) {
            if(cycle[v]) {
                System.out.println("Impossible");
                System.exit(0);
            }
            if (!visited[v]) {
                dfs(v);
            }
        }
        cycle[u] = false;
        res.add(u);
    }

    /*
    1. edge case of a.length() > b.length()
    2. check for cycle with floyd!!! pretty cool
    3. check for cycle with dfs(int u, int v) with cycle[u] = true, false
    4. check for cycle with bfs  if adj[][] still has true... or out.size() < 0;
     */

    public static void main(String[] args) throws IOException {
            /*
            0. Cycle is with cycle[u] = true, cycle[u] = false
            1. char a = x + '49' + '0' or x + 'a'
            2. System.out.println() in functions... System.exit(0);
            1. String comparison
            2. One trick which is you cannot have greater length
            3. Optimization
            4. graph dfs visited[u]... visited ... List<Integer>[];
            5. visited[i]... visited[i]... visited[u]... visited[u] ...
            6. check for cycles by doing cycle[u] = true; System.out.println(impossible); System.exit(0);
            7. visited[u]... visited[u]... res.add(u);
             */
            //BufferedReader in = new BufferedReader(new FileReader("input.in"));
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
            //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            String[] strs = new String[n];
            for (int i = 0; i < n; i++) {
                strs[i] = in.readLine();
            }
            graph = new List[26];
            for (int i = 0; i < 26; i++) {
                graph[i] = new ArrayList<Integer>();
            }
            visited = new boolean[26];
            cycle = new boolean[26];

            for (int j = 0; j < n - 1; j++) {
                String a = strs[j];
                String b = strs[j + 1];
                boolean diff = true;
                for (int i = 0; i < a.length() && i < b.length(); i++) {
                    if(a.charAt(i) != b.charAt(i)) {
                        int u = (int) (a.charAt(i) - 'a');
                        int v = (int) (b.charAt(i) - 'a');
                        graph[u].add(v);
                        diff = false;
                        break;
                    }
                }
                if (a.length() > b.length() && diff) {
                    System.out.println("Impossible");
                    System.exit(0);
                }
            }
            res = new ArrayList<Integer>();
            for (int i = 0; i < 26; i++) {
                if(!visited[i]) {
                    dfs(i);
                }
            }
            boolean marked[] = new boolean[26];
            Collections.reverse(res);
            for (int v : res) {
                char c = (char) (v + 'a');
                out.print(c);
                marked[v] = true;
            }
            /*for (int v = 0; v < marked.length; v++) {
                if (!marked[v]) {
                    char c = (char) (v + 48 + '0');
                    out.print(c);
                }
            }*/
            out.println();
            out.close();
            System.exit(0);
    }
}

