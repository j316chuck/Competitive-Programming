package Solutions.POJ;
import java.math.BigInteger;
import java.util.*;
import java.io.*;
/**
 * Created by chuck on 6/8/2017.
 */
public class poj_2084 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger dp[] = new BigInteger[105];
        dp[0] = BigInteger.ONE;
        dp[1] = BigInteger.valueOf(1); //practice with BigIntegers...
        for (int i = 2; i <= 100; i++) {
            dp[i] = BigInteger.valueOf(0);
            for (int j = 0; j < i; j++) {
                dp[i] = dp[i].add(dp[j].multiply(dp[i - j - 1]));
            }
        }
        while (true) {
            int n = in.nextInt();
            if (n == -1) break;
            System.out.println(dp[n]);
        }
        System.exit(0);
    }
}
