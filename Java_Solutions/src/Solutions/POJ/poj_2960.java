package Solutions.POJ;

import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;

public class poj_2960 {
    static final int MAXN = 10001;
    static HashSet<Integer> set;
    static int grundy[];

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileReader("input.in"));
        //Scanner in = new Scanner(System.in);

        while (in.hasNext()) {
            set = new HashSet<Integer>();
            int k = in.nextInt();
            if (k == 0) {
                System.exit(0);
            }
            for (int i = 0; i < k; i++) {
                set.add(in.nextInt());
            }
            grundy = new int[MAXN];
            getGrundy();
            int m = in.nextInt();
            for (int i = 0; i < m; i++) {
                int n = in.nextInt();
                int xor = 0;
                for (int j = 0; j < n; j++) {
                    xor ^= grundy[in.nextInt()];
                }
                System.out.print(xor == 0 ? "L" : "W");
            }
            System.out.println();
        }
        in.close();
        System.exit(0);
    }

    static void getGrundy() {
        grundy[0] = 0;
        HashSet<Integer> hash = new HashSet<Integer>();
        for (int i = 1; i < MAXN; i++) {
            //seeing where point i can go to with move j from the set
            hash.clear();
            for (int j : set) {
                if (i - j >= 0) {
                    hash.add(grundy[i - j]);
                }
            }
            //mex algorithm
            for (int j = 0; j < MAXN; j++) {
                if (!hash.contains(j)) {
                    grundy[i] = j;
                    break;
                }
            }
        }
    }
}
