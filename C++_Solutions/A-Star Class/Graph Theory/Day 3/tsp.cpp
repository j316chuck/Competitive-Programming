#include <bits/stdc++.h>
using namespace std;

const short INF = 1<<15;
const int maxn = 19;
const int lim = 1 << 19;
short dist[maxn][maxn];
short dp[lim][maxn];
int n, m;

int tsp() {
    //memset(dp, 63, sizeof(dp));
    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < maxn; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }
    int lim = 1 << n, old_mask;
    for (int mask = 0; mask < lim; mask++) {
        for (int last = 0; last < n; last++) {
            if (mask & (1 << last) == 0) {
                continue;
            } //cout << mask << ' ' << (1 << last) << endl;
            for (int cur = 0; cur < n; cur++) {
                if (mask & (1 << cur) == 0) continue;
                if (dist[last][cur] == INF) continue;
                old_mask = mask ^ (1 << cur);
                if (dp[old_mask][last] == INF) continue;
                if (dp[mask][cur] < dp[old_mask][last] + dist[last][cur]) {
                    dp[mask][cur] = dp[old_mask][last] + dist[last][cur];
                }
                //dp[mask][cur] = min(dp[mask][cur], dp[old_mask][last] + dist[last][cur]);
            }
        }
    }
    lim--;
    short m = INF;
    for (int i = 0; i < n; i++) {
        m = min(m, dp[lim][i]);
    }
    return m;
}

int main() {
    freopen("tsp.in", "r", stdin);
    //memset(dist, 63, sizeof(dist));
    for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++) dist[i][j] = INF;
    scanf("%d %d", &n, &m);
    //cout << n << ' ' << m << endl;
    int u, v; short w;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }
    int ret = tsp();
    (ret >= INF) ? printf("IMPOSSIBLE\n") : printf("%d\n", ret);
}

