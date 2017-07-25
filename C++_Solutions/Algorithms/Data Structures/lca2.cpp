/*
ID: j316chuck
PROG: lca
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
using namespace std;

const int maxn = 1e3+5;
const int k = 15;
vector<int> graph[maxn];
int depth[maxn];
int parent[maxn];
int n, q, e;

void dfs(int u, int par, int d) {
    depth[u] = d;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (par != v) {
            parent[v] = u;
            dfs(v, u, d+1);
        }
    }
}

int anc[maxn][k];
void sparse_table() {
    //for (int i = 0; i < maxn; i++) memset(anc[i], -1, sizeof(anc[i]));

    for (int i = 0; i < n; i++) {
        anc[i][0] = parent[i];
    }

    for (int j = 1; 1 << j < n; j++) {
        for (int i = 0; i < n; i++) {
            anc[i][j] = anc[i][j-1] == -1 ? -1 : anc[anc[i][j-1]][j-1];
        }
    }
    /*for (int j = 0; 1 << j < n; j++) {
        cout << "parent of height "  << j << " ";
        for (int i = 0; i < n; i++) {
            cout << anc[i][j] << ' ';
        } cout << endl;
    }*/
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int stp = 1;
    for(; 1 << stp <= depth[u]; stp++);
    stp--;
    for (int j = stp; j >= 0; j--) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = anc[u][j];
        }
    }
    if (u == v) {
        return u;
    }
    for (int j = stp; j >= 0; j--) {
        if (anc[u][j] != -1 && anc[u][j] != anc[v][j]) {
            u = anc[u][j];
            v = anc[v][j];
        }
    }
    return anc[u][0];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

inline void calc_lca() {
    //building graph
    cin >> n;
    int x, v;
    for (int i = 0; i < n; i++) {
        cin >> x;
        graph[i].clear();
        for (int k = 0; k < x; k++) {
            cin >> v;
            graph[i].push_back(v-1);
            graph[v-1].push_back(i);
        }
    }

    memset(parent, -1, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    //dfs
    dfs(0, -1, 0);

    //construct sparse table
    sparse_table();

    //query
    int l, r;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << lca(l-1, r-1) + 1 << endl;
    }
}

int main() {

    //Rd("lca2.in");
    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    int u, v, t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ":\n";
        calc_lca();
    }
    return 0;
}




