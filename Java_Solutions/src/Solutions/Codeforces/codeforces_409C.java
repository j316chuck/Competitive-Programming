package Solutions.Codeforces;
import java.util.*;
import java.io.*;

public class codeforces_409C {

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
        int n = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        double powerconsumed = 0;
        ArrayList<Node> A = new ArrayList<Node>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            double p1 = Double.parseDouble(st.nextToken());
            double s1 = Double.parseDouble(st.nextToken());
            A.add(new Node(p1, s1));
            powerconsumed += p1;
        }
        if (powerconsumed <= p) {
            out.println(-1);
            out.close();
            System.exit(0);
        }
        Collections.sort(A);

        powerconsumed = 0;
        double totaltime = 0;
        double remainingpower = 0;
        for (int i = 0; i < A.size(); i++) {
            remainingpower -= (A.get(i).time - totaltime) * (powerconsumed - p);
            if (remainingpower <= 0) {
                remainingpower += (A.get(i).time - totaltime) * (powerconsumed - p);
                out.println(totaltime + remainingpower / (powerconsumed - p));
                out.close();
                System.exit(0);
            }
            totaltime = A.get(i).time;
            powerconsumed += A.get(i).power;
        }
        out.println(remainingpower / (powerconsumed - p) + totaltime);
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


