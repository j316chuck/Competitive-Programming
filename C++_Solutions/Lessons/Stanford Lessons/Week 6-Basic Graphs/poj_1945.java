package Solutions;

import java.io.*;
import java.util.*;

public class powerhungrycows {

    static int n;
    static Queue<int[]> queue= new LinkedList<int[]>();
    static boolean[][] visited = new boolean[20100][100];; //15 million okay...

    //static int[][] q = new int[800000][3];
    //static int last = -1, head = -1;
    //static final int[][][] transitions = {{{0, 0}, {1, 0}}, {{1, -1}, {1, 0}}, {{1, 1}, {1, 0}}, {{2, 0}, {1, 0}}, {{0, 2}, {1, 0}}, {{0, 0}, {0, 1}}, {{1, -1}, {0, 1}}, {{1, 1}, {0, 1}}, {{2, 0}, {0, 1}}, {{0, 2}, {0, 1}}};
    /*private static class Pair {
        int x, y, val;
        public Pair(int x, int y, int val) {
            this.x = x;
            this.y = y;
            this.val = val;
        }
    }*/

    private static boolean addNode(int x, int y, int step) {
        if (x == n || y == n) {
            return true;
        }
        if (y > x) {
            int temp = y;
            y = x;
            x = temp;
        }
        if (x == y || x >= 20100 || y >= 100) {
            return false;
        }
        if (!visited[x][y]) {
            visited[x][y] = true;
            queue.add(new int[]{x, y, step});
        }
        return false;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());
        n = Integer.parseInt(st.nextToken());

        queue.add(new int[]{1,0,0});
        while (!queue.isEmpty()) {
            int[] top = queue.poll();
            int w0 = top[0];
            int w1 = top[1];
            int step = top[2] + 1;
            if ( addNode(2 * w0, w1, step) || addNode(w0 + w1, w1, step) || addNode(2 * w1, w1, step) || addNode(2 * w0, w0, step) //make sure to increment the right queue steps...
                    || addNode(w0 + w1, w0, step) || addNode(2 * w1, w0, step) || addNode(w0 - w1, w0, step)) {
                out.println(step);
                out.close();
                System.exit(0);
            }
        }
        /*addNode(1, 0, 0);
        while (head < last) {
            head++;
            int w0 = q[head][0], w1 = q[head][1], step = q[head][2] + 1;
            if ( addNode(2 * w0, w1, step) || addNode(w0 + w1, w1, step) || addNode(2 * w1, w1, step) || addNode(2 * w0, w0, step) //make sure to increment the right queue steps...
                || addNode(w0 + w1, w0, step) || addNode(2 * w1, w0, step) || addNode(w0 - w1, w0, step)) {
                out.println(step);
                out.close();
                System.exit(0);
            }
        }*/
        //out.close();
        //System.exit(0);
        /*Queue<Pair> queue = new LinkedList<Pair>();
        queue.add(new Pair(1, 0, 0));
        int x, y, temp;
        while(!queue.isEmpty()) {
            Pair top = queue.poll();
            if (top.x == n) {
                out.println(top.val);
                out.close();
                System.exit(0);
            }
            for (int i = 0; i < transitions.length; i++) {
                x = transitions[i][0][0] * top.x + transitions[i][0][1] * top.y;
                y = transitions[i][1][0] * top.x + transitions[i][1][1] * top.y;
                if (x >= 30000 || y >= 200) continue;
                if (visited[x][y]) continue;
                if (y > x) {
                    temp = y;
                    y = x;
                    x = temp;
                }
                visited[x][y] = true;
                queue.add(new Pair(x, y, top.val + 1));
            }
        }*/
    }
}
