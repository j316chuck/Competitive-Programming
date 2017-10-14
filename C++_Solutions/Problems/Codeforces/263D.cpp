#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int n;
vector<int> graph[maxn];
long long dp[maxn][2];
int color[maxn];

void dfs(int u, int par) {
    dp[u][color[u]] = 1;
    for (int v : graph[u]) {
        if (v == par) continue;
        dfs(v, u);
        long long black = dp[u][1];
        long long white = dp[u][0];
        dp[u][0] = 0;
        dp[u][1] = 0;
        dp[u][0] = (dp[u][0] + white * dp[v][0]) % mod;
        dp[u][0] = (dp[u][0] + white * dp[v][1]) % mod;
        dp[u][1] = (dp[u][1] + black * dp[v][0]) % mod;
        dp[u][1] = (dp[u][1] + white * dp[v][1]) % mod;
        dp[u][1] = (dp[u][1] + black * dp[v][1]) % mod;
        //cout << dp[u][0] << ' ' << dp[u][1] << endl;
    }
}

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int p;
        cin >> p;
        graph[p].push_back(i);
        graph[i].push_back(p);
    }

    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    dfs(0, -1);
    cout << dp[0][1] << endl;
}

