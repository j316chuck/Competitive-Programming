package Solutions.USACO;
import java.util.*;
import java.io.*;

public class msched {
    static int time[];
    static int cost[];
    static HashMap<Integer, ArrayList<Integer> > mp = new HashMap<Integer, ArrayList<Integer>>();

    static int dfs(int pos) {
        if(cost[pos] != -1) {
            return cost[pos];
        }
        if(!mp.containsKey(pos)){
            cost[pos] = time[pos];
            return time[pos];
        }
        int ret = 0;
        for(int val : mp.get(pos)){
            ret = Math.max(dfs(val), ret);
        }
        cost[pos] = ret + time[pos];
        return cost[pos];
    }

    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("input.in"));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("msched.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        time = new int[n+1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(in.readLine());
            time[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(in.readLine());
            int before = Integer.parseInt(st.nextToken());
            int after  = Integer.parseInt(st.nextToken());
            if(!mp.containsKey(after)){
                mp.put(after, new ArrayList<Integer>());
            }
            mp.get(after).add(before);
        }

        cost = new int[n+1];
        Arrays.fill(cost, -1);
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if(cost[i] == -1){
                result = Math.max(result, dfs(i));
            }
        }
        out.println(result);
        out.close();
        System.exit(0);
    }
}
