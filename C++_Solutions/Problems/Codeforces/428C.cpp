#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n;
vector<int> graph[maxn];
double ans[maxn];

void dfs(int u, int par) {
    double sz = graph[u].size() - 1;
    if (par == -1) sz++;
    for (int v : graph[u]) {
        if (v != par) {
            dfs(v, u);
            ans[u] += (1.0 + ans[v]) / sz;
        }
    }
}


int main() {
    //freopen("428C.in", "r", stdin);
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1);
    printf("%.9f", ans[1]);
}

