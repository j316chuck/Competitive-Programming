import java.util.*;
import java.io.*;

public class Main {

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

    public Solver(BufferedReader in, PrintWriter out, int testNumber) throws IOException {
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());

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

