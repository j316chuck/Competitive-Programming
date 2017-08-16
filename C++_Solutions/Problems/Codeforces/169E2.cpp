#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, q, pre[maxn], sz[maxn], h[maxn], dist[maxn], counter = -1, chain[maxn], c = 0;
vector<int> graph[maxn];

void dfs(int u, int par) {
    sz[u] = 1;
    pre[u] = ++counter;
    par == 1 ? chain[u] = ++c : chain[u] = chain[par];
    for (int v : graph[u]) {
        if (par != v) {
            h[v] = h[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

struct SegmentTree {
    int lazy[4*maxn] = {0}, seg[4*maxn] = {0};
    void push(int x, int st, int en) {
        if (lazy[x]) {
            seg[x] += (en-st+1)*lazy[x];
            if (st != en) {
                lazy[2*x] += lazy[x];
                lazy[2*x+1] += lazy[x];
            }
            lazy[x] = 0;
        }
    }
    int query_range(int x, int st, int en, int l, int r) {
        if (r < st || en < l) {
            return 0;
        }
        push(x, st, en);
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return query_range(2*x, st, mid, l, r) + query_range(2*x+1, mid+1, en, l, r);
    }
    void update_range(int x, int st, int en, int l, int r, int val) {
        if (r < st || en < l) {
            return;
        }
        push(x, st, en);
        if (l <= st && en <= r) {
            lazy[x] += val;
            push(x, st, en);
            return;
        }
        int mid = (st + en) >> 1;
        update_range(2*x, st, mid, l, r, val);
        update_range(2*x+1, mid+1, en, l, r, val);
        seg[x] = seg[2*x] + seg[2*x+1];
    }
} root, tree;

/*vector<int> bit[maxn];
int sum(int p, int x) {
    int ret = 0;
    while (x < bit[p].size()) {
        ret += bit[p][x];
        x += x & -x;
    }
    return ret;
}

void update(int p, int x, int val) {
    while (x > 0) {
        if (x < bit[p].size()) bit[p][x] += val;
        x -= x & -x;
    }
}*/

int main() {
    //freopen("169E.in", "r", stdin);
    scanf("%d %d", &n, &q);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    h[1] = 0;
    dfs(1, -1);
    /*for (int v : graph[1]) {
        int i = chain[v];
        for (int j = 0; j < sz[v] + 10; j++) {
            bit[i].push_back(0);
        }
    }*/

    for (int i = 0, o, v, x, d; i < q; i++) {
        scanf("%d %d", &o, &v);
        if (o == 0) {
            scanf("%d %d", &x, &d);
            if (v == 1) root.update_range(1, 0, n-1, 0, d, x);
            else {
                if (d < h[v]) {
                    tree.update_range(1, 0, n-1, pre[v]-d, pre[v]+min(sz[v]-1, d), x);
                } else {
                    root.update_range(1, 0, n-1, 0, d-h[v], x);
                    tree.update_range(1, 0, n-1, pre[v]-2*h[v]+d+1, pre[v]+min(sz[v]-1, d), x);
                }
            }
        } else {
            if (v == 1) printf("%d\n", root.query_range(1, 0, n-1, 0, 0));
            else printf("%d\n", tree.query_range(1, 0, n-1, pre[v], pre[v]) + root.query_range(1, 0, n-1, h[v], h[v]));
        }
    }
}

