package Solutions;

import java.util.*;
import java.io.*;

public class maxcross {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("maxcross.in"));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("maxcross.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        k--;

        boolean broken[] = new boolean[n+1];
        for(int i = 0; i < b; i++){
            st = new StringTokenizer(in.readLine());
            int broke = Integer.parseInt(st.nextToken());
            broken[broke] = true;
        }

        int prefixsums[] = new int[n+1];
        for(int i = 1; i <= n; i++){
            if(broken[i]) prefixsums[i] = prefixsums[i-1] + 1;
            else prefixsums[i] = prefixsums[i-1];
        }

        int total = 100001;
        for(int i = 1; i <= n-k; i++) {
            total = Math.min(total, prefixsums[i+k]-prefixsums[i]);
        }
        out.println(total);
        out.close();
        System.exit(0);
    }
}
