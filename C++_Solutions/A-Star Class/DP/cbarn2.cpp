#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int maxk = 10;
long long ans = 1e17 + 5;
long long dp[maxn][maxk];
long long psum[maxn];

int main() {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    int n, max_k;
    scanf("%d %d", &n, &max_k);
    vector<int> v(n + 1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    if (max_k >= n) {
        printf("0\n");
        return 0;
    }

    for (int ii = 0; ii < n; ii++) {
        memset(dp, 0x3f, sizeof(dp));
        dp[1][1] = 0;
        for (int k = 2; k <= max_k; k++) {
            for (int i = k; i <= n; i++) {
                long long sum = 0, total = 0;
                for (int j = i - 1; j >= 1; j--) {
                    dp[i][k] = min(dp[i][k], dp[j][k - 1] + total);
                    sum += v[j];
                    total += sum;
                }
                //cout << dp[i][k] << ' ';
            } //cout << endl;
        }
        long long sum = 0;
        long long total = 0;
        for (int i = n; i >= 1; i--) {
            ans = min(ans, dp[i][max_k] + total);
            sum += v[i];
            total += sum;
        }
        rotate(v.begin() + 1, v.begin() + 2, v.end());
    }
    printf("%lld\n", ans);
    return 0;
}

