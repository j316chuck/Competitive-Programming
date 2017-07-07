#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], b[maxn];
int tin = 0;
pair<int, int> tree[4*maxn]; //stores time then difference

void update(int node, int st, int en, int l, int r, int diff) {
    if (en < l || st > r) {
        return;
    }
    if (l <= st && en <= r) {
        tree[node].first = tin;
        tree[node].second = diff;
        return;
    }
    int mid = (st + en) >> 1;
    update(2*node, st, mid, l, r, diff);
    update(2*node+1, mid+1, en, l, r, diff);
}

pair<int, int> query (int node, int st, int en, int x) {
    if (st == en) {
        return tree[node];
    }
    int mid = (st + en) >> 1;
    pair<int, int> p;
    if (x <= mid) {
        p = query(2*node, st, mid, x);
    } else {
        p = query(2*node+1, mid+1, en, x);
    }
    return p.first < tree[node].first ? tree[node] : p;
}

int main() {
    //freopen("292E.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", b + i);
    }
    int len, sa, sb, diff, type, x;
    for (int i = 0; i < m; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d%d", &sa, &sb, &len);
            sa--; sb--;
            diff = sa - sb;
            ++tin;
            update(1, 0, n-1, sb, sb + len - 1, diff);
        } else {
            scanf("%d", &x);
            x--;
            pair<int, int> p = query(1, 0, n-1, x);
            if (p.first == 0)  printf("%d\n", b[x]);
            else printf("%d\n", a[x + p.second]);
        }
    }
    return 0;
}




