#include <bits/stdc++.h>
using namespace std;

struct pp {
    int v, w;
};

const int maxn = 1e3+5;
const int INF = -1e9+1;
//DAG
vector<pp> graph[maxn];
bool visited[maxn];
vector<int> order;
int n, m, longest_index;
int dist[maxn];
int par[maxn];

void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].v;
        if (!visited[v])
            dfs(v);
    }
    order.push_back(u);
}

//calculates the longest path of a DAG
//must have topological order represented in the vector order established
//st is the starting vertex
//runtime is O(V+E)
int longest_path(int st) {
    memset(par, -1, sizeof(par));
    for (int i = 0; i < maxn; i++) {
        dist[i] = INF;
    }
    dist[st] = 0;
    for (int i = 0; i < order.size(); i++) {
        int u = order[i];
        if (dist[u] == INF) continue;
        for (int k = 0; k < graph[u].size(); k++) {
            int v = graph[u][k].v;
            int w = graph[u][k].w;
            if (dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        if (mx < dist[i]) {
            mx = dist[i];
            longest_index = i;
        }
    }
    return mx;
}

int main() {
    freopen("longest_path.in", "r", stdin);
    scanf("%d %d", &n, &m);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        graph[u].push_back({v, w});
    }
    //topological sort;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    printf("%d\n", longest_path(order[0]));
    //debugging
    /*for (int i = 0; i < n; i++) {
        cout << i+1 << ": ";
        for (int j =0 ; j < graph[i].size(); j++) {
            cout << graph[i][j].v << ' ';
        } cout << endl;
    }*/
    //for (int i = 0; i < order.size(); i++)  cout << order[i] + 1 << ' ';
    //for (int i = 0; i < n; i++) cout << dist[i] << ' ';
    /*for (int i = longest_index; i != -1; i = par[i]) {
        cout << i + 1 << ' ';
    } cout << endl;
    for (int i = longest_index; i != -1; i = par[i]) {
        cout << dist[i] << ' ';
    } cout << endl;*/
}
