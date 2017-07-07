#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];
int seg[4*maxn];

void build(int node, int st, int en) {
    if (st == en) {
        seg[node] = a[st];
        return;
    }
    int mid = (st + en) >> 1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    seg[node] = seg[2*node] + seg[2*node+1];
}

int query(int node, int st, int en, int l, int r) {
    if (r < st || en < l) {
        return 0;
    }
    if (l <= st && en <= r) {
        return seg[node];
    }

    int mid = (st + en) >> 1;
    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node+1, mid+1, en, l, r);
    return q1 + q2;
}

void update(int node, int st, int en, int id, int val) {
    if (st == en) {
        a[id] += val;
        seg[node] += val;
        return;
    }
    int mid = (st + en) >> 1;
    if (st <= id && id <= mid) {
        update(2*node, st, mid, id, val);
    } else {
        update(2*node+1, mid+1, en, id, val);
    }
    seg[node] = seg[2*node] + seg[2*node+1];
}

int main() {
    freopen("segment_tree.in", "r", stdin);
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &a[i]);
    }
    build(1, 0, n - 1);
    char c; int l, r;
    for (int i = 0; i < q; i++) {
        scanf("%c %d %d ", &c, &l, &r);
        //l and r are 1 indexed while array a is 0 indexed
        if (c == 'q') {
            printf("%d\n", query(1, 0, n-1, l-1, r-1));
        } else {
            update(1, 0, n-1, l-1, r);
        }
    }
}
