package Solutions.GCJ.GCJ_2017.Round_1B;

import java.util.*;
import java.io.*;

public class B {

    static int colors[] = new int[6];
    static int index = 0;
    static int primarycolors[] = {0, 2, 3};

    static boolean f1(int red, int green, int[] arr, PrintWriter out, int t) {
        if (colors[green] == 0) {
            return true;
        }
        if (colors[red] < colors[green]) {
            out.printf("Case #%d: IMPOSSIBLE\n", t);
            return false;
        }
        while(colors[green] != 0) {
            colors[green]--;
            colors[red]--;
            arr[index] = red;
            arr[index + 1] = green;
            index += 2;
        }
        if (index == arr.length) {
            print(out, arr, t);
            return false;
        } else {
            arr[index] = red;
            colors[red]--;
            index++;
            return true;
        }
    }

    static int getIndex(int prev, int first) {
        int mindex = -1;
        int minvalue = -1;
        for (int i : primarycolors) {
            if (i == prev || colors[i] == 0) {
                continue;
            } else if (colors[i] > minvalue) {
                mindex = i;
                minvalue = colors[i];
            } else if (colors[i] == minvalue && i == first) {
                mindex = i;
                minvalue = colors[i];
            }
        }
        return mindex;
    }
    static void print(PrintWriter out, int result[], int t) {
        out.print("Case #"); out.print(t); out.print(": ");
        for (int i = 0; i < result.length; i++) {
            if (result[i] == 0) {
                out.print("R");
            } else if (result[i] == 1) {
                out.print("O");
            } else if (result[i] == 2) {
                out.print("Y");
            } else if (result[i] == 3) {
                out.print("G");
            } else if (result[i] == 4) {
                out.print("B");
            } else if (result[i] == 5) {
                out.print("V");
            }
        }
        out.println();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int testcases = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= testcases; t++) {
            st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int result[] = new int[n];
            index = 0;
            for (int i = 0; i < 6; i++) {
                colors[i] = Integer.parseInt(st.nextToken());
            }
            if (!f1(0, 3, result, out, t)) {
                continue;
            } if (!f1(4, 1, result, out, t)) {
                continue;
            } if (!f1(2, 5, result, out, t)) {
                continue;
            }

            int i1;
            boolean flag = false;
            while (index != n) {
                if (index - 1 > 0) {
                    i1 = getIndex(result[index-1], result[0]);
                } else {
                    i1 = getIndex(-1, -1);
                }
                if (i1 == -1) {
                    flag = true;
                    break;
                }
                colors[i1]--;
                result[index] = i1;
                index++;
            }
            if (result[0] == result[n - 1] || flag) {
                out.printf("Case #%d: IMPOSSIBLE\n", t);
                continue;
            }
            print(out, result, t);
            //out.printf("Case #%d: %f\n", t, d/maxtime);
        }
        out.close();
        System.exit(0);
    }
}

