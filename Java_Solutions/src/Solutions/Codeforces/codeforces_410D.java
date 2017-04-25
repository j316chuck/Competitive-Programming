package Solutions.Codeforces;

import java.util.*;
import java.io.*;

public class codeforces_410D {
    static class pp implements Comparable<pp> {
        int a, b, id;
        public int compareTo(pp c) {
            if (a == c.a) {
                return c.b - b;
            }
            return c.a - a;
        }
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        pp[] arr = new pp[n];
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = new pp();
            arr[i].a = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            arr[i].b = Integer.parseInt(st.nextToken());
            arr[i].id = i + 1;
        }

        Arrays.sort(arr);
        out.println(n/2 + 1);
        out.print(arr[0].id + " ");
        for (int i = 1; i < n; i+=2) {
            if (i + 1 >= n || arr[i].b > arr[i+1].b) {
                out.print(arr[i].id + " ");
            } else {
                out.print(arr[i+1].id + " ");
            }
        }
        out.println();
        out.close();
        System.exit(0);
    }
}
