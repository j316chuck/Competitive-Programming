#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int tree[8*maxn][21]; //tree[i][j] stores the number of bits of j at node i (which stands for an interval)
int n, m, t, a[maxn], lazy[8*maxn]; //lazy stores the p value that is xor to the ith index;

void build(int x, int st, int en) {
    if (st == en) {
        for (int i = 0; i <= 20; i++) {
            tree[x][i] = bool (a[st] & (1 << i));
        }
        return;
    }
    int mid = (st + en) >> 1;
    build(2*x, st, mid);
    build(2*x+1, mid+1, en);
    for (int i = 0; i <= 20; i++) {
        tree[x][i] = tree[2*x][i] + tree[2*x+1][i];
    }
}

void push(int x, int l, int r) {
    if (lazy[x]) {
        for (int i = 0; i <= 20; i++) {
            if (lazy[x] & (1 << i)) {
                tree[x][i] = (r - l + 1) - tree[x][i];
            }
        }
        lazy[2*x+1] ^= lazy[x];
        lazy[2*x] ^= lazy[x];
        lazy[x] = 0;
    }
}

void update(int x, int st, int en, int l, int r, int val) {
    push(x, st, en);
    if (en < l || r < st) {
        return;
    }
    if (l <= st && en <= r) {
        lazy[x] = val;
        push(x, st, en);
        return;
    }
    int mid = (st + en) >> 1;
    update(2*x, st, mid, l, r, val);
    update(2*x+1, mid+1, en, l, r, val);
    for (int i = 0; i <= 20; i++) {
        tree[x][i] = tree[2*x][i] + tree[2*x+1][i];
    }
}

long long query(int x, int st, int en, int l, int r) {
    push(x, st, en);
    if (en < l || r < st) {
        return 0;
    }
    if (l <= st && en <= r) {
        long long res = 0;
        for (int i = 0; i <= 20; i++) {
            res += (1LL << i) * tree[x][i];
        }
        return res;
    }
    int mid = (st + en) >> 1;
    return query(2*x, st, mid, l, r) + query(2*x+1, mid+1, en, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("242E.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n-1);
    /*for (int i = 0; i <= 4 * n; i++) {
        for (int k = 0; k <= 20; k++) {
            cout << tree[i][k] << " ";
        } cout << endl;
    }*/
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        int l, r, val;
        if (t == 1) {
            cin >> l >> r;
            cout << query(1, 0, n-1, l-1, r-1) << endl;
        } else {
            cin >> l >> r >> val;
            update(1, 0, n-1, l-1, r-1, val);
        }
    }
}
