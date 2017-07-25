#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5;
vector<int> graph[maxn];
vector<int> visited;

int dfs(int u) {
    int sum = 1;
    visited[u] = 1;
    for (int i = 0; i < graph[u].size(); i++) {
        if (visited[graph[u][i]] == -1) {
            sum += dfs(graph[u][i]);
        }
    }
    return sum;
}

int main() {
    //freopen("ranking.in", "r", stdin);
    int n, m;
    scanf("%d %d ", &n, &m);
    visited.resize(n+1);
    //cout << n << ' ' << m << endl;
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
    }
    int sum = n * (n-1) * 0.5;
    for (int i = 1; i <= n; i++) {
        fill(visited.begin(), visited.end(), -1);
        sum -= (dfs(i) - 1);
    }
    printf("%d\n", sum);
}
