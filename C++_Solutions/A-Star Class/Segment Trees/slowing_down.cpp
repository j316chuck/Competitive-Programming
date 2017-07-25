#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int tin[maxn], seen[maxn], ans[maxn], n;
vector<int> graph[maxn];

void dfs(int u, int par) {
    ans[tin[u]] = 0;
    for (int i = tin[u]; i > 0; i -= i & -i) {
        ans[tin[u]] += seen[i];
    }
    for (int i = tin[u]; i < maxn; i += i & -i) {
        seen[i]++;
    }
    for (vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++) {
        if (*it != par) {
            dfs(*it, u);
        }
    }
    for (int i = tin[u]; i < maxn; i += i & -i) {
        seen[i]--;
    }
}

int main() {
    //freopen("slowing.in", "r", stdin);
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n-1; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v);
        tin[v] = i;
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
}


