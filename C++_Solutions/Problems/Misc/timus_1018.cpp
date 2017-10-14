#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;
vector< pair<int, int> > graph[maxn];
int dp[maxn][maxn]; //vertex, branches
int n, q;

void dfs(int u, int par) {
    int dpv[maxn][maxn]; //cannot be global because then you are resetting dp every time. can change to 1-D to reduce complexity.
    memset(dpv, -1, sizeof(dp)); // -1 means invalid;
    dpv[0][0] = 0; //base case
    int nextchild = 1;

    for (int i = 0; i < graph[u].size(); i++) {
        int w = graph[u][i].second;
        int v = graph[u][i].first;
        if (par == v) continue;
        dfs(v, u);
        for (int j = 0; j <= q; j++) { //should be q in this case but can be n, will reduce time complexity from O(n^3) -> O(nq^2)
            if (dpv[nextchild - 1][j] != -1) {
                dpv[nextchild][j] = dpv[nextchild - 1][j];
            }
            for (int k = 0; k < j; k++) {
                if (dpv[nextchild - 1][j - (k + 1)] != -1) {
                    dpv[nextchild][j] = max(dpv[nextchild][j], dpv[nextchild - 1][j - (k + 1)] + w + dp[v][k]);
                }
            }
        }
        nextchild++;
    }

    for (int i = 0; i <= q; i++) {
        dp[u][i] = dpv[nextchild - 1][i];
    }
}



int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dfs(1, -1);
    cout << dp[1][q] << endl;
}
