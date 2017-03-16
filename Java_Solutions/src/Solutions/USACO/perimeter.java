package Solutions.USACO;
import java.io.*;
import java.util.*;

public class perimeter {

    static int xlow = 1<<30, yhigh = -1;
    static int dx[] = {0, 1, 0, -1}; //up right down left
    static int dy[] = {1, 0, -1, -0};
    static Map<Integer, TreeSet<Integer> > mp = new HashMap<Integer, TreeSet<Integer> > ();

    static TreeSet<Point> points = new TreeSet<Point>();
    static int perimeter;
    static TreeSet<Point> visited = new TreeSet<Point>();

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("perimeter.in"));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("perimeter.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            points.add(new Point(x, y));
        }
        int sx = points.first().x - 1;
        int sy = points.first().y;
        floodfill(sx, sy);
        out.println(perimeter);

        /*for(int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            if(!mp.containsKey(x)){
                mp.put(x, new TreeSet<Integer>());
            }if(!mp.containsKey(x+1)){
                mp.put(x+1, new TreeSet<Integer>());
            }
            mp.get(x).add(y);
            mp.get(x+1).add(y);
            mp.get(x).add(y+1);
            mp.get(x+1).add(y+1);
            if(xlow > x){
                xlow = x;
                yhigh = y+1;
            }else if(xlow == x){
                yhigh = Math.max(yhigh, y+1);
            }
        }

        out.println(dfs(xlow, yhigh, 1));*/
        out.close();
        System.exit(0);
    }

    static class Point implements Comparable<Point>{
        private int x, y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }
        @Override
        public int compareTo(Point p){
            return p.x == this.x ? this.y - p.y: this.x - p.x;
        }

        @Override
        public boolean equals(Object p1){
            if(p1 == this) return true;
            if(p1 == null) return false;
            if(p1.getClass() != this.getClass()) return false;
            Point other = (Point) p1;
            return x == other.x && y == other.y;
        }
    }

    static void floodfill(int x, int y) {
        if (points.contains(new Point(x, y))) {
            perimeter++;
            return;
        }
        if(visited.contains(new Point(x, y))) return;
        boolean isolated = true;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (points.contains(new Point(x + i, y + j))) {
                    isolated = false;
                    break;
                }
            }
        }
        if (isolated) return;
        visited.add(new Point(x, y));
        floodfill(x+1, y);
        floodfill(x, y-1);
        floodfill(x-1, y);
        floodfill(x, y+1);
    }

    static int dfs(int x, int y, int dir) {
        if (x == xlow && y == yhigh - 1 && dir == 0) {
            return 1;
        }
        for(int i = 0; i < 3; i++) {
            int ndir = (dir + 3 + i) % 4;
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];
            if(mp.containsKey(nx) && mp.get(nx).contains(ny)){
                return 1 + dfs(nx, ny, ndir);
            }
        }
        return 0;
    }
}
