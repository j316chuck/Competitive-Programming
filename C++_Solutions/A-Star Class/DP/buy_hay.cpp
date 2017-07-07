#include <bits/stdc++.h>
using namespace std;

const int maxn = 55005;
const int INF = 1e9+1;
int old[maxn], cur[maxn];

int main () {
    //freopen("buy_hay.in", "r", stdin);
    int n, h;
    scanf("%d %d", &n, &h);
    pair<int, int> cost[n]; //weight cost
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cost[i].first, &cost[i].second);
    }
    for (int i = 0; i < maxn; i++) {
        old[i] = cur[i] = INF;
    }
    //base cases
    old[0] = 0;
    for (int i = 0; i < maxn; i += cost[0].first) {
        old[i] = i/cost[0].first * cost[0].second;
    }
    for (int i = 1; i < n; i++) {
        cur[0] = 0;
        for (int j = cost[i].first; j < maxn; j++) {
            cur[j] = min(old[j], cur[j-cost[i].first] + cost[i].second);
        }
        copy(cur, cur+maxn, old);
    }
    int ans = INF;
    for (int i = h; i < maxn; i++) {
        ans = min(ans, old[i]);
    }
    printf("%d\n", ans);
    return 0;
}
