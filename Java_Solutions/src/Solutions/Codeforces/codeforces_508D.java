package Solutions.Codeforces;

import java.util.*;
import java.io.*;

public class codeforces_508D {

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        Solver solve = new Solver(in, out, 1);
        out.println();
        out.close();
        System.exit(0);
    }
}

class Solver {

    final int ALPHABET = 256;
    final int N = ALPHABET * ALPHABET;

    ArrayList<Integer>[] graph; //or you can use a queue/linkedlist for fast deletion
    ArrayList<Integer> eulerPath;

    int getId(char c1, char c2) {
        return c1 * ALPHABET + c2;
    }

    void dfs(int u) {
        while (graph[u].size() > 0) {
            int v = graph[u].get(graph[u].size() - 1);
            graph[u].remove(graph[u].size() - 1);
            dfs(v);
        }
        eulerPath.add(u);
    }

    public Solver(BufferedReader in, PrintWriter out, int testNumber) throws IOException {
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        String[] s = new String[n];
        graph = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        int[] degIn = new int[N];
        int[] degOut = new int[N];
        HashMap<Pair, Integer> toId = new HashMap<Pair, Integer>();
        for (int i = 0; i < n; i++) {
            s[i] = in.readLine();
            int prefix = getId(s[i].charAt(0), s[i].charAt(1));
            int suffix = getId(s[i].charAt(1), s[i].charAt(2));
            graph[prefix].add(suffix);
            degIn[prefix]++;
            degOut[suffix]++;
            toId.put(new Pair(prefix, suffix), i);
        }
        int start = -1, end = -1, any = -1;
        for (int i = 0; i < N; i++) {
            if (degOut[i] > 0) {
                any = i;
            }
            if (Math.abs(degIn[i] - degOut[i]) >= 2) {
                out.println("NO");
                return;
            } if (degIn[i] - degOut[i] == 1) {
                if (start != -1) {
                    out.println("NO");
                    return;
                }
                start = i;
            } if (degIn[i] - degOut[i] == -1) {
                if (end != -1) {
                    out.println("NO");
                    return;
                }
                end = i;
            }
        }
        if (start == -1) {
            start = any;
        }
        eulerPath = new ArrayList<Integer>();
        dfs(start);
        if (eulerPath.size() != n + 1) {
            out.println("NO");
            return;
        }
        out.println("YES");
        Collections.reverse(eulerPath);
        //out.println(eulerPath);
        for (int i = 0; i < n; i++) {
            int a = eulerPath.get(i);
            int b = eulerPath.get(i+1);
            String curr = s[toId.get(new Pair(a, b))];
            out.print(i == 0 ? curr : curr.charAt(2));
        }
        out.println();

    }

}

class Pair implements Comparable<Pair> {
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
