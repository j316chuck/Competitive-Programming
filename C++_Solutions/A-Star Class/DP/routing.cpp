#include <bits/stdc++.h>
using namespace std;

const int maxn = 40005;
const int maxm = 1e5+5;
long long int l[maxn], r[maxn];
pair<int, int> route[maxm];
long long dp_left[maxn], dp_right[maxn];

int main() {
    freopen("routing.in", "r", stdin);
    int n, m, k, u, v;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &l[i]);
        dp_left[i] = l[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%lld", &r[i]);
        dp_right[i] = r[i];
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        route[i] = make_pair(u, v);
    }
    sort(route, route + k);
    for (int i = k - 1; i >= 0; i--) {
        int u = route[i].first;
        int v = route[i].second;
        long long ri = dp_left[u] + r[v];
        long long le = dp_right[v] + l[u];
        dp_left[u] = max(dp_left[u], le);
        dp_right[v] = max(dp_right[v], ri);
    }
    printf("%lld", max(*max_element(dp_left, dp_left+n), *max_element(dp_right, dp_right+m)));
}
