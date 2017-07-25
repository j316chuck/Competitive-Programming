#include <bits/stdc++.h>
using namespace std;

struct pp {
    long long h, w, s;
};

const int maxn = 1<<20;
const int invalid = -1;
int n; long long h;
vector<pp> v;
pair<long long, long long> dp[maxn];

int main() {
    //freopen("guard.in", "r", stdin);
    //freopen("guard.out", "w", stdout);
    scanf("%d %lld", &n, &h);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &v[i].h, &v[i].w, &v[i].s);
    }
    for (int i = 0; i < (1 << n); i++) {
        dp[i] = {invalid, invalid};
    }
    for (int i = 0; i < n; i++) {
        dp[1 << i].first = v[i].s;
        dp[1 << i].second = v[i].h;
    }
    long long ans = -1;
    for (int b = 1; b < (1 << n); b++) {
        int num_of_bits = __builtin_popcount(b);
        if (num_of_bits == 1) {
            if (dp[b].second >= h) {
                ans = max(ans, dp[b].first);
            }
            continue;
        }
        for (int i = 0; i < n; i++) {
            int m = 1 << i;
            if (b & m) {
                pair<int, int> val = dp[b ^ m];
                val.first = min(v[i].s, val.first - v[i].w);
                if (val.first < 0) {
                    continue;
                }
                if (dp[b].first < val.first) {
                    dp[b].first = val.first;
                    dp[b].second = val.second + v[i].h;
                }
            }
        }
        if (dp[b].second >= h) {
            ans = max(ans, dp[b].first);
        }
    }
    if (ans == invalid){
        printf("Mark is too tall\n");
    } else {
        printf("%lld\n", ans);
    }
}
