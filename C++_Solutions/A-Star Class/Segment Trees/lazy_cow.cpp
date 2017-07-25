#include <bits/stdc++.h>
using namespace std;

struct pp {
    int bot, top, x, grass;
    bool operator < (const pp &a) const {
        return x < a.x;
    }
};
int n, k;

const int maxn = 1e5+5;
const int INF = 1e9+1;
int mn[4*maxn];
int mx[4*maxn];
int lazy[4*maxn];
int seg[4*maxn];
vector<int> ys;
vector<pp> v;

void build(int node, int st, int en) {
    if (st == en) {
        mn[node] = ys[st];
        mx[node] = ys[st];
        return;
    }
    int mid = (st + en) >> 1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    mn[node] = min(mn[2*node], mn[2*node+1]);
    mx[node] = max(mx[2*node], mx[2*node+1]);
    //cout << node << ' '  << st << ' ' << en << ' ' << mn[node] << ' ' << mx[node] << endl;
}

void update_range(int node, int st, int en, int l, int r, int val) {
    if (lazy[node]) {
        seg[node] += lazy[node];
        if (st != en) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (mx[node] < ys[l] || mn[node] > ys[r]) {
        return;
    }
    if (mn[node] <= ys[l] && ys[r] <= mx[node]) {
        seg[node] += val;
        if (st != en) {
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }
    int mid = (st + en) >> 1;
    update_range(2*node, st, mid, l, r, val);
    update_range(2*node+1, mid+1, en, l, r, val);
    seg[node] = max(seg[2*node], seg[2*node+1]);
}

int query_range(int node, int st, int en, int l, int r) {
    if (lazy[node]) {
        seg[node] += lazy[node];
        if (st != en) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (mx[node] < ys[l] || mn[node] > ys[r]) {
        return 0;
    }
    if (mx[l] <= ys[st] && mn[en <= r) {
        return seg[node];
    }
    int mid = (st + en) >> 1;
    int q1 = query_range(2*node, st, mid, l, r);
    int q2 = query_range(2*node+1, mid+1, en, l, r);
    return max(q1, q2);
}

int main() {
    freopen("lazy_cow.in", "r", stdin);
    scanf("%d %d", &n, &k);
    int g, x, y;
    for (int i = 0; i < maxn; i++) {
        mn[i] = INF;
        mx[i] = -INF;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &g, &x, &y);
        int xl = x - k;
        int xr = x + k;
        int llx = 2 * (xl - y) - 1;
        int lly = 2 * (xl + y) - 1;
        int urx = 2 * (xr - y) + 1;
        int ury = 2 * (xr + y) + 1;
        v.push_back({lly, ury, llx, g});
        v.push_back({lly, ury, urx, -g});
        ys.push_back(ury); ys.push_back(lly);
    }
    sort(v.begin(), v.end());
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    /*for (int i = 0; i < ys.size(); i++) {
        cout << ys[i] << ' ';
    } cout << endl;*/
    int num = ys.size();
    build(1, 0, num-1);
    /*for (int i = 1; i <= n; i++) {
        cout << mn[i] << ' '  << mx[i] << endl;
    }*/
    int ret = -1, l, r;
    for (int i = 0; i < v.size(); i++) {
        //l = lower_bound(ys.begin(), ys.end(), v[i].bot) - ys.begin();
        //r = lower_bound(ys.begin(), ys.end(), v[i].top) - ys.begin();
        update_range(1, 0, num-1, v[i].bot, v[i].top, v[i].grass);
        ret = max(ret, query_range(1, 0, num-1, 0, num-1));
    }
    printf("%d\n", ret);
}
