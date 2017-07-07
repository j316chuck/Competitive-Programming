#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("running.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> d(n);
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            if (dp[i-1][k-1] == 0 && k!=1) continue;
            dp[i][k] = dp[i-1][k-1] + d[i];
        }
        for (int k = 1; k <= m && i - k >= 0; k++) {
            dp[i][0] = max(dp[i][0], dp[i-k][k]);
        }
        dp[i][0] = max(dp[i-1][0], dp[i][0]);
    }
    printf("%d\n", dp[n][0]);
}
