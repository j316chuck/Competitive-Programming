#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
const long long INF = 1LL << 60;
int n, q;
long long a[maxn];
long long rmq[4*maxn];
long long lazy[4*maxn];

void build(int node, int st, int en) {
    if (st == en) {
        rmq[node] = a[st];
        return;
    }
    int mid = (st + en) >> 1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    rmq[node] = min(rmq[2*node], rmq[2*node+1]);
}

long long rmq_query(int node, int st, int en, int l, int r) {
    if (lazy[node]) {
        rmq[node] += lazy[node];
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
    rmq[node] = min(rmq[2*node], rmq[2*node+1]);
}

int main() {
    //freopen("input.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", a + i);
    }
    build(1, 0, n - 1);

    char s[1024]; int l, r; long long val;
    scanf("%d ", &q);
    for (int i = 0; i < q; i++) {
        gets(s);
        if (sscanf(s, "%d %d %I64d", &l, &r, &val) == 3) {
            if (l <= r) {
                update_range(1, 0, n - 1, l, r, val);
            } else {
                update_range(1, 0, n - 1, l, n - 1, val);
                update_range(1, 0, n - 1, 0, r, val);
            }
        } else {
            if (l <= r) {
                printf("%I64d\n", rmq_query(1, 0, n - 1, l, r));
            } else {
                printf("%I64d\n", min(rmq_query(1, 0, n - 1, l, n - 1), rmq_query(1, 0, n - 1, 0, r)));
            }
        }
    }
}

