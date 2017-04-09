package Solutions.GCJ;
/*
Problem: BathroomStalls
Origin: Google Code Jam Qualification Round 2017
Learned: Use priority queue for small cases, can use tree optimization/greedy
traversal to solve problem.
 */

import java.util.*;
import java.io.*;

public class BathroomStalls {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int t = Integer.parseInt(st.nextToken());
        for (int testcase = 1; testcase <= t; testcase++) {
            st = new StringTokenizer(in.readLine());
            long n = Long.parseLong(st.nextToken());
            long k = Long.parseLong(st.nextToken());
            int treeheight = (int) (Math.log(n) / Math.log(2));
            boolean[] right = new boolean[treeheight * 2];
            int counter = 0;
            while (k != 1) {
                long h = (long) (Math.log(k) / Math.log(2));
                h = (long) 1 << h;
                k -= h/2;
                if (k >= h) {
                    k -= h/2;
                    right[counter] = true;
                }
                counter++;
            }
            for (int i = counter - 1; i >= 0; i--) {
                if (right[i]) { // it is smaller
                    n = (n - 1)/2;
                } else {
                    n = n/2;
                }
            }
            out.printf("Case #%d: %d %d\n", testcase, n/2, (n-1)/2);
        }
        out.close();
        System.exit(0);
    }
}



