#include <bits/stdc++.h>
using namespace std;


const long long mod = 998244353;
const int maxn = 5e3 + 5;
long long c[maxn][maxn];
long long f[maxn];

void calc() {
    c[0][0] = 1;
    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    f[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
}

long long solve(long long n1, long long n2) {
    long long ans = 0;
    for (int i = 0; i <= min(n1, n2); i++) {
        long long m = (c[n1][i] * c[n2][i]) % mod;
        m = (m * f[i]) % mod;
        ans = (ans + m) % mod;
    }
    return ans;
}

int main() {
    //freopen("input.in", "r", stdin);
    calc();
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans = solve(a, b);
    ans = (ans * solve(b, c)) % mod;
    ans = (ans * solve(c, a)) % mod;
    cout << ans << endl;
}
