#include <bits/stdc++.h>
using namespace std;

class pp {
public:
    int gcd, lst, cnt;
};

int n, t;
const int maxn = 4e5+10;
pp tree[maxn];
int a[maxn];

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

void combine(pp &l, pp &r, pp &ret) {
    ret.gcd = gcd(l.gcd, r.gcd);
    ret.lst = min(l.lst, r.lst);
    ret.cnt = l.lst < r.lst ? l.cnt : r.lst == l.lst ? l.cnt + r.cnt : r.cnt;
}

void build(int node, int st, int en) {
    if (st == en) {
        tree[node].lst = a[st];
        tree[node].cnt = 1;
        tree[node].gcd = a[st];
        return;
    }
    int mid = (st + en) >> 1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    combine(tree[2*node], tree[2*node+1], tree[node]);
}

void query(int node, int st, int en, int l, int r, pp &ret) {
    if (en < l || r < st) {
        ret.gcd = -1;
        return;
    }
    if (l <= st && en <= r) {
        ret = tree[node];
        return;
    }
    pp left, right;
    int mid = (st + en) >> 1;
    query(2*node, st, mid, l, r, left);
    query(2*node+1, mid+1, en, l, r, right);
    if (left.gcd == -1) {
        ret = right;
        return;
    } else if (right.gcd == -1) {
        ret = left;
        return;
    }
    combine(left, right, ret);
}

int main() {
    //freopen("271F.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 0, n-1);
    scanf("%d", &t);
    int l, r; pp ret;
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &l, &r);
        query(1, 0, n-1, l - 1, r - 1, ret);
        if (ret.gcd != ret.lst) {
            printf("%d\n", r - l + 1);
        } else {
            printf("%d\n", r - l + 1 - ret.cnt);
        }
    }
}
