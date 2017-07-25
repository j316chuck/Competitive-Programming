#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
const int maxm = 17;
int n, k;
int cost[maxm];
int val[maxn];
vector<int> psum;
int dp[1<<maxm];

int main() {
    freopen("no_change.in", "r", stdin);
    scanf("%d %d", &k, &n);
    psum.resize(n+1); psum[0] = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", &cost[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
        psum[i+1] = psum[i] + val[i];
    }
    int ans = -1;
    for (int b = 1; b <= (1 << k); b++) {
        int rem = 0, best = 0;
        for (int i = 0; i < k; i++) {
            int m = (1 << i);
            if (m & b) {
                int last = upper_bound(psum.begin(), psum.end(), psum[dp[b^m]] + cost[i]) - psum.begin() - 1;
                best = max(best, last);
            } else {
                rem += cost[i];
            }
        }
        dp[b] = best;
        if (dp[b] == n) {
            ans = max(ans, rem);
        }
    }
    printf("%d\n", ans);
}
