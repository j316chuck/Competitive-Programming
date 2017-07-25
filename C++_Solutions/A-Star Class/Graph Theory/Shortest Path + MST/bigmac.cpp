#include <bits/stdc++.h>
using namespace std;

struct pp {
    int u, v;
    double w;
};

const int maxn = 2e3+5;
const double INF = 1e17 + 1;
int n, m, st, en;
double beg_dis;
vector<pp> edges;
double dis[maxn];

bool bellman() {
    for (int i = 0; i < maxn; i++) {
        dis[i] = INF;
    }
    dis[st] = beg_dis;
    int u, v; double w;
    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < edges.size(); j++) {
            u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dis[u] != INF && (dis[u] * w < dis[v])) {
                dis[v] = dis[u] * w;
            }
        }
    }
    for (int j = 0; j < edges.size(); j++) {
        u = edges[j].u, v = edges[j].v, w = edges[j].w;
        if (dis[u] != INF && dis[u] * w < dis[v]){
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("bigmac.in", "r", stdin);
    scanf("%d %d %lf %d %d", &n, &m, &beg_dis, &st, &en);
    edges.resize(m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lf", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    if (bellman()) {
        printf("%lld", (long long) dis[en]);
    } else {
        printf("0\n");
    }
    return 0;
}
