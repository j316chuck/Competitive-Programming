package Solutions.Codeforces;

/**
 * Created by chuck on 4/17/2017.
 */
import java.util.*;
import java.io.*;

public class codeforces_409A {

    static class Node implements Comparable<Node> {
        double power;
        double storage;
        double time;
        Node(double p, double s) {
            power = p;
            storage = s;
            time = s / p;
        }

        @Override
        public int compareTo(Node a) {
            return ((Double) this.time).compareTo(a.time);
        }
        public String toString() {
            return ((Double) time).toString();
        }
    }
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        String s1 = st.nextToken();
        int total = 0;
        boolean add = false;
        boolean arr[] = new boolean[s1.length()];
        for (int i = 0; i < s1.length() - 1; i++) {
            if (s1.charAt(i) == 'V' && s1.charAt(i + 1) == 'K') {
                total++;
                arr[i] = true;
                arr[i+1] = true;
            }
        }
        for (int i = 1; i < s1.length(); i++) {
            if (s1.charAt(i) == 'K' && !arr[i - 1]) {
                add = true;
            }
        }
        for (int i = 0; i < s1.length() - 1; i++) {
            if (s1.charAt(i) == 'V' && !arr[i+1]) {
                add = true;
            }
        }
        out.println(total + (add ? 1 : 0));
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



