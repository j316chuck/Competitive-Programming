#include <bits/stdc++.h>
using namespace std;

struct pp {
    long long val;
    int ind;
    bool operator < (const pp &a) const {
        return val < a.val;
    }
};

const int maxn = 25e4+5;
int n, k;
long long dp[maxn];
long long cost[maxn];
long long a[maxn];
int parent[maxn];
bool mark[maxn];

int main() {
    freopen("hopscotch.in", "r", stdin);
    //freopen("hopscotch.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a+i);
    }
    for (int i = 1; i <= n-1; i++) {
        cost[i] = a[i] + a[i+1];
    }
    priority_queue<pp> pq;
    pq.push({0, 0});
    for (int i = 1; i <= n-1; i++) {
        while (pq.top().ind < i - k) {
            pq.pop();
        }
        dp[i] = cost[i] + pq.top().val;
        parent[i] = pq.top().ind;
        pq.push({dp[i-1], i-1});
    }
    int maxdex = 0;
    for (int i = 1; i <= n-1; i++) {
        //cout << dp[i] << endl;
        if (dp[maxdex] < dp[i]) {
            maxdex = i;
        }
    }
    memset(mark, true, sizeof(mark));
    int x = maxdex;
    while (x != 0) {
        mark[x] = false;
        mark[x+1] = false;
        x = parent[x];
    }
    for (int i = 1; i <= n; i++) {
        //sif (!mark[i]) cout << i << endl;
    }
    long long total = dp[maxdex];
    for (int i = 1; i <= maxdex; i++) {
        if (a[i] > 0 && mark[i]) {
            //cout << a[i] << ' ' << mark[i] << endl;
            total += a[i];
        }
    }
    printf("%lld\n", total);
    return 0;
}

