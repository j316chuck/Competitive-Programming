#include <bits/stdc++.h>
using namespace std;

struct pp {
    int index, val;
    bool operator < (const pp &a) const {
        return val > a.val;
    }
};

const int maxn = 1e5+5;
vector<int> graph[maxn];
int pre[maxn], post[maxn], ret[maxn], counter;

void dfs(int u) {
    pre[u] = ++counter;
    for (int i = 0; i < graph[u].size(); i++) {
        dfs(graph[u][i]);
    }
    post[u] = counter;
}

int bit[maxn];
int sum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += bit[x];
        x -= x & -x;
    }
    return ret;
}

void update(int x, int val) {
    while (x < maxn) {
        bit[x] += val;
        x += x & -x;
    }
}

int main() {
    freopen("promote.in", "r", stdin);
    //freopen("promote.out", "w", stdout);
    int n;
    scanf("%d", &n);
    vector<pp> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i].val);
        v[i].index = i + 1;
    }
    sort(v.begin(), v.end());
    for (int i = 2; i <= n; i++) {
        int par;
        scanf("%d", &par);
        graph[par].push_back(i);
    }
    dfs(1);
    //for (int i = 1; i <= n; i++) { cout << pre[i] << ' ' << post[i] << endl;}
    for (int i = 0; i < n; i++) {
        ret[v[i].index] = sum(post[v[i].index]) - sum(pre[v[i].index] - 1);
        update(v[i].index, 1);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ret[i]);
    }
    return 0;
}
