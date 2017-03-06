package Solutions;

import java.util.*;
import java.io.*;

class castle {

    static int dc[] = {-1, 0, 1, 0}; //w, n, e, s
    static int dr[] = {0, -1, 0, 1};
    static int rows, columns;

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("./src/Solutions/castle.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("./src/Solutions/castle.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        rows = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        columns = Integer.parseInt(st.nextToken());

        List<List<Room>> graph= new ArrayList<List<Room>>(); //always use List<List<Room>> = new ArrayList<List<Room>>();
        for (int i = 0; i < rows; i++) {
            graph.add(new ArrayList<Room> ());
            st = new StringTokenizer(in.readLine());
            for(int j = 0; j < columns; j++) {
                Room r = new Room(Integer.parseInt(st.nextToken()));
                graph.get(i).add(r);
                //out.print(r + " ");
            }
            //out.println();
        }

        boolean visit[][] = new boolean[rows][columns];
        //for(int i = 0; i < 4; i++) out.print(visit[i][i] + " " + dx[i] + " " + dy[i] + " "); */

        int totalrooms = 0, largestroom = 0;
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                if(!visit[i][j]) {
                    totalrooms++;
                    largestroom = Math.max(largestroom, floodfill(i, j, graph , visit));
                }
            }
        }

        out.println(totalrooms + " " + largestroom);
        out.close();
        in.close();
    }

    static int floodfill(int r, int c, List<List<Room>> graph, boolean visit[][]) {
        if(visit[r][c]) return 0; //precaution
        visit[r][c] = true;
        int roomsvisited = 1;
        for (int i = 0; i < 4; i++) {
            if (graph.get(r).get(c).dir[i]) continue;
            int newr = r + dr[i];
            int newc = c + dc[i];
            if (newr < 0 || newr >= rows || newc >= columns || newc < 0) continue;
            if (visit[newr][newc]) continue;
            roomsvisited += floodfill(newr, newc, graph, visit);
        }
        return roomsvisited;
    }

    static class Room {
        //public boolean n, e, s, w;
        public boolean dir[];

        public Room(int val) {
            dir = new boolean[4];
            int pos = 0;
            while (val > 0) {
                int bit = val & -val;
                if (bit == 1) dir[0] = true;
                else if (bit == 2) dir[1] = true;
                else if (bit == 4) dir[2] = true;
                else if (bit == 8) dir[3] = true;
                val -= bit;
            }
            /*while (val > 0) {
                int bit = val & -val;
                if (bit == 1) w = true;
                else if (bit == 2) n = true;
                else if (bit == 4) e = true;
                else if (bit == 8) s = true;
                val -= bit;
            }*/
        }

        @Override
        public String toString() {
            int sum = 0;
            /*if (n) sum += 2;
            if (w) sum += 1;
            if (e) sum += 4;
            if (s) sum += 8;*/
            int bit = 1;
            for(int i = 0; i < 4; i++) {
                if(dir[i]) sum += bit;
                bit = bit<<1;
            }
            return Integer.toString(sum);
        }
    }
}