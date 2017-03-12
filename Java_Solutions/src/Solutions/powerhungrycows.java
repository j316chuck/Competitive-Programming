package Solutions;

import java.io.*;
import java.util.*;

public class powerhungrycows {

    private static int bit(int i) {
        int count = 0;
        while ((i & -i) != 0) {
            count++;
            i -= (i & -i);
        }
        return count;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int log = (int) (Math.log(n) / Math.log(2));
        if ((int) Math.pow(2, log) == n) {
            System.out.println(log);
            System.exit(0);
        }
        System.out.println(log);
        int ret1 = log + 1 + bit(n - (int) (Math.pow(2, log)));
        int ret2 = log + 2 + bit ((int) (Math.pow(2, log+1) - n));
        System.out.println(Math.max(ret1, ret2));
    }
}
