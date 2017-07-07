#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
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
    seg[node] = seg[2*node] + seg[2*node+1];
}

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

int main() {
    freopen("segment_tree.in", "r", stdin);
    int n = 100;
    for (int i = 0; i < n; i++) {
        a[i] = 1;
    }
    build(1, 0, n-1);
    memset(lazy, 0, sizeof(lazy));
	cout << query_range(1, 0, n-1, 0, n-1) << endl;
    update_range(1, 0, n-1, 0, 6, 5); // Increment range [0, 6] by 5. here 0, N-1 represent the current range.
	cout << query_range(1, 0, n-1, 0, n-1) << endl;
	cout << query_range(1, 0, n-1, 0, 6) << endl;
	cout << query_range(1, 0, n-1, 0, 8) << endl;
	update_range(1, 0, n-1, 7, 10, 12); // Incremenet range [7, 10] by 12. here 0, N-1 represent the current range.
	cout << query_range(1, 0, n-1, 7, 7) << endl;
	update_range(1, 0, n-1, n-1, n-1, 100); // Increment range [10, N-1] by 100. here 0, N-1 represent the current range.
    cout << query_range(1, 0, n-1, n-3, n-1) << endl;
}
