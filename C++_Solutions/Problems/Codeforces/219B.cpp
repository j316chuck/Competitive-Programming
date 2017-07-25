#include <bits/stdc++.h>
using namespace std;

int g[55][55];
int dp[55][55][55][55];
int num[55][55];

int main() {
    //freopen("219B.in", "r", stdin);
    int n, m, q;
    scanf("%d %d %d ", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &g[i][j]);
            num[i][j] = num[i][j-1] + 1;
            if (g[i][j] == 1) num[i][j] = 0;
        }
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= m; b++) {
            for (int c = a; c <= n; c++) {
                for (int d = b; d <= m; d++) {
                    int &cur = dp[a][b][c][d] = dp[a][b][c][d-1] + dp[a][b][c-1][d] - dp[a][b][c-1][d-1];
                    int add = d - b + 1;
                    for (int i = c; i >= a; i--) {
                        add = min(add, num[i][d]);
                        cur += add;
                    }
                }
            }
        }
    }

    int a, b, c, d;
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        printf("%d\n", dp[a][b][c][d]);
    }
}
