#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, q, pre[maxn], sz[maxn], h[maxn], counter = -1;
vector<int> graph[maxn];

void dfs(int u, int par) {
    sz[u] = 1;
    pre[u] = ++counter;
    for (int v : graph[u]) {
        if (par != v) {
            h[v] = h[u] + 1;
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

int lazy[4*maxn], seg[4*maxn];
int query_range(int node, int st, int en, int l, int r) {
    if (r < st || en < l) {
        return 0;
    }
    if (lazy[node]) {
        seg[node] += (en - st + 1) * lazy[node];
        if (st != en) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (l <= st && en <= r) {
        return seg[node];
    }
    int mid = (st + en) >> 1;
    int q1 = query_range(2*node, st, mid, l, r);
    int q2 = query_range(2*node+1, mid+1, en, l, r);
    return q1 + q2;
}

void update_range(int node, int st, int en, int l, int r, int val) {
    if (lazy[node]) {
        seg[node] += (en - st + 1) * lazy[node];
        if (st != en) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (r < st || en < l) {
        return;
    }
    if (l <= st && en <= r) {
        seg[node] += (en - st + 1) * val;
        if (st != en) {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    int mid = (st + en) >> 1;
    update_range(2*node, st, mid, l, r, val);
    update_range(2*node+1, mid+1, en, l, r, val);
    seg[node] = seg[2*node] + seg[2*node+1];
}


int lazy_root[4*maxn], root[4*maxn];
void push_root(int x, int st, int en) {
    if (lazy_root[x]) {
        root[x] += (en-st+1) * lazy_root[x];
        if (st != en) {
            lazy_root[2*x+1] += lazy_root[x];
            lazy_root[2*x] += lazy_root[x];
        }
        lazy_root[x] = 0;
    }
}

void update_root(int x, int st, int en, int l, int r, int val) {
    push_root(x, st, en);
    if (r < st || en < l) {
        return;
    }
    if (l <= st && en <= r) {
        lazy_root[x] += val;
        push_root(x, st, en);
        return;
    }
    int mid = (st + en) >> 1;
    update_root(2*x, st, mid, l, r, val);
    update_root(2*x+1, mid+1, en, l, r, val);
    root[x] = root[2*x] + root[2*x+1];
}

int query_root(int x, int st, int en, int l, int r) {
    push_root(x, st, en);
    if (r < st || en < l) {
        return 0;
    }
    if (l <= st && en <= r) {
        return root[x];
    }
    int mid = (st + en) >> 1;
    return query_root(2*x, st, mid, l, r) + query_root(2*x+1, mid+1, en, l, r);
}

int main() {
    freopen("169E.in", "r", stdin);
    scanf("%d %d", &n, &q);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    h[1] = 0;
    dfs(1, -1);
    for (int i = 0, o, v, x, d; i < q; i++) {
        scanf("%d %d", &o, &v);
        if (o == 0) {
            scanf("%d %d", &x, &d);
            if (v == 1) update_root(1, 0, n-1, 0, d, x);
            else {
                int l = pre[v]-min(h[v]-1, d);
                int r = pre[v] + min(sz[v]-1, d);
                update_range(1, 0, n-1, l, r, x);
                if (h[v] <= d) {
                    d -= h[v];
                    update_root(1, 0, n-1, 0, d, x);
                }
            }
        } else {
            if (v == 1) printf("%d\n", query_root(1, 0, n-1, 0, 0));
            else printf("%d\n", query_range(1, 0, n-1, pre[v], pre[v]) + query_root(1, 0, n-1, h[v], h[v]));
        }
    }
}
