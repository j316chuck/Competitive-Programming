#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
int n, k, m, x;
vector<int> graph[maxn];
long long dp[maxn][15][3];

void dfs(int u, int par) {
    dp[u][0][0] = k - 1;
    dp[u][1][1] = 1;
    dp[u][0][2] = m - k;

    for (int v : graph[u]) {
        if (v == par) continue;
        dfs(v, u);
        long long dp1[15][3] = {0};
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= x; j++) {
                if (i + j > x) break;
                dp1[i + j][0] += dp[u][i][0] * (dp[v][j][1] + dp[v][j][0] + dp[v][j][2]);
                dp1[i + j][0] %= mod;
                dp1[i + j][1] += dp[u][i][1] * (dp[v][j][0]);
                dp1[i + j][1] %= mod;
                dp1[i + j][2] += dp[u][i][2] * (dp[v][j][0] + dp[v][j][2]);
                dp1[i + j][2] %= mod;
            }
        }
        memcpy(dp[u], dp1, sizeof(dp1));
    }
}

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cin >> k >> x;
    dfs(1, -1);
    long long ans = 0;
    for (int i = 0; i <= x; i++) {
        ans = (ans + dp[1][i][0] + dp[1][i][1] + dp[1][i][2]) % mod;
    }
    cout << ans << endl;
}

