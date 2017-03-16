package Solutions.USACO;
import java.io.*;
import java.util.*;
public class countcross {

    static int dr[] = {1, -1, 0, 0};
    static int dc[] = {0, 0, 1, -1};
    static Map<Pair<Integer, Integer>, ArrayList< Pair<Integer, Integer> > > mp= new HashMap<Pair<Integer, Integer>, ArrayList< Pair<Integer, Integer> > >();

    static class Pair<X, Y> {
        public X first;
        public Y second;

        public Pair(X f, Y s){
            first = f;
            second = s;
        }
        void setFirst(X f) {
            first = f;
        }
        void setSecond(Y s) {
            second = s;
        }

        @Override
        public boolean equals(Object p1){ //can also do p1.first.equals() and p2.first.equals();
            if(p1 == this) return true;
            if(p1 == null) return false;
            if(p1.getClass() != this.getClass()) return false;
            Pair other = (Pair) p1;
            return other.first.equals(this.first) && other.second.equals(this.second);
        }

        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + (first == null ? 0 : first.hashCode());
            result = prime * result + (second == null ? 0 : second.hashCode());
            return result;
        }
    }

    static void floodfill(int r, int c, int counter, int graph[][], int n){
        graph[r][c] = counter;
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr <= 0 || nc <= 0 || nr > n || nc > n || graph[nr][nc] != 0){
                continue;
            }if(mp.containsKey(new Pair(r, c)) && mp.get(new Pair(r, c)).contains(new Pair(nr, nc))){
                continue;
            }
            floodfill(nr, nc, counter, graph, n);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("countcross.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        for (int i = 0; i < r; i++) {
            st = new StringTokenizer(in.readLine());
            int r1 = Integer.parseInt(st.nextToken());
            int c1 = Integer.parseInt(st.nextToken());
            int r2 = Integer.parseInt(st.nextToken());
            int c2 = Integer.parseInt(st.nextToken());
            if(!mp.containsKey(new Pair(r1, c1))){
                mp.put(new Pair(r1, c1), new ArrayList<Pair<Integer, Integer>>());
            }
            mp.get(new Pair(r1, c1)).add(new Pair(r2, c2));
        }

        int graph[][] = new int[n+1][n+1];
        int counter = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if(graph[i][j] == 0){
                    floodfill(i, j, counter, graph, n);
                    counter++;
                }
            }
        }

        ArrayList<Pair<Integer, Integer>> cows = new ArrayList<Pair<Integer, Integer>>();
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            for(Pair<Integer, Integer> p : cows) {
                if(graph[p.first][p.second] != graph[x][y]){
                    counter++;
                }
            }
            cows.add(new Pair(x, y));
        }

        out.println(counter);
        out.close();
        System.exit(0);
    }
}
