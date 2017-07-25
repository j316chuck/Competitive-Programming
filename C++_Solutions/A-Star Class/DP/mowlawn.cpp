#include <bits/stdc++.h>
using namespace std;

struct pp {
    int ind;
    long long val;
    bool operator < (const pp &a) const {
        return val < a.val;
    }
};

const int maxn = 1e5+5;
long long dp[maxn];
long long psum[maxn];
long long val[maxn];
priority_queue<pp> pq;
int n, k;

int main() {
    freopen("mowlawn.in", "r", stdin);
    scanf("%d %d", &n, &k);
    long long e;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &e);
        psum[i] = psum[i-1] + e;
    }
    pq.push({-1, 0});
    for (int i = 0; i <= n; i++) {
        while (!pq.empty() && pq.top().ind < i - k - 1) {
            pq.pop();
        }
        dp[i] = pq.top().val + psum[i];
        val[i] = dp[i] - psum[i+1];
        pq.push({i, val[i]});
    }
    printf("%lld\n", dp[n]);
}
