#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+5;
vector<int> graph[maxn];
int n, q, l[maxn], r[maxn], counter = -1;
int seg[4*maxn];
int lazy[4*maxn];
int tree[4*maxn];

void push(int x, int st, int en) {
    if (lazy[x]) {
        seg[x] = max(seg[x], lazy[x]);
        if (st != en) {
            lazy[2*x] = max(lazy[2*x], lazy[x]);
            lazy[2*x+1] = max(lazy[2*x+1], lazy[x]);
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
    return max(query_range(2*x, st, mid, l, r), query_range(2*x+1, mid+1, en, l, r));
}

void update_range(int x, int st, int en, int l, int r, int val) {
    push(x, st, en);
    if (r < st || en < l) {
        return;
    }
    if (l <= st && en <= r) {
        lazy[x] = val;
        push(x, st, en);
        return;
    }
    int mid = (st + en) >> 1;
    update_range(2*x, st, mid, l, r, val);
    update_range(2*x+1, mid+1, en, l, r, val);
}

void update(int x, int st, int en, int l, int val) {
    if (st == en) {
        tree[x] = val;
        return;
    }
    int mid = (st + en) >> 1;
    if (l <= mid) {
        update(2*x, st, mid, l, val);
    } else {
        update(2*x+1, mid+1, en, l, val);
    }
    tree[x] = max(tree[2*x], tree[2*x+1]);
}

int query(int x, int st, int en, int l, int r) {
    if (r < st || en < l) {
        return -1;
    }
    if (l <= st && en <= r) {
        return tree[x];
    }
    int mid = (st + en) >> 1;
    return max(query(2*x, st, mid, l, r), query(2*x+1, mid+1, en, l, r));
}

int dfs(int u, int par) {
    l[u] = ++counter;
    for (int v : graph[u]) {
        if (v != par) dfs(v, u);
    }
    r[u] = counter;
}

int main() {
    //freopen("200D.in", "r", stdin);
    scanf("%d", &n);
    int u, v, o;
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, -1);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &o, &v);
        v--;
        if (o == 1) {
            update_range(1, 0, n-1, l[v], r[v], i);
        } else if (o == 2) {
            update(1, 0, n-1, l[v], i);
        } else {
            bool ret = query_range(1, 0, n-1, l[v], l[v]) > query(1, 0, n-1, l[v], r[v]);
            printf(ret ? "1\n" : "0\n");
        }
    }
}

