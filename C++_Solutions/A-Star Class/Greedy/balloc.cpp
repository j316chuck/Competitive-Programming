#include <bits/stdc++.h>
using namespace std;

struct pp {
    int s, e;
    bool operator < (const pp &a) const {
        return e < a.e || a.e == e && s > a.s;
    }
};

const int maxn = 1e5+5;
const int INF = 1e9+1;
int n, m;
int a[maxn];
int seg[4*maxn];
int lazy[4*maxn];

void build(int node, int st, int en) {
    if (st == en) {
        seg[node] = a[st];
        return;
    }
    int mid = (st + en) >> 1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    seg[node] = min(seg[2*node], seg[2*node+1]);
}

int query_range(int node, int st, int en, int l, int r) {
    if (lazy[node]) {
        seg[node] -= lazy[node];
        if (st != en) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (en < l || r < st) {
        return INF;
    }
    if (l <= st && en <= r) {
        return seg[node];
    }
    int mid = (st + en) >> 1;
    int q1 = query_range(2*node, st, mid, l, r);
    int q2 = query_range(2*node+1, mid+1, en, l, r);
    return min(q1, q2);
}

void update_range(int node, int st, int en, int l, int r, int val) {
    if (lazy[node]) {
        seg[node] -= lazy[node];
        if (st != en) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (en < l || r < st) {
        return;
    }
    if (l <= st && en <= r) {
        seg[node] -= val;
        if (st != en) {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    int mid = (st + en) >> 1;
    update_range(2*node, st, mid, l, r, val);
    update_range(2*node+1, mid+1, en, l, r, val);
    seg[node] = min(seg[2*node], seg[2*node+1]);
}

int main() {
    freopen("balloc.in", "r", stdin);
    scanf("%d %d", &n, &m);
    memset(seg, 63, sizeof(seg));
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    vector<pp> v(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v[i].s, &v[i].e);
        v[i].s--; v[i].e--;
    }
    sort(v.begin(), v.end());
    build(1, 0, n-1);
    int j = 0, ans = 0;
    for (int i = 0; i < maxn; i++) {
        while (j < m && v[j].e == i) {
            if (query_range(1, 0, n-1, v[j].s, v[j].e) > 0) {
                //cout << query_range(1, 0, n-1, v[j].s, v[j].e)<< ' ' << v[j].s + 1 << ' ' << v[j].e + 1 << endl;
                update_range(1, 0, n-1, v[j].s, v[j].e, 1);
                ans++;
            }
            j++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
