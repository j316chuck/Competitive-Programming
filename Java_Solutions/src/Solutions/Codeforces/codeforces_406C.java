package Solutions.Codeforces; /**
 * Created by chuck on 3/28/2017.
 */
import java.util.*;
import java.io.*;

public class codeforces_406C {
    static int n;
    static int[][] mem;
    static List<Integer> rick;
    static List<Integer> morty;
    //0 = rick won
    //1 = morty won
    //2 = infinite
    //0 = rick turn
    //1 = morty turn;
    //mem[k][i] = pos, whose turn
    //indexed 0 -> n

    static int dfs(int pos, int turn) {
        if (pos == 0 && turn == 0) {
            return 1;
        } if (pos == 0 && turn == 1) {
            return 0;
        } if (mem[turn][pos] != -1) {
            return mem[turn][pos];
        } if (mem[turn][pos] == -2) {
            return 2;
        }
        List<Integer> list = (turn == 0 ? rick : morty);
        boolean win = false;
        mem[turn][pos] = -2;
        boolean loop = false;
        for (int v : list) {
            int a = dfs((pos + v) % n, 1 - turn);
            if (a == turn) {
                win = true;
            } if (a == 2) {
                loop = true;
            }
        }
        if (!loop) {
            mem[turn][pos] = 1 - turn;
        }
        if (win) {
            mem[turn][pos] = turn;
        }
        return mem[turn][pos];
    }

    public static void main(String[] args) throws IOException {
        //BufferedReader in = new BufferedReader(new FileReader("input.in"));
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        //PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        n = Integer.parseInt(st.nextToken());
        mem = new int[2][n];
        Arrays.fill(mem[0], -1);
        Arrays.fill(mem[1], -1);
        st = new StringTokenizer(in.readLine());
        rick = new ArrayList<Integer>();
        morty = new ArrayList<Integer>();
        int k1 = Integer.parseInt(st.nextToken());
        for (int i = 0; i < k1; i++) {
            rick.add(Integer.parseInt(st.nextToken()));
        }
        st = new StringTokenizer(in.readLine());
        int k2 = Integer.parseInt(st.nextToken());
        for (int i = 0; i < k2; i++) {
            morty.add(Integer.parseInt(st.nextToken()));
        }
        for (int k = 0; k < 2; k++) {
            for (int i = 1; i < n; i++) {
                if (mem[k][i] == -1) {
                    dfs(i, k);
                }
                if (mem[k][i] == 2) {
                    System.out.print("Loop ");
                } else if ((mem[k][i] == 0 && k == 0) || (mem[k][i] == 1 && k == 1)) {
                    System.out.print("Win ");
                } else if (mem[k][i] != k){
                    System.out.print("Lose ");
                }
            }
            System.out.println();
        }
        System.exit(0);
    }
}
