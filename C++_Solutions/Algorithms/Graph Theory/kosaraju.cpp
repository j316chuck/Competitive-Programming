#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3+5;
int n, m;
vector<int> graph[maxn];
vector<int> rgraph[maxn];
vector< vector<int> > components;
vector<int> torder;
bool visited[maxn];


void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
    torder.push_back(u);
}

void topological_sort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

void rdfs(int u, vector<int> &c) {
    visited[u] = true;
    for (int i = 0; i < rgraph[u].size(); i++) {
        int v = rgraph[u][i];
        if (!visited[v]){
            rdfs(v, c);
        }
    }
    c.push_back(u);
}


void kosaraju() {
    memset(visited, false, sizeof(visited));
    topological_sort();
    reverse(torder.begin(), torder.end());
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < torder.size(); i++) {
        vector<int> component;
        int u = torder[i];
        if (!visited[u]) {
            rdfs(u, component);
            components.push_back(component);
        }
    }
}

int main() {
    //freopen("kosaraju.in", "r", stdin);
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    kosaraju();
    int odd = 0, even = 0;
    for (int i = 0; i < components.size(); i++) {
        /*for (int j = 0; j < components[i].size(); j++) {
            cout << components[i][j] +1 << ' ';
        } cout << endl;*/
        if (components[i].size() % 2 == 0) even += components[i].size();
        else odd += components[i].size();
    }
    printf("%d\n", odd - even);
    return 0;
}

