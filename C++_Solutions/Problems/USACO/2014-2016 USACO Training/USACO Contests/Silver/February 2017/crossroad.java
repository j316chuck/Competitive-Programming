package Solutions;
import java.util.*;
import java.io.*;

public class crossroad {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("crossroad.in"));
        //PrintWriter out = new PrintWriter( new BufferedWriter( new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter( new BufferedWriter( new FileWriter("crossroad.out")));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());

        Set<Integer> cows = new TreeSet<Integer>();
        int arr[][] = new int[100][2];
        int total = 0;
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            int position = Integer.parseInt(st.nextToken());
            int crossed = Integer.parseInt(st.nextToken());
            if(!cows.contains(position)){
                cows.add(position);
                arr[position][crossed] = 1;
                continue;
            }
            if(arr[position][crossed] == 0){
                arr[position][crossed] = 1;
                total++;
                arr[position][1-crossed] = 0;
            }
        }

        out.println(total);
        out.close();
        System.exit(0);
    }
    class pair implements Comparator<pair>{
        public int pos;
        public int crossed;

        public pair(int p, int c){
            pos = p;
            crossed = c;
        }
        public int compare(pair p1, pair p2){
            return p1.pos - p2.pos;
        }
    }
}
