#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
//bit is one indexed
int a[maxn], bit[maxn], l[maxn], r[maxn], p[maxn];
//v is 0 indexed
vector<int> v[maxn];
vector<int> qq[maxn];
long long ans[maxn];

long long sum(int x) {
    long long ret = 0;
    while (x > 0) {
        ret += bit[x];
        x -= x & -x;
    }
    return ret;
}

void upd(int x, int val) {
    while (x < maxn) {
        bit[x] += val;
        x += x & - x;
    }
}


int main() {
    //freopen("182D.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
        p[a[i]] = i;
    }
    //0 based sieve with smaller to bigger transitions
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            int x = p[j], y = p[i];
            if (x > y) swap(x, y);
            v[x].push_back(y);
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l[i], &r[i]);
        qq[l[i]-1].push_back(i);
    }

    for (int i = n-1; i >= 0; i--) {
        for (int p : v[i]) {
            upd(p + 1, 1);
        }
        for (int p : qq[i]) {
            ans[p] = sum(r[p]);
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}
