#include <bits/stdc++.h>
using namespace std;


const int maxn = 5e4 + 5;
const int maxm = 103;
const long long mod = 1e9 + 7;
vector< vector<int> > graph;
vector<int> w;
int n, k;
long long dp[maxn][maxm];

void dfs(int u, int par) {
    long long dpv[maxm][maxm] = {0};
    dp[u][w[u]] = 1;
    dpv[0][w[u]] = 1;
    int nextchild = 1;
    for (int v : graph[u]) {
        if (v == par) continue;
        dfs(v, u);
        for (int i = 0; i <= k; i++) {
            dpv[nextchild][i] = dpv[nextchild - 1][i];
        }
        for (int i = w[u]; i <= k; i++) { //can also set i to w[u] to speed up (on tests speeds up by factor of 6!) i usually set as 0
            for (int j = 0; j <= k - i; j++) {
                dpv[nextchild][i + j] = (dpv[nextchild][i + j] + dpv[nextchild - 1][i] * dp[v][j]) % mod;
            }
        }
        nextchild++;
    }
    for (int i = 0; i <= k; i++) {
        dp[u][i] = dpv[nextchild - 1][i];
    }
}

void solve() {
    memset(dp, 0, sizeof(dp));
    graph.clear();
    cin >> n >> k;
    w.resize(n + 1);
    graph.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1, 0);
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total = (total + dp[i][k]) % mod;
    }
    cout << total << endl;
}

int main() {
    //freopen("input.in", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}
