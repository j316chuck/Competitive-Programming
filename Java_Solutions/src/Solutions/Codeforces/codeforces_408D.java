package Solutions.Codeforces;

import java.util.*;
import java.io.*;

public class codeforces_408D {
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(in.readLine());
        HashSet<Integer> set = new HashSet<Integer>();
        LinkedList<Integer> q = new LinkedList<Integer>();
        boolean[] visited = new boolean[n];

        for (int i = 0; i < k; i++) {
            int a = Integer.parseInt(st.nextToken()) - 1;
            visited[a] = true;
            q.push(a);
        }
        List<Pair>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<Pair>();
        }
        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            graph[a].add(new Pair(b, i)); graph[b].add(new Pair(a, i));
            set.add(i);
        }

        while (!q.isEmpty()) {
            int top = q.poll();
            for (Pair w : graph[top]) {
                if (!visited[w.first]) {
                    q.add(w.first);
                    set.remove(w.second);
                    visited[w.first] = true;
                }
            }
        }
        System.out.println(set.size());
        for (int x : set) {
            System.out.print(x + 1 + " ");
        }
        System.out.println();
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
