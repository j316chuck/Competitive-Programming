#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
int m;
vector<int> ngraph[maxn];
vector<int> graph[maxn];
set< pair<int, int> > used;
vector<int> path;
set < pair<int, int> > edges;

void construct_graph() {
    for (int i = 0; i < maxn; i++) {
        graph[i].clear();
        for (int j = 0; j < ngraph[i].size(); j++) {
            graph[i].push_back(ngraph[i][j]);
        }
    }
}

void euler(int u) {
    while (graph[u].size()) {
        int v = graph[u].back();
        graph[u].pop_back();
        if (used.find(make_pair(u, v)) != used.end()) {
            continue;
        }
        used.insert(make_pair(u, v));
        used.insert(make_pair(v, u));
        euler(v);
    }
    path.push_back(u);
    cout << "VECTOR>>>";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] + 1 << ' ';
    } cout << endl;
}

bool valid() {
    for (int i = 0; i + 1 < path.size(); i++) {
        int u = path[i], v = path[i+1];
        if (edges.find(make_pair(u, v)) == edges.end()) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("fences.in", "r", stdin);
    scanf("%d", &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        ngraph[u].push_back(v);
        ngraph[v].push_back(u);
        edges.insert(make_pair(u, v));
        edges.insert(make_pair(v, u));
    }
    for (int i = 0; i < maxn; i++) {
        if (ngraph[i].size()) {
            sort(ngraph[i].begin(), ngraph[i].end());
            reverse(ngraph[i].begin(), ngraph[i].end());
        }
    }
    for (int i = 0; i < maxn; i++) {
        path.clear();
        used.clear();
        construct_graph();
        euler(i);
        if (valid()) {
            reverse(path.begin(), path.end());
            for (int i = 0; i < path.size(); i++) {
                printf("%d\n", path[i]+1);
            }
            break;
        }
    }
    return 0;
}
