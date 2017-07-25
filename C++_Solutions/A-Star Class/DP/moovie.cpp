#include <bits/stdc++.h>
using namespace std;

int n, max_len, sz;
vector < vector<int> > showtimes;
vector<int> duration;
int dp[1 << 20];

int main() {
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
    scanf("%d %d", &n, &max_len);
    duration.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &duration[i], &sz);
        vector<int> v(sz);
        for (int i = 0; i < sz; i++) {
            scanf("%d ", &v[i]);
        }
        showtimes.push_back(v);
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int b = 0; b < (1 << n); b++) {
        for (int k = 0; k < n; k++) {
            if (b & 1 << k) {
                int last_valid = dp[b ^ (1 << k)];
                if (last_valid == -1) {
                    continue;
                }
                int index = upper_bound(showtimes[k].begin(), showtimes[k].end(), last_valid)
                            - showtimes[k].begin() - 1;
                if (index == -1) continue;
                else if (index == showtimes[k].size() - 1) {
                    if (showtimes[k][index] + duration[k] >= last_valid) {
                        dp[b] = max(dp[b], showtimes[k][index] + duration[k]);
                    }
                } else {
                    dp[b] = max(dp[b], showtimes[k][index] + duration[k]);
                }
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < (1 << n); i++) {
        if (dp[i] >= max_len) {
            ans == -1 ? ans = __builtin_popcount(i) : ans = min(ans, __builtin_popcount(i));
        }
    }
    printf("%d\n", ans);
    return 0;
}
