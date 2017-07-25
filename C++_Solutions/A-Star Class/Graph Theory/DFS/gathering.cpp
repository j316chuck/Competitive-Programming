#include <bits/stdc++.h>
using namespace std;

class pp {
public:
    int v, w;
};

const int maxn = 1e5+3;
int n, total_child;
long long child[maxn], dist[maxn], ret, cost[maxn];
vector<pp> graph[maxn];

void dfs(int u, int par) {
    int v;
    for (int i = 0; i < graph[u].size(); i++) {
        v = graph[u][i].v;
        if (v != par) {
            dfs(v, u);
            child[u] += child[v];
            dist[u] += dist[v] + (child[v] * 1LL * graph[u][i].w);
        }
    }
}

void dfs2(int u, int par, int par_dist, int w) {
    long long dis = par_dist + (total_child - 2 * child[u]) * w;
    int v;
    ret = min(ret, dis);
    for (int i = 0; i < graph[u].size(); i++) {
        v = graph[u][i].v;
        if (v != par) {
            dfs2(v, u, dis, graph[u][i].w);
        }
    }
}

long long dfs3(int u, int par) {
    long long c = cost[u];
    for (int i = 0; i < graph[u].size(); i++) {
        if (graph[u][i].v == par) continue;
        cost[graph[u][i].v] = cost[u] + (total_child - 2 * child[graph[u][i].v]) * graph[u][i].w;
        c = min(c, dfs3(graph[u][i].v, u));
    }
    return c;
}

int main() {
    freopen("gathering.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &child[i]);
        total_child += child[i];
    }
    int u, v, w;
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dfs(0, -1);
    ret = dist[0];
    for (int i = 0; i < graph[0].size(); i++) {
        dfs2(graph[0][i].v, 0, dist[0], graph[0][i].w);
    }
    printf("%lld\n", ret);
    //cost[0] = dist[0];
    //printf("%lld\n", dfs3(0, -1));
}
