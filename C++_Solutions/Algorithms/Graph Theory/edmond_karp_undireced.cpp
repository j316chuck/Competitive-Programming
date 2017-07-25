#include <bits/stdc++.h>
using namespace std;

/*struct Edge {
    int u, v, res, cap;
    Edge(int u, int v, int res, int cap) : u(u), v(v), res(res), cap(cap) {};
};*/

const int maxn = 55;
const int INF = 1e9 + 1;
int n, m;
vector<int> graph[maxn];
int capacity[maxn][maxn];
int residual[maxn][maxn];
int parent[maxn];
bool visited[maxn];

bool bfs(int st, int en) {
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    visited[st] = true;
    queue<int> q;
    q.push(st);
    int u, v;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            v = graph[u][i];
            if (visited[v] == false && capacity[u][v] > residual[u][v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return visited[en] == true;
}


int max_flow(int st, int en) {
    int flow = 0;
    while (bfs(st, en)) {
        int path_flow = INF;
        for (int v = en; v != st; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, capacity[u][v] - residual[u][v]);
        }
        for (int v = en; v != st; v = parent[v]) {
            int u = parent[v];
            residual[u][v] += path_flow;
            residual[v][u] -= path_flow;
        }
        flow += path_flow;
    }

    return flow;
}

int main() {
    freopen("edmond_karp_undirected.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, cap;
        scanf("%d %d %d", &u, &v, &cap);
        graph[u].push_back(v);
        graph[v].push_back(u);
        capacity[u][v] = cap;
    }
    /*for (int i = 1; i <= n; i++) {
        cout << graph[i][0] << endl;
    }*/
    printf("%d\n", max_flow(1, n));
}

