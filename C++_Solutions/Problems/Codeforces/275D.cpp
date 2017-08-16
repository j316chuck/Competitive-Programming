#include <bits/stdc++.h>
using namespace std;

const int maxb = 30;
const int maxn = 1e5 + 5;
int n, m;
//seg stores the & values of all the intervals
int a[maxn], seg[4 * maxn], l[maxn], r[maxn], q[maxn], psum[maxn];

int build(int node, int st, int en) {
    if (st == en) {
        seg[node] = a[st];
        return seg[node];
    }
    int mid = (st + en) >> 1;
    return seg[node] = build(2 * node, st, mid) & build(2 * node + 1, mid + 1, en);
}

int query(int node, int st, int en, int l, int r) {
    if (en < l || r < st) {
        return (1 << 31) - 1;
    }
    if (l <= st && en <= r) {
        return seg[node];
    }
    int mid = (st + en) >> 1;
    return query(2 * node, st, mid, l, r) & query(2 * node + 1, mid + 1, en, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("275D.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> l[i] >> r[i] >> q[i];
    }
    //0 based just like in segment tree how the node is 1 based but the segments are 0 - n-1 based
    for (int b = 0; b <= maxb; b++) {
        memset(psum, 0, sizeof(psum));
        for (int i = 0; i < m; i++) {
            if ((q[i] >> b) & 1) {
                psum[l[i] - 1]++;
                psum[r[i]]--;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) psum[i] += psum[i-1];
            if (psum[i] > 0) {
                a[i] |= (1 << b);
            }
        }
    }
    build(1, 0, n-1);
    for (int i = 0; i < m; i++) {
        if (query(1, 0, n - 1, l[i] - 1, r[i] - 1) != q[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    } cout << '\n';
    return 0;
}
