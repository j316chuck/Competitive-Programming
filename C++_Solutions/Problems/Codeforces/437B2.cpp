#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const long long inf = 1e9 + 7;
long long l[maxn], r[maxn], rm[maxn], lm[maxn];
long long p, q, s;
int n;

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> p >> q >> s;
    vector<long long> v(n + 1);
    for (int i = 0; i < maxn; i++) {
        l[i] = r[i] = -inf;
    }
    l[0] = -inf;
    lm[0] = inf;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        l[i] = max(l[i - 1], v[i]);
        lm[i] = min(lm[i - 1], v[i]);
    }
    r[n + 1] = -inf;
    rm[n + 1] = inf;
    for (int i = n; i >= 1; i--) {
        r[i] = max(v[i], r[i + 1]);
        rm[i] = min(v[i], rm[i + 1]);
    }
    long long ans = -3 * inf * inf;
    for (int i = 1; i <= n; i++) {
        long long a, b, c;
        c = (s < 0 ? rm[i] * s : r[i] * s);
        b = (q * v[i]);
        a = (p < 0 ? lm[i] * p : l[i] * p);
        ans = max(ans, a + b + c);
    }
    cout << ans << endl;
}

