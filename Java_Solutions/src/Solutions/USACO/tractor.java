package Solutions.USACO;//package Solutions;
import java.io.*;
import java.util.*;

public class tractor {
    static int n;
    static boolean visited[][];
    static int graph[][];
    static int dr[] = {0, 1, 0, -1};
    static int dc[] = {1, 0, -1, 0}; //south west north east

    static int floodfill(int r, int c, int range){
        int result = 1;
        visited[r][c] = true;
        for(int i = 0; i < 4; i++){
            int nr = dr[i] + r;
            int nc = dc[i] + c;
            if(nr >= 0 && nc >= 0 && nr < n && nc < n && !visited[nr][nc]){
                if(Math.abs(graph[nr][nc]-graph[r][c]) <= range){
                    result += floodfill(nr, nc, range);
                }
            }
        }
        return result;
    }

    static boolean possible(int range) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j]){
                    if(floodfill(i, j, range) * 2 >= n * n){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("Solutions.USACO.tractor.in"));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Solutions.USACO.tractor.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        n = Integer.parseInt(st.nextToken());
        graph = new int[n][n];
        visited = new boolean[n][n];
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            for(int j = 0; j < n; j++) {
                graph[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        /*int lo = 0;
        int high = 1000001;
        while(lo + 5 <= high){
            int mid = (lo + high)/2;
            if(possible(mid)) {
                high = mid - 1;
            }else {
                lo = mid + 1;
            }
        }
        for(int i = -1; i < 5; i++) {
            if(possible(i + lo)){
                out.println(i + lo);
                break;
            }
        }*/
        int lo = -1;
        int high = 10000001;
        while(lo + 1 < high){
            int mid = (lo + high)/2;
            if(possible(mid))
                high = mid;
            else
                lo = mid;
        }
        out.println(high);
        out.close();
        System.exit(0);
    }
}
