#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
struct SegmentTree {
    int seg[4 * maxn];
    void init() {
        memset(seg, 0, sizeof(seg));
    }
    int query(int x, int st, int en, int l, int r) {
        if (r < l) return 0;
        if (r < st || en < l) {
            return 0;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return max(query(2 * x, st, mid, l, r), query(2 * x + 1, mid + 1, en, l, r));
    }
    void update(int x, int st, int en, int id, int val) {
        if (st == en) {
            seg[x] = val;
            return;
        }
        int mid = (st + en) >> 1;
        if (id <= mid) {
            update(2 * x, st, mid, id, val);
        } else {
            update(2 * x + 1, mid + 1, en, id, val);
        }
        seg[x] = max(seg[2 * x], seg[2 * x + 1]);
    }
} dp;

struct pp {
    int id, x, h;
    bool operator < (const pp &a) const {
        return x < a.x;
    }
};

int ret[maxn], sorted[maxn];
vector<pp> v;

int main() {
    //freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].h;
        v[i].id = i, sorted[i] = v[i].x;
        dp.update(1, 0, n - 1, i, i);
    }
    sort(sorted, sorted + n);
    sort(v.begin(), v.end());
    ret[v[n - 1].id] = 1;
    int x, d;
    for (int i = n - 2; i >= 0; i--) {
        d = v[i].x + v[i].h;
        x = dp.query(1, 0, n - 1, i, (lower_bound(sorted, sorted + n, d) - sorted - 1));
        ret[v[i].id] = x - i + 1;
        dp.update(1, 0, n - 1, i, x);
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << ' ';
    } cout << endl;
}

