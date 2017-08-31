#include <bits/stdc++.h>
using namespace std;

const int maxn = 14;
const int maxm = 100500;
long long dp[2][maxn * 10][maxm][2];
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
    //dp with state space reduction
    for (int pos = 0; pos < maxn; pos++) {
        //initializing next dp position as 0
        for (int sum = 0; sum <= y; sum++) {
            for (int mod = 0; mod < k; mod++) {
                for (int under = 0; under < 2; under++) {
                    dp[1 ^ (pos % 2)][sum][mod][under] = 0;
                }
            }
        }
        //dp
        for (int sum = 0; sum <= y; sum++) {
            for (int mod = 0; mod < k; mod++) {
                for (int under = 0; under < 2; under++) if (dp[pos % 2][sum][mod][under]) {
                    for (int dig = 0; dig < 10; dig++) {
                        if (dig > num[pos + 1] && under == 0) {
                            break;
                        } if (dig + sum > y) {
                            break;
                        }
                        dp[(pos + 1) % 2][sum + dig][(mod * 10 + dig) % k][bool (under | (dig < num[pos + 1]))] += dp[pos % 2][sum][mod][under];
                    }
                }
            }
        }
    }
    //final states
    long long ans = 0;
    for (int i = x; i <= y; i++) {
        ans += dp[(maxn % 2)][i][0][1];
        ans += dp[(maxn % 2)][i][0][0];
    }
    return ans;
}

int main() {
    freopen("digit.in", "r", stdin);
    cin >> a >> b >> x >> y >> k;
    if (k >= maxm) {
        cout << naive() << endl;
    } else {
        cout << solve(b) - solve(a - 1) << endl;
    }
}

