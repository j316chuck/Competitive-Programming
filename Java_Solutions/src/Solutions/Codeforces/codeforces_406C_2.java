package Solutions.Codeforces;

import java.io.*;
import java.util.*;

public class codeforces_406C_2 {
    static ArrayList<Integer> moves[] = new ArrayList[2];
    static int dp[][]; //1 = win 2 = lose
    static int n;
    static int deg[][];

    static void dfs(int p, int x) {
        int np = 1 - p;
        for (int i = 0; i < moves[np].size(); i++) {
            int nx = (x - moves[np].get(i) + n) % n;
            if (dp[np][nx] != 0) {
                continue;
            } if (dp[p][x] == 1) {
                deg[np][nx]--;
                if (deg[np][nx] == 0) {
                    dp[np][nx] = 2;
                    dfs(np, nx);
                }
            } else if (dp[p][x] == 2) {
                dp[np][nx] = 1;
                dfs(np, nx);
            }
        }
    }
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        n = Integer.parseInt(st.nextToken());
        dp = new int[2][n]; //0 - n-1
        st = new StringTokenizer(in.readLine());
        int k1 = Integer.parseInt(st.nextToken());
        deg = new int[2][n];
        moves[0] = new ArrayList<Integer>();
        for (int i = 0; i < k1; i++) {
            moves[0].add(Integer.parseInt(st.nextToken())); //rick
        }
        st = new StringTokenizer(in.readLine());
        int k2 = Integer.parseInt(st.nextToken());
        moves[1] = new ArrayList<Integer>();
        for (int i = 0; i < k2; i++) {
            moves[1].add(Integer.parseInt(st.nextToken())); //morty
        }
        dp[0][0] = 2;
        dp[1][0] = 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    deg[i][j] = k1;
                } else {
                    deg[i][j] = k2;
                }
            }
        }
        dfs(0, 0);
        dfs(1, 0);

        for (int i = 0; i < 2; i++) {
            for (int k = 1; k < n; k++) {
                if (dp[i][k] == 0) {
                    out.print("Loop ");
                } else if (dp[i][k] == 1) {
                    out.print("Win ");
                } else {
                    out.print("Lose ");
                }
            }
            out.println();
        }
        out.close();
        System.exit(0);
    }
}
