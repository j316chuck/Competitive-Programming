#include <bits/stdc++.h>
using namespace std;

const int maxn = 14;
const int maxm = 5000;
long long dp[maxn + 1][maxn * 9 + 9][maxm][2];
long long a, b, k; int x, y;
int num[maxn + 1];

int digit(long long x) {
    int sum = 0;
    while (x) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

long long naive() {
    long long ans = 0;
    for (long long i = k; i <= b; i += k) {
        if (i < a) {
            continue;
        }
        int dig = digit(i);
        if (x <= dig && dig <= y) {
            ans++;
        }
    }
    return ans;
}

long long solve(long long c) {
    if (c == 0) return 0;
    //initialization
    long long cur = c;
    for (int i = maxn; i >= 0; i--) {
        num[i] = cur % 10;
        cur /= 10;
    }
    //base case
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for (int pos = 0; pos < maxn; pos++) {
        for (int sum = 0; sum <= pos * 9; sum++) {
            for (int mod = 0; mod < k; mod++) {
                cur = dp[pos][sum][mod][0];
                for (int dig = 0; dig < num[pos + 1]; dig++) {
                    dp[pos + 1][sum + dig][(mod * 10 + dig) % k][1] += cur;
                }
                dp[pos + 1][sum + num[pos + 1]][(mod * 10 + num[pos + 1]) % k][0] += cur;
                cur = dp[pos][sum][mod][1];
                for (int dig = 0;  dig < 10; dig++) {
                    dp[pos + 1][sum + dig][(mod * 10 + dig) % k][1] += cur;
                }
            }
        }
    }

    //final states
    long long ans = 0;
    for (int i = x; i <= y; i++) {
        ans += dp[maxn][i][0][1];
        ans += dp[maxn][i][0][0];
    }
    return ans;
}

int main() {
    //freopen("digit.in", "r", stdin);
    cin >> a >> b >> x >> y >> k;
    if (k >= maxm) {
        cout << naive() << endl;
    } else {
        //cout << solve(b) << endl;
        cout << solve(b) - solve(a - 1) << endl;
    }
}
