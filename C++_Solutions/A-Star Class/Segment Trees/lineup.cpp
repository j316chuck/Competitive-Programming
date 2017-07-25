#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
const int INF = 1e9+1;
int a[maxn];
pair<int, int> seg[4*maxn]; //holds max then min 1 index

void build(int node, int st, int en) {
    if (st == en) {
        seg[node] = {a[st], a[st]};
        return;
    }
    int mid = (st + en) >> 1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    seg[node].first = max(seg[2*node].first, seg[2*node+1].first);
    seg[node].second = min(seg[2*node].second, seg[2*node+1].second);
}


pair<int, int> query(int node, int st, int en, int l, int r) {
    if (l > en || r < st) {
        return {-INF, INF};
    }
    if (l <= st && en <= r) {
        return seg[node];
    }
    int mid = (st + en) >> 1;
    pair<int, int> q1 = query(2*node, st, mid, l, r);
    pair<int, int> q2 = query(2*node+1, mid+1, en, l, r);
    return {max(q1.first, q2.first), min(q1.second, q2.second)};
}


int main() {
    //freopen("lineup.in", "r", stdin);
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }
    build(1, 0, n-1);
    /*for (int i = 1; i < 2*n; i++) {
        cout << seg[i].first << ' '  << seg[i].second << endl;
    }*/
    int l, r; pair<int, int> ret;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        l--, r--;
        ret = query(1, 0, n-1, l, r);
        printf("%d\n", ret.first - ret.second);
    }
    return 0;
}
