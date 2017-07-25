#include <bits/stdc++.h>
using namespace std;

const int maxn = 50005;
int n;
vector<int> graph[maxn];
int dp1[maxn], dp2[maxn];

void dfs(int u, int par) {
    dp1[u] = 1;
    dp2[u] = 0;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (v != par) {
            dfs(v, u);
            dp1[u] += dp2[v];
            dp2[u] += dp1[v];
        }
    }
    dp1[u] = max(dp1[u], dp2[u]);
}

int main() {
    //freopen("visiting_cows.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(0, -1);
    printf("%d\n", max(dp1[0], dp2[0]));
}
