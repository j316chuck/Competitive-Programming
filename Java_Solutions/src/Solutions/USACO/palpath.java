package Solutions.USACO;

import java.io.*;
import java.util.*;
public class palpath {
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("input.in"));
        //PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("palpath.out")));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        n = Integer.parseInt(br.readLine());
        char[][] grid = new char[n][n];
        for(int i = 0; i < n; i++) {
            String s = br.readLine();
            for(int j = 0; j < n; j++) {
                grid[i][j] = s.charAt(j);
            }
        }
        long[][] dp = new long[n][n];
        for(int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        final long MOD = 1000000007;
        for(int num = n-1; num >= 1; num--) {
            long[][] next = new long[n][n];
            for(int a = 0; a < n; a++) {
                int rowA = a;
                int colA = (num-1-a);
                if(colA < 0) continue;
                for(int b = 0; b < n; b++) {
                    int rowB = b;
                    int colB = 2*n-num-rowB-1;
                    if(colB >= n) continue;
                    if(grid[rowA][colA] != grid[rowB][colB]) continue;
                    next[rowA][rowB] += dp[rowA][rowB];
                    if(rowA+1 < n) next[rowA][rowB] += dp[rowA+1][rowB];
                    if(rowB-1 >= 0) next[rowA][rowB] += dp[rowA][rowB-1];
                    if(rowA+1 < n && rowB-1 >= 0) next[rowA][rowB] += dp[rowA+1][rowB-1];
                    next[rowA][rowB] %= MOD;
                }
            }
            dp = next;
            pw.println();
            pw.println("ITERATION: ");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    pw.print(dp[i][j] + " ");
                } pw.println();
            }
        }
        pw.println(dp[0][n-1]);
        pw.close();
    }
}