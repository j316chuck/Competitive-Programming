#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int v, rev;
    long long cap, flow;
};

const int maxn = 5e3+5;
const long long INF = 1LL << 60;
int n, m;
vector<Edge> graph[maxn];
int work[maxn], level[maxn];

//adding directed edge
/*void add_edge(int u, int v, long long cap) {
    if (u == v) return;
    Edge u1 = {v, graph[v].size(), cap, 0};
    Edge v1 = {u, graph[u].size(), 0, 0};
    graph[u].push_back(u1);
    graph[v].push_back(v1);
}*/

//adding undirected edge
void add_edge(int u, int v, long long cap) {
    if (u == v) return;
    Edge u1 = {v, graph[v].size(), cap, 0};
    Edge v1 = {u, graph[u].size(), cap, 0};
    graph[u].push_back(u1);
    graph[v].push_back(v1);
}

bool bfs(int st, int en) {
    queue<int> q({st});
    memset(level, -1, sizeof(level));
    level[st] = 0;
    int u, v;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            v = graph[u][i].v;
            if (level[v] == -1 && graph[u][i].cap > graph[u][i].flow) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[en] != -1;
}

long long dfs(int u, int dest, long long ret) {
    //base case
    if (ret == 0 || u == dest) {
        return ret;
    }
    for (int &i = work[u]; i < graph[u].size(); i++) {
        Edge &e = graph[u][i];
        if (e.cap <= e.flow) {
            continue;
        }
        int v = e.v;
        if (level[v] == level[u] + 1) {
            long long bottleneck = dfs(v, dest, min(ret, e.cap - e.flow));
            if (bottleneck > 0) {
                e.flow += bottleneck;
                graph[v][e.rev].flow -= bottleneck;
                return bottleneck;
            }
        }
    }

    //default return value when there is no more blocking flow left
    return 0;
}

long long max_flow(int st, int en) {
    long long result = 0;
    long long flow;
    while (bfs(st, en)) {
        memset(work, 0, sizeof(work));
        while (flow = dfs(st, en, INF)) {
            result += flow;
        }
    }
    return result;
}

int main() {
    //freopen("dinic.in", "r", stdin);
    scanf("%d %d", &n, &m);
    int u, v; long long cap;
    //for undirected graphs just add edge twice
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &u, &v, &cap);
        add_edge(u, v, cap);
    }
    /*printf("%d\n", bfs(1, n));
    for (int i = 1; i <= n; i++) {
        cout << level[i] << ' ';
    } cout << endl;*/
    printf("%lld\n", max_flow(1, n));
    return 0;
}

