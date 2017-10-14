#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int maxm = 1 << 17;
const int INF = 1e5 + 15;
int n;
int a[maxn], res[maxn], fact[maxn];
int dp[maxn][maxm], par[maxn][maxm];
vector<int> p;

void calc_prime() {
    p.push_back(2);
    for (int i = 3; i <= 60; i++) {
        p.push_back(i);
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                p.pop_back();
                break;
            }
        }
    }
}

void calc_fact() {
    fact[1] = 0;
    for (int i = 2; i < 60; i++) {
        for (int j = 0; j < p.size(); j++) {
            if (i % p[j] == 0) {
                fact[i] |= (1 << j);
            }
        }
    }
}

int main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    //precalculations
    calc_prime();
    calc_fact();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    //base cases
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxm; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    //unnecessary
    /*for (int i = 1; i <= n; i++) {
        dp[i][0] += dp[i - 1][0] + abs(a[i] - 1);
    }*/

    //dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 60; j++) {
            int f = (maxm - 1) ^ fact[j];
            for (int s = f; s >= 0; s = ((s - 1) & f)) {
                if (dp[i][s ^ fact[j]] > dp[i - 1][s] + abs(a[i] - j)) {
                    dp[i][s ^ fact[j]] = dp[i - 1][s] + abs(a[i] - j);
                    par[i][s ^ fact[j]] = j;
                }
                if (s == 0) break;
            }
        }
    }

    //output
    int ans = INF;
    int index = -1;
    for (int i = 0; i < (maxm - 1); i++) {
        if (ans > dp[n][i]) {
            ans = dp[n][i];
            index = i;
        }
    }
    for (int i = n; i >= 1; i--) {
        res[i] = par[i][index];
        index = index ^ fact[res[i]];
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
}

