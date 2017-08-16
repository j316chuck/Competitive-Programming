#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int maxn = 2 * 1e5 + 5;
int l[maxn], r[maxn], cost[maxn];
vector< pair<int, int> > graph[maxn][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("422C_2.in", "r", stdin);
    int n, t;
    cin >> n >> t;
    set<int> contains;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> cost[i];
        int x = r[i] - l[i] + 1;
        graph[x][0].push_back({l[i], cost[i]});
        graph[x][1].push_back({r[i], cost[i]});
        contains.insert(x);
    }
    for (auto it = contains.begin(); it != contains.end(); it++) {
        sort(graph[*it][0].begin(), graph[*it][0].end());
        sort(graph[*it][1].begin(), graph[*it][1].end());
    }

    for (auto it = contains.begin(); it != contains.end(); it++) {
        int x = *it;
        for (int i = 1; i < graph[x][0].size(); i++) {
            graph[x][0][i].second = min(graph[x][0][i].second, graph[x][0][i-1].second);
        }
        for (int i = graph[x][1].size() - 2; i >= 0; i--) {
            graph[x][0][i].second = min(graph[x][0][i+1].second, graph[x][0][i].second);
        }
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int x = r[i] - l[i] + 1;
        x = t - x;
        if (x < 0 || graph[x][0].size()) continue;
        int p1 = lower_bound(graph[x][0].begin(), graph[x][0].end(), make_pair(l[i], -1)) - graph[x][0].begin() - 1;
        if (p1 >= 0) {
            ans = min(ans, graph[x][0][p1].second + cost[i]);
        }
        int p2 = upper_bound(graph[x][1].begin(), graph[x][1].end(), make_pair(r[i], INF)) - graph[x][1].begin();
        if (p2 < graph[x][1].size()) {
            ans = min(ans, graph[x][1][p2].second + cost[i]);
        }
    }
    if (ans != INF) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}

