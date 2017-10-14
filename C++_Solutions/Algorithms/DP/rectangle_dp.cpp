#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;
int cost[maxn][maxn], dp[maxn][maxn];
int n, m, q, x, y;

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> cost[i][j];
        }
    }
    dp[1][1] = cost[1][1];
    for (int i = 2; i <= m; i++) {
        dp[1][i] = dp[1][i - 1] + cost[1][i];
    }
    for (int i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][1] + cost[i][1];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + cost[i][j];
        }
    }
    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dp[i][j] << ' ';
        } cout << endl;
    }*/
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        cout << dp[x][y] << endl;
    }
    return 0;
}
