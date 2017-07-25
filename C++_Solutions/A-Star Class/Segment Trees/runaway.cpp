#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;
const int maxm = 20;
int n;
long long max_len;
vector<int> graph[maxn];
int anc[maxn][maxm+1], ans[maxn], sub[maxn];
long long dist[maxn][maxm+1];
int dfs(int u) {
    cout << u << endl;
    ans[u] -= sub[u];
    for (int i = 0; i < graph[u].size(); i++) {
        ans[u] += dfs(graph[u][i]);
    }
    return ans[u];
}

int main() {
    freopen("runaway.in", "r", stdin);
    freopen("runaway.out", "w", stdout);
    scanf("%d %lld", &n, &max_len);
    for (int i = 0; i < maxn; i++) ans[i] = 1;
    for (int i = 0; i < maxn; i++) for (int j = 0; j <= maxm; j++) anc[i][j] = -1, dist[i][j] = -1;
    int u, v; long long w;
    for (int i = 2; i <= n; i++) {
        scanf("%d %lld", &u, &w);
        v = i-1;
        u = u-1;
        graph[u].push_back(v);
        anc[v][0] = u;
        dist[v][0] = w;
        //graph[v].push_back({u, w});
    }
    //cout << "Hi1" << endl;
    //build sparse table
    anc[0][0] = -1; dist[0][0] = 0;
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i < n; i++) {
            if (anc[i][j-1] == -1) {
                anc[i][j] = -1;
                dist[i][j] = 0;
            } else {
                anc[i][j] = anc[anc[i][j-1]][j-1];
                dist[i][j] = anc[i][j] == -1 ? 0 : dist[i][j-1] + dist[anc[i][j-1]][j-1];
            }
            //cout << i << ' ' << j << ' '<< anc[i][j] << ' ' << dist[i][j] << endl;
        } //cout << endl;
    }
    //cout << "Hi2" << endl;

    //build first non-reachable vertex in array sub
    for (int i = 0; i < n; i++) {
        int d = 0, c = i;
        for (int j = maxm; j >= 0; j--) {
            if (anc[c][j] != -1 && dist[c][j] != -1 && d + dist[c][j] <= max_len) {
                d += dist[c][j];
                c = anc[c][j];
            }
        }
        c = anc[c][0];
        if (c != -1) {
            sub[c]++;
        }
    }
    //cout << "Hi3" << endl;

    /*for (int i = 0; i < n; i++) {
        cout << sub[i] << endl;
    }*/
    dfs(0);
    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
}
