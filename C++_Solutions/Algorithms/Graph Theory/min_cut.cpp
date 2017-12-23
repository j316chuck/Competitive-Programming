/*
Algorithm: min cut
Solves: HackerEarth Baahubali vs Bhallaladeva
Idea: min cut = max flow, construct residual graph, then solve max flow, bfs one more time to find min cut
if undirected graph, just make two directed edges, maximum flow literally equals minimum cut.
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
const int INF = 1e9 + 1;
map<char, int> mp;
char s, t;
int n, m;
int capacity[maxn][maxn], residual[maxn][maxn], parent[maxn];
bool visited[maxn];
vector<int> graph[maxn];

bool bfs(int st, int en) {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    parent[st] = 0;
    visited[st] = true;
    queue<int> q; q.push(st);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (!visited[v] && capacity[u][v] > residual[u][v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return visited[en];
}

//min_cut = max_flow
//bfs to find the edges of min cut;
int max_flow(int st, int en) {
    int flow = 0;
    while (bfs(st, en)) {
        int path_flow = INF;
        for (int v = en; v != st; v = parent[v]) {
            path_flow = min(path_flow, capacity[parent[v]][v] - residual[parent[v]][v]);
        }
        for (int v = en; v != st; v = parent[v]) {
            residual[parent[v]][v] += path_flow;
            residual[v][parent[v]] -= path_flow;
        }
        flow += path_flow;
    }
    return flow;
}

int main() {
    freopen("min_cut.in", "r", stdin);
    cin >> m >> s >> t;
    mp[s] = ++n;
    mp[t] = ++n;
    for (int i = 0; i < m; i++) {
        char x, y; int w;
        cin >> x >> y >> w;
        if (!mp[x]) {
            mp[x] = ++n;
        } if (!mp[y]) {
            mp[y] = ++n;
        }
        capacity[mp[x]][mp[y]] = capacity[mp[y]][mp[x]] = w;
        graph[mp[x]].push_back(mp[y]);
        graph[mp[y]].push_back(mp[x]);
    }
    cout << max_flow(mp[s], mp[t]) << endl;
}


