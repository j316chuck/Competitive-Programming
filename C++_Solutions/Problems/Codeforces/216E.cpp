#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+5;
const int maxm = 1e6 + 13;
int n, m;
int bit[maxn], a[maxn], ans[maxn], t;
vector< pair<int, int> > qq[maxm];
vector<int> v[maxm];

void update(int x) {
    x++;
    while (x < maxm) {
        bit[x]++;
        x += x & -x;
    }
}
int sum(int x) {
    x++;
    int total = 0;
    while (x > 0) {
        total += bit[x];
        x -= x & -x;
    }
    return total;
}

int sum(int l, int r) {
    return sum(r) - sum(l-1);
}

int main() {
    //freopen("216E.in", "r", stdin);
    //freopen("216E.out", "w", stdout);
    scanf("%d %d", &n, &m);
    int l, r;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        v[r].push_back(l);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        a[0] = 0, a[t+1] = 1e6 + 3;
        for (int j = 1; j <= t; j++) {
            scanf("%d", &a[j]);
        }
        for (int j = 0; j <= t; j++) {
            qq[a[j + 1] - 1].push_back({a[j] + 1, i});
        }
    }

    for (int i = 0; i < 1000005; i++) {
        for (int j : v[i]) {
            update(j);
        }
        for (pair<int, int> p : qq[i]) {
            ans[p.second] += sum(p.first, i);
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%d\n", (n - ans[i]));
    }
    return 0;
}
