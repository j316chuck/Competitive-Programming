#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
struct pp {
    long long a, b, c; int index;
    bool operator < (const pp &a) const {
        return c < a.c;
    }
} sub[maxn];
pair<int, int> parent[maxn][maxn][maxn];
long long dp[maxn][maxn][maxn];
long long k;
int n, m;

//d = day, s = sub, o = offset, type 1 = +, type 2 = x
long long dfs(int d, int s, int o) {
    long long val = sub[s].a + o;
    //cout << "val: " << val << " d: " << d << " s: " << s << " o: " << o << " DP :" << dp[d][s][o] << endl;
    if (dp[d][s][o] != -1) {
        return dp[d][s][o];
    }
    if (d == n) {
        return val;
    }

    long long ans = -2; int nxt = -2, type = -2;
    for (int ns = s + 1; ns <= m; ns++) {
        if (sub[ns].c == sub[s].c) continue;
        long long v1 = val + k;
        if (sub[ns].a <= v1 && v1 <= sub[ns].b) {
            long long sum = dfs(d + 1, ns, v1 - sub[ns].a);
            if (sum >= 0) {
                sum += val;
                if (sum > ans) {
                    ans = sum;
                    nxt = ns;
                    type = 1;
                }
            }
        }
        long long v2 = val * k;
        if (sub[ns].a <= v2 && v2 <= sub[ns].b) {
            long long sum = dfs(d + 1, ns, v2 - sub[ns].a);
            if (sum >= 0) {
                sum += val;
                if (sum > ans) {
                    ans = sum;
                    nxt = ns;
                    type = 2;
                }
            }
        }
    }

    parent[d][s][o] = {nxt, type};
    return dp[d][s][o] = ans;
}

int main() {
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> sub[i].a >> sub[i].b >> sub[i].c;
        sub[i].index = i;
    }
    sort(sub + 1, sub + m + 1);
    memset(dp, -1, sizeof(dp));

    long long ans = -2; int d = -1, nm = -1;
    for (int i = 1; i <= m; i++) {
        for (long long j = sub[i].a; j <= sub[i].b; j++) {
            long long diff = j - sub[i].a;
            if (ans < dfs(1, i, diff)) {
                ans = dfs(1, i, diff);
                nm = i;
                d = diff;
            }
        }
    }
    if (ans < 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (int day = 1; day <= n; day++) {
            long long om = nm;
            long long v = sub[om].a + d;
            cout << sub[om].index << ' ' << v << endl;
            int t = parent[day][om][d].second;
            nm = parent[day][om][d].first;
            if (t == 1) {
                d = (v + k) - sub[nm].a;
            } else {
                d = (v * k) - sub[nm].a;
            }
        }
    }
}

