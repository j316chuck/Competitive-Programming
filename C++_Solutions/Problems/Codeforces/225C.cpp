#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int a[maxn], l[maxn], r[maxn], h[maxn], counter;
vector<int> graph[maxn]; //1-indexed

void dfs(int u, int par, int x) {
    l[u] = ++counter;
    h[u] = x;
    for (int v : graph[u]) {
        if (v != par)
            dfs(v, u, 1-x);
    }
    r[u] = counter;
}

long long bit[2][maxn];
void update(int t, int x, int val) {
    while (x < maxn) {
        bit[t][x] += val;
        x += x & -x;
    }
}

long long sum(int t, int x) {
    long long ret = 0;
    while (x > 0) {
        ret += bit[t][x];
        x -= x & -x;
    }
    return ret;
}

int main() {
    //freopen("225C.in", "r", stdin);
    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
    }
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1, 0);
    for (int i = 0, q, x, val; i < m; i++) {
        scanf("%d %d", &q, &x);
        if (q == 1) {
            scanf("%d", &val);
            update(h[x], l[x], val); update(h[x], r[x] + 1, -val);
        } else {
            printf("%I64d\n", a[x] + sum(h[x], l[x]) - sum(1 - h[x], l[x]));
        }
    }
}
