#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4+5;
int n, m, tick, current_scc;
int low[maxn], tin[maxn], scc[maxn];
vector<int> graph[maxn];
vector<int> stk;
vector< vector<int> > components;
bool instack[maxn];

void dfs(int u) {
    stk.push_back(u);
    instack[u] = true;
    low[u] = tin[u] = ++tick;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (tin[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (instack[v]) {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (low[u] == tin[u]) {
        vector<int> component;
        while (true) {
            int x = stk.back();
            stk.pop_back();
            component.push_back(x);
            instack[x] = false;
            scc[x] = current_scc;
            if (x == u) {
                break;
            }
        }
        if (component.size() > 0) {
            components.push_back(component), current_scc++;
        }
    }
}

void tarjan() {
    tick = current_scc = 0;
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    memset(instack, false, sizeof(instack));
    stk.clear(); components.clear();
    for (int i = 0; i < n; i++) {
        if (tin[i] == -1) {
            dfs(i);
        }
    }
}

//returns number of components that are source vertexes in this unconnected graph
//does not count the number of components that only have size one
int calculate() {
    bool valid[current_scc];
    memset(valid, true, sizeof(valid));
    //invalidates components with size 1
    for (int i = 0; i < components.size(); i++) {
        if (components[i].size() < 2) {
            int u = components[i][0];
            valid[scc[u]] = false;
            continue;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int u = i;
            int v = graph[i][j];
            if (scc[u] != scc[v]) {
                valid[scc[u]] = false;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < current_scc; i++) {
        total += valid[i];
    }
    return total;
}

int main() {
    freopen("prom.in", "r", stdin);
    scanf("%d %d", &n, &m);
    int u, v;
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
    }
    tarjan();
    /*for (int i = 0; i < components.size(); i++) {
        for (int j = 0; j < components[i].size(); j++) {
            cout << components[i][j] << ' ';
        } cout << endl;
    }*/
    //calculate components
    printf("%d\n", calculate());
    return 0;
}
