#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e12;
const int maxn = 1e6 + 5;
int n, m, k;
vector< pair<int, int> > st[maxn], fn[maxn];
long long b[maxn], e[maxn];

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int d, f, t, c;
        cin >> d >> f >> t >> c;
        if (f) {
            st[d + 1].push_back({f, c});
        } else {
            fn[d - 1].push_back({t, c});
        }
    }
    map<int, int> mp;
    long long total = 0;
    for (int i = 0; i < maxn; i++) {
        b[i] = INF;
        for (int j = 0; j < st[i].size(); j++) {
            int city = st[i][j].first;
            int cost = st[i][j].second;
            if (!mp[city]) {
                mp[city] = cost;
                total += cost;
            } else if (mp[city] > cost) {
                total -= (mp[city] - cost);
                mp[city] = cost;
            }
        }
        if (mp.size() == n) {
            b[i] = total;
        }
    }
    mp.clear();
    total = 0;
    for (int i = maxn - 1; i >= 0; i--) {
        e[i] = INF;
        for (int j = 0; j < fn[i].size(); j++) {
            int city = fn[i][j].first;
            int cost = fn[i][j].second;
            if (!mp[city]) {
                total += cost;
                mp[city] = cost;
            } else if (mp[city] > cost) {
                total -= mp[city] - cost;
                mp[city] = cost;
            }
        }
        if (mp.size() == n) {
            e[i] = total;
        }
    }

    long long ans = INF;
    for (int i = k; i < maxn; i++) {
        ans = min(ans, e[i] + b[i - k + 1]);
    }
    if (ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

