package Solutions.POJ;
import java.util.*;
import java.io.*;

public class poj_2337 {

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());

        for (int testcases = 0; testcases < n; testcases++) {
            List<String>[] start = new List[26];
            for (int k = 0; k < 26; k++) {
                start[k] = new ArrayList<String>();
            }
            int parent[] = new int[26];
            for (int i = 0; i < 26; i++) {
                parent[i] = i;
            }
            boolean[] visited = new boolean[26];
            int forests = 0;
            int[] count = new int[26];

            st = new StringTokenizer(in.readLine());
            int m = Integer.parseInt(st.nextToken());

            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(in.readLine());
                String s = st.nextToken();
                int u = s.charAt(0) - 'a';
                start[u].add(s);
                count[u]++;
                int v = s.charAt(s.length() - 1) - 'a';
                count[v]--;
                int pu = find(u, parent);
                int pv = find(v, parent);
                if (pu != pv) {
                    parent[pu] = pv;
                    forests--;
                }
                visited[u] = true;
                visited[v] = true;
            }

            boolean none = false;
            int beg = -1;
            int odd = 0;
            int min = 27;
            for (int i = 0; i < 26; i++) {
                if (start[i].size() != 0) {
                    min = Math.min(min, i);
                }
                if (count[i] == 1) {
                    beg = i;
                    odd++;
                } else if (count[i] == -1) {
                    odd++;
                } else if (count[i] != 0){
                    none = true;
                    break;
                }
                if (odd > 2) {
                    none = true;
                    break;
                }
            }
            for (int i = 0; i < 26; i++) {
                if (visited[i]) {
                    forests++;
                }
            }
            if (forests != 1) {
                none = true;
            }
            if (none) {
                System.out.println("***");
                continue;
            }
            for (int i = 0; i < 26; i++) {
                Collections.sort(start[i]);
            }
            List<String> result = new ArrayList<String>();
            if (beg == -1) {
                beg = min;
            }
            int curEdge[] = new int[26];
            dfs(beg, start, result, curEdge);
            for (int i = result.size() - 1; i >= 0; i--) {
                System.out.print(result.get(i) + (i == 0 ? "\n" : "."));
            }
        }
        System.exit(0);
    }

    public static void dfs(int u, List<String>[] graph, List<String> result, int[] curEdge) { // a little bit trickier with strings...
        if (curEdge[u] >= graph[u].size()) {
            return;
        }
        int initpos = curEdge[u];
        while (curEdge[u] < graph[u].size()){
            String s = graph[u].get(curEdge[u]);
            curEdge[u]++;
            int v = s.charAt(s.length() - 1) - 'a';
            dfs(v, graph, result, curEdge);
        }
        result.add(graph[u].get(initpos));
    }
    /* reimplement???
    private static void dfs(int u, List<List<String>> words, boolean[][] used, List<String> ans) {
		for (int i = 0; i < words.get(u).size(); ++i) {
			char[] chars = words.get(u).get(i).toCharArray();
			int v = chars[chars.length - 1] - 'a';
			if (!used[u][i]) {
				used[u][i] = true;
				dfs(v, words, used, ans);
				ans.add(words.get(u).get(i));
			}
		}
	}
     */
    public static int find(int x, int parent[]) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x], parent);
    }
}
