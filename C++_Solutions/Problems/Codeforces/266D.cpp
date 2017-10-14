#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 5;
const long long mod = 1e9 + 7;
long long dp[maxn][maxn];
int a[maxn];

inline long long add(long long a, long long b) {
    return (a + b) % mod;
}

inline long long mult(long long a, long long b) {
    return (a * b) % mod;
}

int main() {
    //freopen("input.in", "r", stdin);
    int n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1][0] = (h == a[1] || h == a[1] + 1);
    dp[1][1] = (h == a[1] + 1);
    for (int i = 2; i <= n; i++) {
        int open = h - a[i];
        if (open < 0) break;
        dp[i][open] = add(dp[i][open], dp[i - 1][open]);
        dp[i][open] = add(dp[i][open], dp[i - 1][open - 1]);
        if (open == 0) continue;
        dp[i][open - 1] = add(dp[i][open - 1], mult(dp[i - 1][open], open));
        dp[i][open - 1] = add(dp[i][open - 1], mult(dp[i - 1][open - 1], open - 1));
        dp[i][open - 1] = add(dp[i][open - 1], dp[i - 1][open - 1]);
    }

    cout << dp[n][0] << endl;
}

