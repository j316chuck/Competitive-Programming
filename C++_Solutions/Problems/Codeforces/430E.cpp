#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
const int maxm = 20;
set<int> s1, s2;
int P[maxn][maxm];
int depth[maxn];
int n;

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int j = maxm - 1; j >= 0; j--) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = P[u][j];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = maxm - 1; i >= 0; i--) {
        if (P[u][i] != -1 && P[u][i] != P[v][i]) {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return P[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
    //freopen("input.in", "r", stdin);
    memset(P, -1, sizeof(P));
    cin >> n;
    depth[1] = 0;
    s1.insert(1);
    int mx = 0;
    for (int i = 2; i <= n + 1; i++) {
        int par;
        cin >> par;
        P[i][0] = par;
        depth[i] = depth[par] + 1;
        for (int j = 1; j < 20; j++) {
            P[i][j] = P[i][j - 1] == -1 ? -1 : P[P[i][j - 1]][j - 1];
        }
        int d1 = s1.size() == 0 ? 0 : dist(i, *s1.begin());
        int d2 = s2.size() == 0 ? 0 : dist(i, *s2.begin());
        int d = max(d1, d2);
        if (d > mx) {
            mx = d;
            if (mx == d1) {
                for (int j : s2) {
                    if (dist(i, j) == mx) {
                        s1.insert(j);
                    }
                }
                s2.clear();
                s2.insert(i);
            } else {
                for (int j : s1) {
                    if (dist(i, j) == mx) {
                        s2.insert(j);
                    }
                }
                s1.clear();
                s1.insert(i);
            }
        } else if (d == mx) {
            if (d1 == mx) {
                s2.insert(i);
            } else {
                s1.insert(i);
            }
        }
        cout << (int) s1.size() + (int) s2.size() << endl;
    }
}

