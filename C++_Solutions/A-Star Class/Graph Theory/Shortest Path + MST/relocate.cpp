#include <bits/stdc++.h>
using namespace std;

struct pp {
    int v, w;
    bool operator < (const pp &a) const {
        return w > a.w;
    }
};
const int maxn = 1e4+5;
int n, m, k;
set<int> myhouse;
vector< pair<int, int> > houses;
vector<pp> graph[maxn];
int dist[6][maxn];

void dijstrka(int h, int st) {
    priority_queue<pp> pq;
    pq.push({st, 0});
    //dist[h][st] = 0;
    int u, v, w, cw;
    while(!pq.empty()) {
        u = pq.top().v;
        cw = pq.top().w;
        pq.pop();
        if (dist[h][u] <= cw) continue;
        dist[h][u] = cw;
        for (int i = 0; i < graph[u].size(); i++) {
            v = graph[u][i].v;
            w = graph[u][i].w;
            if (dist[h][u] + w < dist[h][v]) {
                pq.push({v, dist[h][u] + w});
            }
        }
    }
    /*int counter = 0;
    dist[h][st] = 0;
    int u, v, w;
    while(!pq.empty()) {
        u = pq.top().v;
        pq.pop();
        cout << u << endl;
        for (int i = 0; i < graph[u].size(); i++) {
            v = graph[u][i].v;
            w = graph[u][i].w;
            if (dist[h][u] + w < dist[h][v]) {
                dist[h][v] = dist[h][u] + w;
                pq.push({v, dist[h][v]});
            }
        }
    }*/
}

/*int best_perm(vector< pair<int, int> > &houses) {
    int u, v, h1, h2;
    int total = 0;
    for (int i = 0; i + 1 < houses.size(); i++) {
        h1 = houses[i].second, h2 = houses[i+1].second;
        u = houses[i].first, v = houses[i+1].second;
        total += dist[h1][v];
    }
    int m = 1e9+1;
    h1 = houses[0].first; h2 = houses.back().first;
    for (int i = 0; i < n; i++) {
        if (myhouse.find(i) != myhouse.end()) continue;
        m = min(m, dist[h1][i] + dist[h2][i]);
    }
    return m + total;
}*/

int main () {
    freopen("relocate.in", "r", stdin);
    memset(dist, 63, sizeof(dist));
    scanf("%d %d %d", &n, &m, &k);
    houses.resize(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &houses[i].first);
        houses[i].first--;
        houses[i].second = i;
        myhouse.insert(houses[i].first);
    }
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for (int i = 0; i < houses.size(); i++) {
        //cout << "hi" << endl;
        dijstrka(houses[i].second, houses[i].first);
    }
    int order[k];
    for (int i = 0; i < k; i++) {
        order[i] = i;
    }
    int ret = 1e9+1;
    do {
        //ret = min(ret, best_perm(houses));
        int total = 1e9+1;
        for (int i = 0; i < n; i++) {
            if (myhouse.find(i) == myhouse.end()) {
                total = min(total, dist[order[0]][i] + dist[order[k-1]][i]);
            }
        }
        for (int i = 0; i + 1 < houses.size(); i++) {
            total += dist[order[i]][houses[order[i+1]].first];
        }
        ret = min(ret, total);
    } while(next_permutation(order, order+k));
    printf("%d\n", ret);
    return 0;
}
