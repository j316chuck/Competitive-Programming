#include <bits/stdc++.h>
using namespace std;

struct pp {
    long long val;
    int index;
    bool operator < (const pp &a) const {
        return val < a.val;
    }
};

const int maxn = 250005;
int n;
long long k;
long long psum[maxn];
long long dp[maxn];

int main() {
    freopen("hopscotch.in", "r", stdin);
    scanf("%d %lld", &n, &k);
    vector<long long> v(n+1);
    v[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &v[i]);
        psum[i] = psum[i-1] + (v[i] >= 0 ? v[i] : 0);
        v[i] = v[i] >= 0 ? 0 : v[i];
    }
    dp[0] = 0;
    priority_queue<pp> pq;
    long long best = 0;
    for (int i = 1; i <= n; i++) {
        while (!pq.empty() && pq.top().index + k < i) {
            pq.pop();
        }
        long long top_val = 0;
        if (!pq.empty()) {
            top_val = pq.top().val;
        }
        dp[i] = top_val + v[i] + v[i-1];
        long long return_here = dp[i] + psum[i];
        if (v[i-1] < 0) {
            return_here -= v[i-1];
        }
        if (best < return_here) {
            best = return_here;
        }
        pq.push({dp[i-1], i-1});
    }
    printf("%lld\n", best);
}
