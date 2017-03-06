package Solutions;

import java.io.*;
import java.util.*;

public class knight {

    static int rows, columns;
    static int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    static int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    public static void main(String[] args) throws IOException{

        //BufferedReader in = new BufferedReader(new FileReader("msched.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());

        for(int i = 1; i <= n; i++){
            st = new StringTokenizer(in.readLine());
            columns = Integer.parseInt(st.nextToken()); //4 - 1 2 3 4
            rows = Integer.parseInt(st.nextToken()); //3 - A B C
            boolean visited[][] = new boolean[rows+1][columns+1];  //1 - rows indexed

            List<String> result = dfs(1, 1, rows * columns, visited);
            Collections.reverse(result);
            out.printf("Scenario #%d:\n", i);
            if(result.size() != rows * columns) {
                out.print("impossible\n");
            }else{
                for(String res: result){
                    out.print(res);
                }
                out.println();
            }
            out.println();
        }

        out.close();
        System.exit(0);
    }

    static String convert(int i, int j){
        char c[] = Character.toChars(i + 64); //important + 64
        return Character.toString(c[0]) + Integer.toString(j);
    }

    static ArrayList<String> dfs(int r, int c, int expected, boolean visited[][]){
        ArrayList<String> result = new ArrayList<String>();
        if(visited[r][c]) return result;
        visited[r][c] = true;
        if(expected == 1) {
            result.add(convert(r, c));
            return result;
        }
        for(int i = 0; i < 8; i += 1) {
            int newr = dr[i] + r;
            int newc = dc[i] + c;
            if (newr <= 0 || newc <= 0 || newr > rows || newc > columns || visited[newr][newc]) {
                continue;
            }
            result = dfs(newr, newc, expected - 1, visited);
            if (result.size() == expected - 1) {
                visited[r][c] = false; //optional
                result.add(convert(r, c));
                return result;
            }
        }
        visited[r][c] = false;
        return new ArrayList<String>();
    }
}
