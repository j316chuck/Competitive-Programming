package Solutions.Codeforces; /**
 * Created by chuck on 3/28/2017.
 */
import java.util.*;
import java.io.*;

public class codeforces_406B {
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int k = Integer.parseInt(st.nextToken());
            HashSet<Integer> set = new HashSet<Integer>();
            boolean contains = false;
            for (int j = 0; j < k; j++) {
                int a = Integer.parseInt(st.nextToken());
                set.add(a);
                if (set.contains(-a)) {
                    contains = true;
                }
            }
            if (!contains) {
                System.out.println("YES");
                System.exit(0);
            }
        }
        System.out.println("NO");
        System.exit(0);
    }
}
