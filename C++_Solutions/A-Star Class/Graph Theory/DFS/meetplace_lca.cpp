#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5;
const int maxm = 15;
int depth[maxn];
int anc[maxn][maxm];
vector<int> graph[maxn];

void dfs(int u) {
    for (int i = 0; i < graph[u].size(); i++) {
        depth[graph[u][i]] = 1 + depth[u];
        dfs(graph[u][i]);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int j = maxm-1; j >= 0; j--) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = anc[u][j];
        }
    }
    if (u == v) return u;

    for (int j = maxm-1; j >= 0; j--) {
        if (anc[u][j] != -1 && anc[u][j] != anc[v][j]) {
            u = anc[u][j];
            v = anc[v][j];
        }
    }
    return anc[u][0];
}

int main() {
    //freopen("meetplace.in", "r", stdin);
    int n, q, par;
    scanf("%d %d", &n, &q);
    depth[1] = 0;
    anc[1][0] = -1;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &par);
        anc[i][0] = par;
        graph[par].push_back(i);
    }
    dfs(1);
    /*for (int i = 1; i <= n; i++) {
        cout << depth[i] << ' ';
    } cout << endl;*/

    //sparse table
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 1; i <= n; i++) {
            anc[i][j] = anc[i][j-1] == -1 ? -1 : anc[anc[i][j-1]][j-1];
        }
    }
    int u, v;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &u, &v);
        printf("%d\n", lca(u, v));
    }

}

