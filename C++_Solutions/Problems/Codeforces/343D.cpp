#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
struct SegmentTree {
    long long seg[4 * maxn];
    void init() {
        memset(seg, 0, sizeof(seg));
    }
    long long query(int x, int st, int en, int l, int r) {
        if (r < st || en < l) {
            return 0;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return max(query(2 * x, st, mid, l, r), query(2 * x + 1, mid + 1, en, l, r));
    }
    void update(int x, int st, int en, int id, long long val) {
        if (st == en) {
            seg[x] = max(seg[x], val);
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

const double PI = acos(-1.0);
map<long long, int> mp;
int counter;

int main() {
    //freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    vector<long long> v(n);
    long long r, h;
    for (int i = 0; i < n; i++) {
        cin >> r >> h;
        v[i] = r * r * h;
        mp[v[i]] = 1;
    }
    for (auto &x : mp) {
        x.second = ++counter;
    }
    long long x;
    for (int i = 0; i < n; i++) {
        x = dp.query(1, 0, n, 0, mp[v[i]] - 1) + v[i];
        dp.update(1, 0, n, mp[v[i]], x);
    }
   // cout.precision(22);
    cout << setprecision(22) << PI * dp.query(1, 0, n, 0, n) << endl;
    //cout << setprecision(22) <<
}

