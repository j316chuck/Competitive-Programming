#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const long long INF = 1LL << 60;
long long a[maxn];
long long seg[4*maxn];
long long rmq[4*maxn];
long long lazy[4*maxn];

void build(int node, int st, int en) {
    if (st == en) {
        seg[node] = a[st];
        rmq[node] = a[st];
        return;
    }
    int mid = (st + en) >> 1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    seg[node] = seg[2*node] + seg[2*node+1];
    rmq[node] = min(rmq[2*node], rmq[2*node+1]);
}

long long seg_query(int node, int st, int en, int l, int r) {
    if (lazy[node]) {
        seg[node] += ((long long) (en - st + 1)) * lazy[node];
        rmq[node] += lazy[node];
        if (st != en) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
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
    return seg_query(2*node, st, mid, l, r) + seg_query(2*node+1, mid+1, en, l, r);
}

long long rmq_query(int node, int st, int en, int l, int r) {
    if (lazy[node]) {
        rmq[node] += lazy[node];
        seg[node] += ((long long) (en - st + 1)) * lazy[node];
        if (st != en) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (r < st || en < l) {
        return INF;
    }
    if (l <= st && en <= r) {
        return rmq[node];
    }
    int mid = (st + en) >> 1;
    return min(rmq_query(2*node, st, mid, l, r), rmq_query(2*node+1, mid+1, en, l, r));
}

void update_range(int node, int st, int en, int l, int r, long long val) {
    if (lazy[node]) {
        seg[node] += ((long long) (en - st + 1)) * lazy[node];
        rmq[node] += lazy[node];
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
        seg[node] += ((long long) (en - st + 1)) * val;
        rmq[node] += val;
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
    rmq[node] = min(rmq[2*node], rmq[2*node+1]);
}

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%lld ", a + i);
    }
    memset(rmq, 0x7f, sizeof(rmq));
    build(1, 0, n-1);
    char s; long long c = -1; int a, b;
    for (int i = 0; i < q; i++) {
        scanf("%c %d %d ", &s, &a, &b);
        if (s == 'P') {
            scanf("%lld ", &c);
            update_range(1, 0, n-1, a-1, b-1, c);
        } else if (s == 'S') {
            printf("%lld\n", seg_query(1, 0, n-1, a-1, b-1));
        } else {
            printf("%lld\n", rmq_query(1, 0, n-1, a-1, b-1));
        }
    }
    return 0;
}

