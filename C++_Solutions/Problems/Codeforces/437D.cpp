#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
const int maxm = 5e4 + 5;
int n, r;
double p[maxn], f[maxn], s[maxn];
double dp[maxn][maxm];

double dfs(int l, int t, double e) {
    if (t > r) return e;
    if (l == n) return 0;
    if (dp[l][t] != -1.0) return dp[l][t];
    dp[l][t] = p[l] * (f[l] + dfs(l + 1, t + f[l], e)) + (1 - p[l]) * (s[l] + dfs(l + 1, t + s[l], e));
    dp[l][t] = min(e, dp[l][t]);
    return dp[l][t];
}

double calc(double e) {
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxm; j++) {
            dp[i][j] = -1.0;
        }
    }
    return dfs(0, 0, e);
}

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        cin >> f[i] >> s[i] >> p[i];
        p[i] = p[i] / 100.0;
    }
    double lo = 0, hi = 1e17 + 5;
    for (int i = 0; i < 200; i++) {
        double mid = (lo + hi) / 2.0;
        if (calc(mid) < mid) hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(9) << lo << endl;
}

