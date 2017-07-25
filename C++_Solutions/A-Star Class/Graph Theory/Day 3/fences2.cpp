#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;
vector<int> graph[maxn];
vector<int> path;

void euler(int u) {
    while (graph[u].size()) {
        vector<int>::iterator it = min_element(graph[u].begin(), graph[u].end());
        int v = *it;
        graph[u].erase(it);
        graph[v].erase(find(graph[v].begin(), graph[v].end(), u));
        euler(v);
    }
    path.push_back(u);
}

int main() {
    //freopen("fences.in", "r", stdin);
    int m, u, v;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < maxn; i++) {
        if (graph[i].size()) sort(graph[i].begin(), graph[i].end()), reverse(graph[i].begin(), graph[i].end());
        /*for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << ' ';
        } cout << endl;*/
    }
    int s = -1, s1 = -1, s2 = -1;
    for (int i = 0; i < maxn; i++) {
        if (graph[i].size() == 0) continue;
        else if (graph[i].size() % 2 == 0) s = s == -1 ? i : s;
        else s1 == -1 ? s1 = i : s2 = i;
    }
    s1 == -1 ? euler(s) : euler(min(s1, s2));
    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d\n", path[i] + 1);
    }
    return 0;
}
