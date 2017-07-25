#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5;
int n, m;
vector<int> graph[maxn];
vector<int> cutpoints;
vector< pair<int, int> > bridges;
int low[maxn];
int tin[maxn];
vector<int> stk;
vector< vector<int> > bcc;
vector<int> component;
int t;

void dfs(int u, int par) {
    low[u] = tin[u] = ++t;
    //cout << u << ' ' << low[u] << ' ' << tin[u] << endl;
    stk.push_back(u);
    int child = 0, v;
    bool cut = false;
    for (int i = 0; i < graph[u].size(); i++) {
        v = graph[u][i];
        if (v == par) continue;
        if (low[v] == -1) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            child++;
            cut |= (par != -1 && low[v] >= tin[u]);
            if (low[v] > tin[u]) {
                if (v > u) bridges.push_back(make_pair(u, v));
                else bridges.push_back(make_pair(v, u));
            }
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
    cut |= (child > 1 && par == -1);
    if (cut) cutpoints.push_back(u);
    //cout << u << ' ' << low[u] << ' ' << tin[u] << endl;

    if (low[u] == tin[u]) {
        component.clear();
        while (true) {
            int x = stk.back();
            stk.pop_back();
            component.push_back(x);
            if (x == u) break;
        }
        bcc.push_back(component);
    }
}

void init() {
    t = 0;
    memset(low, -1, sizeof(low));
    memset(tin, -1, sizeof(tin));
}

int main() {
    freopen("cutpoints.in", "r", stdin);
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    init();
    for (int i = 0; i < n; i++) {
        if (low[u] == -1) {
            dfs(u, -1);
        }
    }
    sort(bridges.begin(), bridges.end());
    sort(cutpoints.begin(), cutpoints.end());
    int odd = 0, even = 0;
    for (int i = 0; i < bcc.size(); i++) {
        if (bcc[i].size() % 2 == 0) even++;
        else odd++;
        //cout << bcc[i].size() << endl;
        /*for (int j = 0; j < bcc[i].size(); j++) {
            cout << bcc[i][j] << ' ';
        } cout << endl;*/
    }
    printf("%d %d\n", odd, even);
    /*printf("%d\n", cutpoints.size());
    for (int i = 0; i < cutpoints.size(); i++) {
       printf("%d ", cutpoints[i]);
    }
    printf("\n%d\n", bridges.size());
    for (int i = 0; i < bridges.size(); i++) {
        printf("%d %d\n", bridges[i].first, bridges[i].second);
    }*/
}
