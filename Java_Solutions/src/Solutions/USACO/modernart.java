package Solutions.USACO;

import java.io.*;
import java.util.*;

public class modernart {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        Stack<Integer> stack = new Stack<Integer>();
        int[] xmin = new int[n + 1];
        int[] xmax = new int[n + 1];
        Arrays.fill(xmin, 100000000);
        Arrays.fill(xmax, -100000000);
        int[] colors = new int[n + 2];
        colors[0] = 0;
        colors[n + 1] = 0;
        for (int i = 0; i < n; i++) {
            if (i >= 1 && i <= n) {
                st = new StringTokenizer(in.readLine());
                colors[i] = Integer.parseInt(st.nextToken());
            }
            xmin[colors[i]] = Math.min(xmin[colors[i]], i);
            xmax[colors[i]] = Math.max(xmax[colors[i]], i);
        }
        int ret = 0;
        for (int i = 0; i <= n + 1; i++) {
            if (xmin[colors[i]] == i) {
                stack.push(colors[i]);
                ret = Math.max(ret, stack.size());
            }
            if (stack.get(stack.size() - 1) != colors[i]) {
                out.println(-1);
                out.close();
                System.exit(0);
            }
            if (i == xmax[colors[i]]) {
                stack.pop();
            }
        }
        out.println(ret);
        out.close();
        System.exit(0);
    }
}
