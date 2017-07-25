#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int lazy[4*maxn];
int seg[4*maxn];
int a[maxn];

int query_range(int node, int st, int en, int l, int r) {
    if (lazy[node] != 0) {
        seg[node] = (en - st + 1) - seg[node];
        if (st != en) {
            lazy[2*node] ^= 1;
            lazy[2*node+1] ^= 1;
        }
        lazy[node] = 0;
    }
    if (r < st || en < l) {
        return 0;
    }
    if (l <= st && en <= r) {
        return seg[node];
    }
    int mid = (st + en) >> 1;
    return query_range(2*node, st, mid, l, r) + query_range(2*node+1, mid+1, en, l, r);
}

void update_range(int node, int st, int en, int l, int r) {
    if (lazy[node] != 0) {
        seg[node] = (en - st + 1) - seg[node];
        if (st != en) {
            lazy[2*node] ^= 1;
            lazy[2*node+1] ^= 1;
        }
        lazy[node] = 0;
    }
    if (r < st|| en < l) return;
    if (l <= st && en <= r) {
        seg[node] = (en - st + 1) - seg[node];
        if (st != en) {
            lazy[2*node] ^= 1;
            lazy[2*node+1] ^= 1;
        }
        return;
    }
    int mid = (st + en) >> 1;
    update_range(2*node, st, mid, l, r);
    update_range(2*node+1, mid+1, en, l, r);
    seg[node] = seg[2*node] + seg[2*node+1];
}

int main() {
    //freopen("switching.in", "r", stdin);
    int n, m, q, l, r;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &q, &l, &r);
        l--, r--;
        if (q == 0) update_range(1, 0, n-1, l, r);
        else printf("%d\n", query_range(1, 0, n-1, l, r));
    }
}
