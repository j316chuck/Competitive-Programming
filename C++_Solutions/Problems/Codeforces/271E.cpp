/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;

const int maxn = 1e5 + 5;
const pair<int, int> beg = {0, -1};
const pair<int, int> fail = {-1, -1};
long long arr[maxn], sorted[maxn], pre[maxn];
int n, d;

struct RMQ {
    vector< pair<int, int> > seg(beg, 4 * maxn);
    /*void init() {
        pair<int, int> mp = {0, -1};
        fill(seg, seg + 4 * maxn, mp);
    }*/
    void update(int x, int st, int en, int id, pair<int, int> val) {
        if (st == en) {
            seg[x] = max(seg[x], val);
            return;
        }
        int mid = (st + en) >> 1;
        if (id <= mid) {
            update(2 * x, st, mid, id, val);
        } else {
            update(2 * x + 1, mid + 1 , en, id, val);
        }
        seg[x] = max(seg[2 * x], seg[2 * x + 1]);
    }
    pair<int, int> query(int x, int st, int en, int l, int r) {
        if (r < l) return fail;
        if (r < st || en < l) {
            return fail;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return max(query(2 * x, st, mid, l, r), query(2 * x + 1, mid + 1, en, l, r));
    }
} rmq;

int below(long long val) {
    return (upper_bound(sorted, sorted + n, val) - sorted) - 1;
}
int above(long long val) {
    return lower_bound(sorted, sorted + n, val) - sorted;
}


int main() {
    Rd("input.in");
    //ios_base::sync_with_stdio(0);
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    rmq.init();
    sort(sorted, sorted + n);
    pair<int, int> ans = {0, -1};
    int l, r; memset(pre, -1, sizeof(pre)); pair<int, int> ret;
    for (int i = 0; i < n; i++) {
        l = below(arr[i] - d);
        r = above(arr[i] + d);
        ret = max(rmq.query(1, 0, n - 1, 0, l), rmq.query(1, 0, n - 1, r, n - 1));
        if (ret.first == -1) continue;
        pre[i] = ret.second;
        ret.first++;
        ret.second = i;
        ans = max(ans, ret);
        //cout << ret.first << ' ' << ret.second << ' ' << l << ' ' << r << " "<< rmq.query(1, 0, n - 1, 0, l) << ' ' << rmq.query(1, 0, n - 1, r, n - 1) << endl;
        rmq.update(1, 0, n - 1, (lower_bound(sorted, sorted + n, arr[i]) - sorted), ret);
        //cout << rmq.query(1, 0, n - 1, 0, (lower_bound(sorted, sorted + n, arr[i]) - sorted)) << ' ' << ret << ' ' << (lower_bound(sorted, sorted + n, arr[i]) - sorted) << endl;
    }
    int c = ans.second;
    vector<int> v;
    while (c != -1) {
        v.push_back(c);
        c = pre[c];
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] + 1 << ' ';
    } cout << endl;
    return 0;
}




