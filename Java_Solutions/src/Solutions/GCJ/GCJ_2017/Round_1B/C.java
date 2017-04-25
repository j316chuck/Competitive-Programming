package Solutions.GCJ.GCJ_2017.Round_1B;

import java.util.*;
import java.io.*;

public class C {
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
        long fdist[][] = new long[MAXN][MAXN];
        double rdist[][] = new double[MAXN][MAXN];
        int N, Q;
        long rate[] = new long[MAXN];
        long maxdist[] = new long[MAXN];

        public void solve(int t) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            N = Integer.parseInt(st.nextToken());
            Q = Integer.parseInt(st.nextToken());
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(in.readLine());
                maxdist[i] = Long.parseLong(st.nextToken());
                rate[i] = Long.parseLong(st.nextToken());
            }
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(in.readLine());
                for (int j = 0; j < N; j++) {
                    fdist[i][j] = Long.parseLong(st.nextToken());
                    if (i == j) fdist[i][j] = 0;
                    else if (fdist[i][j] == -1) fdist[i][j] = (long) 1e12;
                }
            }
            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        fdist[i][j] = Math.min(fdist[i][j], fdist[i][k] + fdist[k][j]);
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (fdist[i][j] > maxdist[i]) {
                        rdist[i][j] = 1e12d;
                    } else {
                        rdist[i][j] = fdist[i][j] / (double) rate[i];
                    }
                }
            }
            for (int k = 0; k < N; k++) {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        rdist[i][j] = Math.min(rdist[i][j], rdist[i][k] + rdist[k][j]);
                    }
                }
            }
            out.printf("Case #%d: ", t);
            for (int i = 0; i < Q; i++) {
                st = new StringTokenizer(in.readLine());
                int u = Integer.parseInt(st.nextToken()) - 1;
                int v = Integer.parseInt(st.nextToken()) - 1;
                out.printf("%.7f ", rdist[u][v]);
            }
            out.println();
        }
    }
}

