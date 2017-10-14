#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v) {
    cout << "vector is: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    } cout << endl;
}

void print(int arr[], int n) {
    cout << "array is: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    } cout << endl;
}

const int maxn = 1e6 + 5;
const int maxm = 20;
int P[maxn][maxm];
vector<int> graph[maxn];
int depth[maxn];
int parent[maxn];
int n;

void init() {
    memset(parent, -1, sizeof(parent));
    memset(depth, 0, sizeof(depth));
    //print(parent, 10); print(depth, 10);
    for (int i = 0; i < maxn; i++) {
        graph[i].clear();
        memset(P[i], -1, sizeof(P[i]));
        //print(P[i], 10);
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

void lca() {
    scanf("%d", &n);
    int x, v, q, l, r;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        for (int k = 0; k < x; k++) {
            scanf("%d", &v);
            graph[i].push_back(v);
            graph[v].push_back(i);
        }
    }
    dfs(1, -1, 0);
    sparse_table();
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", lca(l, r));
    }
}

int main() {
    //freopen("lca3.in", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; ++tt) {
        printf("Case %d:\n", tt);
        init();
        lca();
    }

}
