#include <bits/stdc++.h>
using namespace std;

struct pp {
    int l, r, k, ind;
    bool operator < (const pp &a) const {
        return k < a.k;
    }
};

const int maxn = 3e5+5;
int n, q;
pair<int, int> a[maxn];
int seg[4 * maxn];
int ans[maxn];

void build(int x, int st, int en) {
    if (st == en) {
        seg[x] = 1;
        return;
    }
    int mid = (st + en) >> 1;
    build(2*x, st, mid);
    build(2*x+1, mid+1, en);
    seg[x] = seg[2*x] + seg[2*x+1];
}

void update(int x, int st, int en, int q) {
    if (st == en) {
        seg[x] = 0;
        return;
    }
    int mid = (st + en) >> 1;
    if (q <= mid) {
        update(2*x, st, mid, q);
    } else {
        update(2*x+1, mid+1, en, q);
    }
    seg[x] = seg[2*x] + seg[2*x+1];
}

int query(int x, int st, int en, int l, int r) {
    if (en < l || r < st) {
        return 0;
    }
    if (l <= st && en <= r) {
        return seg[x];
    }
    int mid = (st + en) >> 1;
    return query(2*x, st, mid, l, r) + query(2*x+1, mid+1, en, l, r);
}


int main() {
    //freopen("kquery.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + n);
    scanf("%d ", &q);
    vector<pp> v(q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &v[i].l, &v[i].r, &v[i].k);
        v[i].l--; v[i].r--;
        v[i].ind = i;
    }
    build(1, 0, n-1);
    sort(v.begin(), v.end());
    int j = 0;
    for (int i = 0; i < q; i++) {
        int x = v[i].ind;
        while (j < n && a[j].first <= v[i].k) {
            update(1, 0, n-1, a[j].second);
            j++;
        }
        ans[x] = query(1, 0, n-1, v[i].l, v[i].r);
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }
}
