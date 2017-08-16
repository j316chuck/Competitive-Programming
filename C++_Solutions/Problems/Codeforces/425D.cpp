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

const int maxn = 1e5+15;
const int maxm = 17;
int P[maxn][maxm];
vector<int> graph[maxn];
int depth[maxn];
int parent[maxn];
int n, q;

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

int calc(int s, int t, int f) {
    int ans = 0;
    int sf = lca(s, f);
    int tf = lca(t, f);
    if ((tf == f) != (sf == f)) {
        return 1;
    } else if ((tf == f) && (sf == f)) {
        return depth[lca(s, t)] - depth[f] + 1;
    } else if (sf == tf){
        ans += depth[lca(t, s)] - depth[sf];
    }
    ans += 1 + depth[f] - max(depth[sf], depth[tf]);
    return ans;
}

int main() {
    //freopen("425D.in", "r", stdin);
    init();
    scanf("%d %d", &n, &q);
    int v;
    for (int u = 2; u <= n; u++) {
        scanf("%d", &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1, 0);
    sparse_table();
    for (int i = 0; i < q; i++) {
        int ans = 0, a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        ans = max(ans, calc(a, b, c));
        ans = max(ans, calc(a, c, b));
        ans = max(ans, calc(b, a, c));
        ans = max(ans, calc(b, c, a));
        ans = max(ans, calc(c, b, a));
        ans = max(ans, calc(c, a, b));
        printf("%d\n", ans);
    }
    return 0;
}

