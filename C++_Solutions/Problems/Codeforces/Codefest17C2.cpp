#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long mod = 1e9 + 7;
int n, k, m, x;
vector<int> graph[maxn];
long long dp[maxn][15][3];
long long a[15][3], b[15][3];

void dfs(int u, int par) {
    if (graph[u].size() == 1 && par != -1) {
        dp[u][0][0] = k - 1;
        dp[u][1][1] = 1;
        dp[u][0][2] = m - k;
        return;
    }
    for (int v : graph[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    a[0][0] = a[0][1] = a[0][2] = 1;
    for (int v : graph[u]) {
        if (v == par) continue;
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= x; j++) {
                if (i + j > x) break;
                b[i + j][0] = a[i][0] * (dp[v][j][0] + dp[v][j][1] + dp[v][j][2]);
                b[i + j][0] %= mod;
                b[i + j][1] = a[i][1] * (dp[v][j][0]);
                b[i + j][1] %= mod;
                b[i + j][2] = a[i][2] * (dp[v][j][0] + dp[v][j][2]);
                b[i + j][2] %= mod;
            }
        }
        memcpy(a, b, sizeof(b));
        memset(b, 0, sizeof(b));
    }

    for (int i = 0; i <= x; i++) {
        dp[u][i][0] = ((a[i][0] + a[i][1] + a[i][2]) * (k - 1)) % mod;
        if (i) dp[u][i][1] = (a[i - 1][0]) % mod;
        dp[u][i][2] = (a[i][2] + a[i][0]) * (m - k) % mod;
    }
}

int main() {
    freopen("input.in", "r", stdin);
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

