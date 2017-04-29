package Solutions.Codeforces;

import java.util.*;
import java.io.*;

public class codeforces_260D {
    final static int MAXN = 100010;
    final static int ALPHABET = 26;
    static boolean win[] = new boolean[MAXN];
    static boolean lose[] = new boolean[MAXN];
    static int trie[][] = new int[MAXN][ALPHABET];
    static int tsz = 0;

    public static void dfs(int v) {
        int degree = 0;
        for (int i = 0; i < 26; i++) {
            if (trie[v][i] != 0) {
                degree++;
                dfs(trie[v][i]);
                win[v] |= !win[trie[v][i]];
                lose[v] |= !lose[trie[v][i]];
            }
        }
        if (degree == 0) {
            lose[v] = true;
            win[v] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(new FileReader("input.in"));
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        for (int i = 0; i < n; i++) {
            String s = in.next();
            int v = 0;
            for (char c : s.toCharArray()) {
                if (trie[v][c - 'a'] == 0) {
                    trie[v][c - 'a'] = ++tsz;
                }
                v = trie[v][c - 'a'];
            }
        }
        dfs(0);
        if (win[0] == false || (lose[0] == false && k % 2 == 0)) {
            System.out.println("Second");
        } else {
            System.out.println("First");
        }
    }
}
