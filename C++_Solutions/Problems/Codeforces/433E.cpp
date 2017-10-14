#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int bit[maxn], u[maxn], d[maxn], l[maxn], r[maxn], row[maxn];
long long cnt[maxn];
int n, q;
vector<int> v[maxn];

long long square(int x) {
    return (1LL * x * (x - 1)) / 2;
}

void update(int idx) {
    while (idx < maxn) {
        bit[idx]++;
        idx += idx & -idx;
    }
}

int sum(int idx) {
    int total = 0;
    while (idx) {
        total += bit[idx];
        idx -= idx & -idx;
    }
    return total;
}

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        row[r] = i;
    }
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> d[i] >> r[i] >> u[i];
        v[u[i] + 1].push_back(i);
    }
    for (int i = n; i >= 1; i--) {
        update(row[i]);
        for (int idx : v[i]) {
            cnt[idx] += square(sum(n) - sum(r[idx]));
            cnt[idx] += square(sum(l[idx] - 1));
        }
    }
    memset(bit, 0, sizeof(bit));
    for (int i = 0; i < maxn; i++) {
        v[i].clear();
    }
    for (int i = 1; i <= q; i++) {
        v[d[i] - 1].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        update(row[i]);
        for (int idx : v[i]) {
            cnt[idx] += square(sum(n) - sum(r[idx]));
            cnt[idx] += square(sum(l[idx] - 1));
        }
    }
    for (int i = 1; i <= q; i++) {
        long long ans = 0;
        ans += square(l[i] - 1);
        ans += square(n - r[i]);
        ans += square(d[i] - 1);
        ans += square(n - u[i]);
        ans -= cnt[i];
        ans = square(n) - ans;
        cout << ans << endl;
    }
}

