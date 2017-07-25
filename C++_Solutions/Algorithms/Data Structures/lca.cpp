/*
ID: j316chuck
PROG: lca
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;

const int maxn = 1e5+5;
const int maxm = 15;
int P[maxn][maxm];
vector<int> graph[maxn];
int depth[maxn];
int parent[maxn];
int n, q;

void init() {
    memset(parent, -1, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    for (int i = 0; i < maxn; i++) {
        graph[i].clear();
        memset(P[i], -1, sizeof(P[i]));
    }
}

void dfs(int u, int par, int d) {
    depth[u] = d;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != par) {
            parent[v] = u;
            dfs(v, u, d+1);
        }
    }
}

void sparse_table() {
    for (int i = 1; i <= n; i++) {
        P[i][0] = parent[i];
    }
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i <= n; i++) {
            P[i][j] = P[i][j-1] == -1 ? -1 : P[P[i][j-1]][j-1];
        }
    }
}

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
    //be careful on implementation must be maxm - 1 or else you will get index out of bounds
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

    //Rd("lca.in");
    //ios_base::sync_with_stdio(0);
    int u, v, e;
    cin >> n >> q;
    e = n-1;
    //building graph
    map<int, int> mp; set<int> s;
    vector< pair<int, int> > pts;
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        s.insert(u); s.insert(v);
        pts.push_back(make_pair(u, v));
    }
    init();
    int cnt = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        mp[*it] = ++cnt;
    }
    for (int i = 0; i < e; i++) {
        pts[i].first = mp[pts[i].first];
        pts[i].second = mp[pts[i].second];
    }
    for (int i = 0; i < e; i++) {
        graph[pts[i].first].push_back(pts[i].second);
        graph[pts[i].second].push_back(pts[i].first);
    }
    //dfs
    dfs(1, -1, 0);
    //construct sparse table
    sparse_table();

    //query
    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << dist(mp[l], mp[r]) << endl;
    }
    return 0;
}



