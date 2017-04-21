package Solutions.Codeforces;

import java.util.*;
import java.io.*;

public class codeforces_408C {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        Pair[] points = new Pair[n];
        int maxvalue = -1, maxn = -1, u, v, w;
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            w = Integer.parseInt(st.nextToken());
            graph[i] = new ArrayList<Integer>();
            if (w > maxvalue) {
                maxvalue = w;
                maxn = i;
            }
            points[i] = new Pair(w, i);
        }

        for (int i = 0; i < n - 1; i++) {
            st = new StringTokenizer(in.readLine());
            u = Integer.parseInt(st.nextToken()) - 1;
            v = Integer.parseInt(st.nextToken()) - 1;
            graph[u].add(v);
            graph[v].add(u);
        }

        boolean[] visited = new boolean[n];
        PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
        pq.add(points[maxn]);

        while (!pq.isEmpty()) {
            Pair top = pq.poll();
            w = top.first;
            v = top.second;
            if (visited[v]) {
                continue;
            }
            visited[v] = true;
            maxvalue = Math.max(maxvalue, w);
            for (int x : graph[v]) {
                if (!visited[x]) {
                    points[x].first++;
                    pq.add(new Pair(points[x].first, points[x].second));
                    for (int y : graph[x]) {
                        if (!visited[y]) {
                            points[y].first++;
                            pq.add(new Pair(points[y].first, points[y].second));
                        }
                    }
                }
            }
        }
        out.println(maxvalue);
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
                return -Integer.compare(first, p.first);
            return -Integer.compare(second, p.second);
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


