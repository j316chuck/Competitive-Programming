#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e4+1e3;
const int INF = 1e9+1;
const int maxm = 100;
int n, nopt, f, m;
bool inc[maxn];
vector<int> take;
vector<int> graph[maxn];
vector<int> order;
int visited[maxn];
int dist[maxn];

void construct_graph() {
    for (int i = 0; i <= n+maxm; i++) {
        int u = i;
        for (int j = 0; j < take.size(); j++) {
            int v = u - take[j];
            if (v >= 0) {
                graph[u].push_back(v);
            }
        }
        if (inc[i]) {
            graph[i].push_back(m+i);
        }
    }
}

bool cycle(int u) {
    visited[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (visited[v] == 1) {
            return true;
        } else if (visited[v] == 0 && cycle(v)) {
            return true;
        }
    }
    visited[u] = 2;
    return false;
}

void dfs(int u) {
    visited[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
    order.push_back(u);
}

int longest_path(int st) {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < maxn; i++) {
        dist[i] = -INF;
    }
    for (int i = 0; i <= n + maxm; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(order.begin(), order.end());
    /*for (int i = 0; i < order.size(); i++) {
        cout << order[i] << ' ';
    } cout << endl;*/
    //int t = 0;
    dist[st] = 0;
    for (int i = 0; i < order.size(); i++) {
        int u = order[i];
        if (dist[u] == -INF) continue;
        //cout << "ORDER: " <<  order[i] << ">>>>";
        for (int k = 0; k < graph[u].size(); k++) {
            int v = graph[u][k];
            int w = u - v > 0 ? u - v : 0;
            if (order[i] == st && w == 0) { //beginning of day edge case
                continue;
            }
            if (dist[u] + w > dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
        /*for (int i = 0; i < 12; i++) {
            if (dist[i] == -INF) {cout << "INF "; continue;}
            cout << dist[i] << ' ';
        } cout << endl;*/
    }
    int mx = 0;
    for (int i = 0; i <= n; i++) {
        mx = max(mx, dist[i]);
    }
    return mx;
}

//construct_graph builds graph from 0 - n inclusive
//checks cycle, if exists return -1, starting only from n
//returns longest path
//longest path = topological sorting -> then from n uses dp to calculate max distance
/*for (int i = 0; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << ' ';
        } cout << endl;
}*/
int calculate() {
    construct_graph();
    memset(visited, 0, sizeof(visited));
    bool cycle_exists = cycle(n);
    /*for (int i = n; i >= 0; i--) {
        if (!visited[i]) {
            cycle_exists |= cycle(i);
        }
    }*/
    if (cycle_exists) {
        return -1;
    }
    return longest_path(n);
}

int main() {
    freopen("candy.in", "r", stdin);
    scanf("%d %d %d %d", &n, &nopt, &f, &m);
    take.resize(nopt);
    for (int i = 0; i < nopt; i++) {
        scanf("%d", &take[i]);
    }
    memset(inc, false, sizeof(inc));
    for (int i = 0; i < f; i++) {
        int c;
        scanf("%d", &c);
        inc[c] = true;
    }
    printf("%d\n", calculate());
}
