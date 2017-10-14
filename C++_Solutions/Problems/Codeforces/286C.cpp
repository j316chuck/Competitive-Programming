#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e4 + 5;
const int maxm = 600;
int mn, n, d;
int cnt[maxn];
int dp[maxn][maxm];

int dfs(int u, int m) {
    int v = d + m - 300;
    if (u > maxn || u > mn) {
        return 0;
    } if (dp[u][m] != -1) {
        return dp[u][m];
    }
    if (v == 1) {
        return dp[u][m] = cnt[u] + max(dfs(u + v, m), dfs(u + v + 1, m + 1));
    } else {
        return dp[u][m] = cnt[u] + max(dfs(u + v + 1, m + 1), max(dfs(u + v, m), dfs(u + v - 1, m - 1)));
    }
}

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> d;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        mn = max(mn, a);
    }
    cout << dfs(d, 300) << endl;
}

