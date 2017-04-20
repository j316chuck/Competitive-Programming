package Solutions.GCJ.GCJ_2017.Round_0;

/**
 * Created by chuck on 4/8/2017.
 * Problem: AscendingNumbers
 * Origin: Qualification Round 2017
 */
import java.util.*;
import java.io.*;

public class AscendingNumbers {
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int t = Integer.parseInt(st.nextToken());
        for (int testcase = 1; testcase <= t; testcase++) {
            char[] strs = in.readLine().toCharArray();
            char[] result = new char[strs.length];
            result[0] = strs[0];
            for (int i = 0; i < strs.length - 1; i++) {
                if (strs[i] <= strs[i + 1]) {
                    result[i + 1] = strs[i + 1];
                } else {
                    int k = i;
                    while (k-1 >= 0 && result[k-1] == result[k]) {
                        k--;
                    }
                    int c = result[k] - '0' - 1;
                    result[k] =(char) (c + '0');;
                    for (int j = k + 1; j < strs.length; j++) {
                        result[j] = '9';
                    }
                    break;
                }
            }
            /*if (result[0] == '0') { //edge case
                for (int i = 1; i < result.length; i++) {
                    result[i] = '9';
                }
            }*/
            out.printf("Case #%d: ", testcase);
            for (int i = 0; i < result.length; i++) {
                if (result[i] != '0') {
                    out.printf("%c", result[i]);
                }
            }
            out.println();
        }
        out.close();
        System.exit(0);
    }
}


