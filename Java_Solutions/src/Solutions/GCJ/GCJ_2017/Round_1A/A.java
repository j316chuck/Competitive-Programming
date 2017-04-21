package Solutions.GCJ.GCJ_2017.Round_1A;

import java.util.*;
import java.io.*;

public class A {
    public static void update(char[][] graph, char c, int lowerrow, int leftcolumn, int upperrow, int rightcolumn) {
        for (int i = lowerrow; i <= upperrow; i++) {
            for (int j = leftcolumn; j <= rightcolumn; j++) {
                graph[i][j] = c;
            }
        }
    }
    static class Point implements Comparable<Point> {
        int r, c;
        char ch;
        Point(int r, int c, char ch) {
            this.r = r;
            this.c = c;
            this.ch = ch;
        }

        public int compareTo(Point x) {
            if (this.r == x.r) {
                return this.c - x.c;
            }
            return this.r - x.r;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int testcases = Integer.parseInt(st.nextToken());
        for (int t = 1; t <= testcases; t++) {
            st = new StringTokenizer(in.readLine());
            int rows = Integer.parseInt(st.nextToken());
            int columns = Integer.parseInt(st.nextToken());
            char[][] graph = new char[rows][];
            char start[] = new char[rows];
            Arrays.fill(start, '0');
            for (int r = 0; r < rows; r++) {
                graph[r] = in.readLine().toCharArray();
                for (int c = 0 ; c < graph[r].length; c++) {
                    if (graph[r][c] != '?' && start[r] == '0') {
                        start[r] = graph[r][c];
                    }
                }
            }
            int lastr = 0;
            for (int r = 0; r < rows; r++) {
                if (start[r] == '0') {
                    continue;
                }
                char curr = start[r];
                for (int c = 0; c < columns; c++) {
                    if (graph[r][c] == '?') {
                        graph[r][c] = curr;
                    } else {
                        curr = graph[r][c];
                    }
                }
                for (int i = r - 1; i >= 0 && start[i] == '0'; i--) {
                    System.arraycopy(graph[r], 0, graph[i], 0, graph[r].length);
                }
                lastr = r;
            }
            for (int i = lastr + 1; i < rows; i++) {
                System.arraycopy(graph[lastr], 0, graph[i], 0, graph[i].length);
            }
            /*ArrayList<Point>[] points = new ArrayList[30];
            for (int i = 0; i < points.length; i++) {
                points[i] = new ArrayList<Point>();
            }
            int lastcolumn = -1;
            for (int r = 0; r < rows; r++) {
                graph[r] = in.readLine().toCharArray();
                for (int c = 0 ; c < graph[r].length; c++) {
                    if (graph[r][c] != '?') {
                        lastcolumn = Math.max(c, lastcolumn);
                        points[c].add(new Point(r, c, graph[r][c]));
                    }
                }
            }

            int prevleftcolumn = -1, prevlowerrow = -1;
            for (int c = 0; c < columns; c++) {
                if (points[c].size() == 0) {
                    continue;
                }
                for (int r = 0; r < points[c].size(); r++) {
                    int upperrow = points[c].get(r).r;
                    int rightcolumn = points[c].get(r).c;
                    int lowerrow, leftcolumn;
                    if (r == points[c].size() - 1) { //last row fill to bottom row
                        upperrow = rows - 1;
                    } if (c == lastcolumn) { //last column fill to bottom column
                        rightcolumn = columns - 1;
                    } if (r == 0) {
                        lowerrow = 0;
                    } else {
                        lowerrow = points[c].get(r - 1).r + 1;
                    }
                    leftcolumn = prevleftcolumn + 1;
                    update(graph, points[c].get(r).ch, lowerrow, leftcolumn, upperrow, rightcolumn);
                    if (r == points[c].size() - 1) {
                        prevleftcolumn = c;
                    }
                }
            }*/

            out.printf("Case #%d: \n", t);
            for (int r = 0; r < rows; r++) {
                for (int c = 0; c < columns; c++) {
                    out.print(graph[r][c]);
                }
                out.println();
            }
        }
        out.close();
        System.exit(0);
    }
}
