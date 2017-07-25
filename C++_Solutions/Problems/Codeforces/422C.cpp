#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+1;
map<int, int> mp;

int main() {
    //freopen("422C.in", "r", stdin);
    int n, x, l, r, cost;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &l, &r, &cost);
        if (mp.find(r-l+1) == mp.end()) {
            mp[r-l+1] = cost;
        } else {
            mp[r-l+1] = min(mp[r-l+1], cost);
        }
    }
    int mini = INF;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        pair<int, int> p = *it;
        if (mp[x - p.first] != 0) {
            mini = min(mini, mp[x - p.first] + p.second);
        }
    }
    mini == INF ? printf("-1\n") : printf("%d\n", mini);
}
