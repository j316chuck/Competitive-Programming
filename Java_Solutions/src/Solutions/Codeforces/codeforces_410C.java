package Solutions.Codeforces;
import java.util.*;
import java.io.*;

public class codeforces_410C {
    static int gcd(int a, int b) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        return b == 0 ? a : gcd(b, a % b);
    }
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int arr[] = new int[n];
        st = new StringTokenizer(in.readLine());
        int d = 0;
        int moves = 0;
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            d = gcd(arr[i], d);
        }
        out.println("YES");
        if (d != 1) {
            out.println(moves);
            out.close();
            System.exit(0);
        }
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] % 2 == 1 && arr[i+1] % 2 == 1) {
                arr[i] = 2;
                arr[i+1] = 2;
                moves++;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if ((arr[i+1] % 2 == 1 && arr[i] % 2 == 0) || (arr[i+1] % 2 == 0 && arr[i] % 2 == 1)) {
                moves += 2;
                arr[i] = 2;
                arr[i+1] = 2;
            }
        }
        out.println(moves);
        out.close();
        System.exit(0);
    }
}
