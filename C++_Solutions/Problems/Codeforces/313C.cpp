#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e3 + 5;
const int maxm = 2e5 + 5;
const long long mod = 1e9 + 7;
struct pp {
    int r, c;
    bool operator < (const pp &a) const {
        return c < a.c || (c == a.c && r < a.r);
    }
} a[maxm];
int h, w, n;
long long dp[maxm];
long long fact[maxm], inv[maxm];

int calc() {
    fact[0] = 1;
    for (int i = 1; i < maxm; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv[0] = 1;
    inv[1] = 1;
    for (int i = 2; i < maxm; i++) {
        inv[i] = (inv[mod % i] * (-mod / i)) % mod;
        inv[i] = (inv[i] + mod) % mod;
    }
    for (int i = 2; i < maxm; i++) {
        inv[i] = (inv[i] * inv[i - 1]) % mod;
    }
}

long long comb(int dr, int dc) {
    if (dr < 0 || dc < 0) return 0;
    if (dr == 0 || dc == 0) return 1;
    return (((fact[dr + dc] * inv[dr]) % mod) * inv[dc]) % mod;
}

int main() {
    //freopen("input.in", "r", stdin);
    calc();
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].r >> a[i].c;
    }
    int sr = 1, sc = 1;
    a[n] = {h, w};
    sort (a,  a + n + 1);
    dp[0] = comb(a[0].r - sr, a[0].c - sc);
    //for (int i = 0; i <= n; i++) cout << a[i].r << ' ' << a[i].c << endl;
    //cout << sr - a[0].r << ' ' << a[0].c - sc << endl;
    //cout << dp[0] << endl;
    for (int i = 1; i <= n; i++) {
        dp[i] = comb(a[i].r - sr, a[i].c - sc);
        for (int j = 0; j < i; j++) {
            long long tmp = (dp[j] * comb(a[i].r - a[j].r, a[i].c - a[j].c)) % mod;
            dp[i] = (dp[i] - tmp) % mod;
        }
        dp[i] = (dp[i] + mod) % mod;
    }
    cout << dp[n] << endl;
}

