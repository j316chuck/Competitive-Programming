package Solutions.Codeforces; /**
 * Created by chuck on 3/28/2017.
 */
import java.io.*;
import java.util.*;

public class codeforces_406A {
    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        boolean[] marked = new boolean[105000];
        for (int i = b; i < marked.length; i+=a) {
            marked[i] = true;
        }
        for (int i = d; i < marked.length; i+=c) {
            if (marked[i]) {
                System.out.println(i);
                System.exit(0);
            }
        }
        System.out.println(-1);
        //out.close();
        System.exit(0);
    }
}
