package Solutions.Codeforces;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

//http://codeforces.com/contest/510/status/C

public class codeforces_510C_1 {

    static boolean dfs(boolean[] visited, int u, List<Integer> res, List<Integer>[] graph, boolean[] used) {
        visited[u] = used[u] = true;
        boolean ret = true;
        for (int v: graph[u]) {
            if (used[v]) {
                ret = false;
            } else if (!visited[v]) {
                ret = ret && dfs(visited, v, res, graph, used);
            }
        }
        res.add(u);
        used[u] = false;
        return ret;
    }

/*static int find(int x, int parent[]) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x], parent);
}*/

    public static void main(String[] args) throws IOException {
    /*
    1. Read input in string[] strs;
    2. Make graph of graph[] = new arraylist...
    3. Make O(N^3) iteration to construct graph... use dfs?
    4. Check if cycle... it cannot have a cycle...
    5. Topological sort...
    6. print result... marked...
     */

        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        String[] strs = new String[n];
        for (int i = 0; i < n; i++) {
            strs[i] = in.readLine();
        }
        List<Integer>[] graph = (List<Integer>[]) new List[26];
        for(int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Integer>();
        }

        //will use union find... doesn't work for directed graphs how do you link 1, 2 and 1, 3
    /*int parent[] = new int[26];
    for (int i = 0; i < 26; i++) {
        parent[i] = i;
    }*/

        for (int i = 0; i < n - 1; i++) {
            String a = strs[i];
            String b = strs[i + 1];
            //edge cases of equals and all of them not equals... how to account for...
            // a.length < b.length fine... a == b and next to each other fine and not next to each other fine
            //a.length > b.length gg maybe check...
            boolean equal = true;
            int u, v;
            for (int k = 0; k < b.length() && k < a.length(); k++) {
                if(a.charAt(k) != b.charAt(k)) {
                    u = a.charAt(k) - 'a';
                    v = b.charAt(k) - 'a';
                    graph[u].add(v);
                    equal = false;
                    break;
                }
            }
            if (equal && a.length() > b.length()) {
                out.println("Impossible");
                System.exit(0);
            }
        }

        //better checks...
    /*for (int i = 0; i < graph.length; i++) {
        for (int v : graph[i]) {
            if (graph[v].contains(i)) {
                out.println("Impossible");
                System.exit(0);
            }
        }
    }*/
        boolean[] used = new boolean[26];
        List<Integer> res = new ArrayList<Integer>();
        boolean[] marked = new boolean[26];
        for (int i = 0; i < graph.length; i++) {
            if(!marked[i]) {
                if(!dfs(marked, i, res, graph, used)){
                    System.out.println("Impossible");
                    //out.println("Impossible");
                    System.exit(0);
                }
            }
        }
        Collections.reverse(res);
        System.out.println(res);
    /*String ret = "";
    for (int v : res) {
        ret += (v + 'a');
    }
    for (int i = 0; i < n; i++) {
        if(!marked[i]) {
            ret += (i + 'a');
        }
    }
    out.println(ret);*/
        out.close();
        System.exit(0);
    }
}
