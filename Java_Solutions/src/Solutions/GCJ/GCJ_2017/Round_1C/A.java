package Solutions.GCJ.GCJ_2017.Round_1C;
import java.util.*;
import java.io.*;

import java.util.*;
import java.io.*;

public class A {

    static BufferedReader in;
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        in = new BufferedReader(new FileReader("input.in"));
        //in = new BufferedReader(new InputStreamReader(System.in));
        //out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int testcases = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= testcases; t++) {
            TaskA solver = new TaskA();
            solver.solve(t);
        }
        out.close();
        System.exit(0);
    }

    static class TaskA {

        public class pp {
            double radius;
            double height;
            public pp(double r, double h) {
                radius = r * r * Math.PI;
                height = 2 * h * Math.PI * r;
            }
        }

        public void solve(int t) throws IOException {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            pp[] arr = new pp[n];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(in.readLine());
                double r = Double.parseDouble(st.nextToken());
                double h = Double.parseDouble(st.nextToken());
                arr[i] = new pp(r, h);
            }
            Arrays.sort(arr, new Comparator<pp>(){
                public int compare(pp o1, pp o2) {
                    int a = -(((Double) o1.height).compareTo(o2.height));
                    if (a == 0) {
                        return -(((Double) o1.radius).compareTo(o2.radius));
                    } else {
                        return a;
                    }
                }
            });

            double biggestradius = -1;
            int biggestindex = -1;
            double result = 0;
            for (int i = 0; i < k; i++) {
                result += arr[i].height;
                if (biggestradius < arr[i].radius) {
                    biggestindex = i;
                    biggestradius = arr[i].radius;
                }
            }
            result += biggestradius;
            for (int i = k + 1; i < n; i++) {
                double difference = arr[i].radius - arr[biggestindex].radius - (arr[biggestindex].height - arr[i].height);
                if (difference > 0) {
                    result += difference;
                    biggestindex = i;
                }
            }
            out.printf("Case #%d: %.9f\n", t, result);
        }
    }
}
