#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int maxk = 10;
long long ans = 1e17 + 5;
long long dp[maxn][maxk];
long long psum[maxn];

int main() {
    freopen("cbarn.in", "r", stdin);
    //freopen("cbarn.out", "w", stdout);
    int n, max_k;
    scanf("%d %d", &n, &max_k);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int ii = 0; ii < n; ii++) {
        memset(dp, 0x3f, sizeof(dp));
        psum[0] = 0;
        dp[0][1] = 0;
        for (int k = 1; k <= n; k++) {
            psum[k] = psum[k - 1] + v[k] * k;
            dp[k][1] = dp[k - 1][1] + (k - 1) * v[k];
        }
        for (int k = 2; k <= max_k; k++) {
            for (int i = k; i <= n; i++) {
                dp[i][k] = dp[i - 1][k - 1];
                long long sum = v[i];
                long long total = 0;
                for (int j = i - 1; j >= 1; j--) {
                    total += sum;
                    sum += v[j];
                    dp[i][k] = min(dp[i][k], dp[j][k] + total);
                }
                cout << dp[i][k] << ' ';
            } cout << endl;
            ans = min(ans, dp[n][k]);
        }
        rotate(v.begin() + 1, v.begin() + 2, v.end());
    }
    printf("%lld\n", ans);
    return 0;
}
