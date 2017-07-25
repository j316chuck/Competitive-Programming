#include <bits/stdc++.h>
using namespace std;

const int maxn = 705;
const int INF = 1e9+1;
int n, k;
long long psum[maxn][maxn];

int main() {
    //freopen("triangle.in", "r", stdin);
    scanf("%d %d", &n, &k);
    memset(psum, 0, sizeof(psum));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%lld", &psum[i][j]);
            psum[i][j] += psum[i][j-1];
        }
    }

    long long ans = -INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            long long sum = 0, div = 0;
            for (int len = 1; len <= 2 * k && len + i - 1 <= n; len++) {
                sum += psum[len+i-1][len+j-1] - psum[len+i-1][j-1];
                div += len;
                if (len >= k) {
                    ans = max(ans, (long long) sum/div);
                }
            }
            sum = 0, div = 0;
            for (int len = 1; len <= 2 * k && (i - len + 1) >= j && j - len >= 0; len++) {
                sum += psum[i - len + 1][j] - psum[i - len + 1][j - len];
                div += len;
                if (len >= k) {
                    ans = max(ans, (long long) sum/div);
                }
            }
        }
    }
    printf("%lld\n", ans);
}
