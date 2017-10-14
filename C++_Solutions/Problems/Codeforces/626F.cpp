#include <bits/stdc++.h>
using namespace std;

const int maxn = 205;
const int maxm = 1005;
const int mod = 1e9 + 7;
long long dp[2][maxn][maxm];
int a[maxn];
int n, k;

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    dp[1][1][0] = 1;
    dp[1][0][0] = 1;
    for (int i = 1; i < n; i++) {
        memset(dp[(i + 1) % 2], 0, sizeof(dp[(i + 1) % 2]));
        for (int g = 0; g <= i; g++) {
            for (int j = 0; j <= k; j++) {
                if (!dp[i % 2][g][j]) continue;
                int v = j + g * (a[i + 1] - a[i]);
                if (v > k) continue;
                dp[(i + 1) % 2][g][v] = (dp[(i + 1) % 2][g][v] + dp[i % 2][g][j]) % mod;
                dp[(i + 1) % 2][g][v] = (dp[(i + 1) % 2][g][v] + ((1LL * g * dp[i % 2][g][j]) % mod)) % mod;
                if (g) dp[(i + 1) % 2][g - 1][v] = (dp[(i + 1) % 2][g - 1][v] + ((1LL * g * dp[i % 2][g][j]) % mod)) % mod;
                dp[(i + 1) % 2][g + 1][v] = (dp[(i + 1) % 2][g + 1][v] + dp[i % 2][g][j]) % mod;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = (ans + dp[n % 2][0][i]) % mod;
    }
    cout << ans << endl;
}

