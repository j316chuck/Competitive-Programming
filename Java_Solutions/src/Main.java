import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader in;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new FileReader("input.in"));
        //in = new BufferedReader(new InputStreamReader(System.in));
        //out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int testcases = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= testcases; t++) {
            TaskB solver = new TaskB();
            solver.solve(t);
        }
        out.close();
        System.exit(0);
    }

    static class TaskB {
        final int MAXN = 110;
        int N;

        public void solve(int t) throws IOException {
            Scanner in = new Scanner(System.in);
            //System.out.println();
        }
    }
}
