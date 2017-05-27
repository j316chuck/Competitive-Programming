package Solutions.GCJ.GCJ_2017.Round_1C;
import java.util.*;
import java.io.*;

public class C {
    static BufferedReader in;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new FileReader("input.in"));
        //in = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int testcases = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= testcases; t++) {
            TaskC solver = new TaskC();
            solver.solve(t);
        }
        out.close();
        System.exit(0);
    }

    static class TaskC {

        public void solve(int t) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(in.readLine());
            double u = Double.parseDouble(st.nextToken());
            double[] arr = new double[n+1];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                arr[i] = Double.parseDouble(st.nextToken());
            }
            arr[n] = 1.0;
            Arrays.sort(arr);
            double sum = 0;
            for (int i = 1; i <= n; i++) {
                double add = (arr[i] - arr[i-1]) * i;
                if (sum + add > u) {
                    double d = (u - sum) / (double) i;
                    for (int j = 0; j < i; j++) {
                        arr[j] = arr[i-1] + d;
                    }
                    break;
                } else {
                    sum += add;
                    for (int j = 0; j < i; j++) {
                        arr[j] = arr[i];
                    }
                }
            }
            double ret = 1;
            for (int i = 0; i <= n; i++) {
                ret *= arr[i];
            }
            out.printf("Case #%d: %.9f\n", t, ret);
        }
    }
}

