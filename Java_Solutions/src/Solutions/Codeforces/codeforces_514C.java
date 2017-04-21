package Solutions.Codeforces;

import java.io.*;
import java.util.HashSet;
import java.util.StringTokenizer;

/**
 * Created by chuck on 4/19/2017.
 */
public class codeforces_514C {

    public static HashSet<Long> set = new HashSet<Long>();
    public static final long MOD = 123456789341l;
    public static final long MULTIPLY = 257;
    public static final long POWERS[] = new long[655360];

    public static long hash(String s) {
        long result = 0;
        for (int i = 0; i < s.length(); i++) {
            result = ((result * MULTIPLY + s.charAt(i))) % MOD;
        }
        return result;
    }

    public static void init() {
        POWERS[0] = 1;
        for (int i = 1; i < POWERS.length; i++) {
            POWERS[i] = ((POWERS[i-1] * MULTIPLY)) % MOD;
        }
    }

    public static boolean judge(String s) {
        long hashvalue = hash(s);
        for (int i = 0; i < s.length(); i++) {
            for (char c = 'a'; c <= 'c'; c++) {
                if (c == s.charAt(i)) {
                    continue;
                }
                long hashmodification = (hashvalue + ((c - s.charAt(i)) * POWERS[s.length() - i - 1]) % MOD + MOD) % MOD;
                if (set.contains(hashmodification)) {
                    return true;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            set.add(hash(in.readLine()));
        }
        init();
        for (int i = 0; i < m; i++) {
            System.out.print(judge(in.readLine()) ? "YES\n": "NO\n");
        }
        out.close();
        System.exit(0);
    }

}
