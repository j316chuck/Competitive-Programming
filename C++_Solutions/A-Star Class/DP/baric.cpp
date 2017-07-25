#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
long long w[maxn];
long long pre[maxn][maxn], dp[maxn][maxn];

int main() {
    freopen("baric.in", "r", stdin);
    int n; long long max_e;
    scanf("%d %lld", &n, &max_e);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &w[i]);
    }
    for (int i = 0; i <= n; i++) {
        for (int j = i+1; j <= n+1; j++) {
            if (i == 0) {
                for (int k = i+1; k < j; k++) {
                    pre[i][j] += 2 * abs(w[j] - w[k]);
                }
            } else if (j == n+1) {
                for (int k = i+1; k < j; k++) {
                    pre[i][j] += 2 * abs(w[i] - w[k]);
                }
            } else {
                for (int k = i+1; k < j; k++) {
                    pre[i][j] += abs(w[j] + w[i] - 2 * w[k]);
                }
            }
        }
    }

    pre[0][n+1] = 1LL<< 60;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][1] = 0;
    for (int len = 2; len <= n+2; len++) {
        for (int i = len-1; i <= n+1; i++) {
            for (int k = 0; k < i; k++) {
                dp[i][len] = min(dp[i][len], dp[k][len-1] + pre[k][i]);
            }
        }
    }

    for (int i = 2; i <= n+2; i++) {
        if (dp[n+1][i] <= max_e) {
            printf("%d %lld\n", i-2, dp[n+1][i]);
            break;
        }
    }
    return 0;
}
