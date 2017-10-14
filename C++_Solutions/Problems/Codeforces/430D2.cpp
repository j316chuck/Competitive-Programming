#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> v[2 * maxn];
int n, w, h;
int p[maxn], t[maxn], g[maxn], x[maxn], y[maxn];

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++) {
        cin >> g[i] >> p[i] >> t[i];
        v[p[i] - t[i] + maxn].push_back(i);
    }
    vector<int> xs, ys;
    for (int i = 0; i < 2 * maxn; i++) if (v[i].size()) {
        for (int u : v[i]) {
            if (g[u] == 1) xs.push_back(p[u]);
            else ys.push_back(p[u]);
        }
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        reverse(ys.begin(), ys.end());
        sort(v[i].begin(), v[i].end(), [] (int u, int v) {
            if (g[u] != g[v]) return g[u] == 2;
            else return (g[u] == 2 ? p[u] > p[v] : p[u] < p[v]);
        });
        for (int j = 0; j < xs.size(); j++) {
            x[v[i][j]] = xs[j];
            y[v[i][j]] = h;
        }
        for (int j = 0; j < ys.size(); j++) {
            x[v[i][j + xs.size()]] = w;
            y[v[i][j + xs.size()]] = ys[j];
        }
        xs.clear();
        ys.clear();
    }
    for (int i = 1; i <= n; i++) {
        cout << x[i] << ' ' << y[i] << endl;
    }
}

