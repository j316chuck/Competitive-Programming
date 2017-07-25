#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int maxn = 505;
/*
1. read in grid 0 based
2. dp initialize base case where the level is equivalent to i+1, etc. dp by row and column;
3. len = 1, n-1, if (dist(i, j) > 0 continue);
4. a = for (int i = 0; i < n; i++) rowa = a; cola = n-1-length-a if (cola < 0) continue;
5. b = for (int j = 0; j < n; j++) rowb = b; colb = colb = n-1 + length - rowb (if col > n) continue;
6. next[a][b] = dp[ra][rb] if (ra+1< n) ra = ra-1, b) if (b>= 1) dp[row][rowb-1]
7. next[a][b] %= MOD;
8. dp = next;
9. dp stands for rowa and rowb
*/
char grid[maxn][maxn];
long long dp[maxn][maxn];
long long cur[maxn][maxn];

int main() {
    freopen("palpath.in", "r", stdin);
    //freopen("palpath.out", "w", stdout);
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c ", &grid[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for (int len = 1; len <= n-1; len++) {
        memset(cur, 0, sizeof(cur));
        for (int i = 0; i < n; i++) {
            int row_a = i;
            int col_a = n-1-len-row_a;
            if (col_a < 0) continue;
            for (int j = 0; j < n; j++) {
                int row_b = j;
                int col_b = n-1+len-row_b;
                if(col_b >= n) continue;
                if (grid[row_a][col_a] != grid[row_b][col_b]) continue;
                cur[row_a][row_b] += dp[row_a][row_b];
                if (row_a < n-1) cur[row_a][row_b] += dp[row_a+1][row_b];
                if (row_b > 0) cur[row_a][row_b] += dp[row_a][row_b-1];
                if (row_a < n-1 && row_b > 0) cur[row_a][row_b] += dp[row_a+1][row_b-1];
                cur[row_a][row_b] %= mod;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = cur[i][j];
            }
        }
    }
    printf("%lld\n", dp[0][n-1]);
}
