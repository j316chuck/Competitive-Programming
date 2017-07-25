#include <bits/stdc++.h>
using namespace std;

struct pp {
    int v, w;
    bool operator < (const pp &a) const {
        return w < a.w;
    }
};

struct edge {
    int u, v, w;
};

const int INF = 1e9+1;
const int maxn = 255;
int n, m;
vector<edge> edges;
vector<pp> graph[maxn];
int dist[maxn];

int dijstrka() {
    for (int i = 0; i < maxn; i++) {
        graph[i].clear(), dist[i] = INF;
    }
    for (int i = 0; i < edges.size(); i++) {
       graph[edges[i].u].push_back({edges[i].v, edges[i].w});
       graph[edges[i].v].push_back({edges[i].u, edges[i].w});
    }
    priority_queue<pp> pq;
    pq.push({1, 0});
    dist[1] = 0;
    int v, u, w;
    while (!pq.empty()) {
        u = pq.top().v;
        pq.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            w = graph[u][i].w;
            v = graph[u][i].v;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
    return dist[n];
}


int main() {
    //freopen("roadblock.in", "r", stdin);
    scanf("%d %d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back({u, v, w});
    }
    int best = dijstrka();
    int mx = 0;
    for (int i = 0; i < m; i++) {
        edges[i].w = edges[i].w * 2;
        mx = max(mx, dijstrka());
        edges[i].w = edges[i].w / 2;
    }
    printf("%d\n", mx - best);
    return 0;
}
