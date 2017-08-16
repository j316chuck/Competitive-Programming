#include <bits/stdc++.h>
using namespace std;

int n, k, p;
const int INF = INT_MAX;
vector<int> a, b;
int dist[1005][2005];
int mem[2005][1005];

int dp(int key, int person) {
    if (mem[key][person] != -1) {
        return mem[key][person];
    }
    if (key < person) {
        return INF;
    }
    if (person == 0) {
        return mem[key][person] = dist[person][key];
    }
    mem[key][person] = INF;
    for (int i = key - 1; i >= 0; i--) {
        mem[key][person] = min(mem[key][person], max(dist[person][key], dp(i, person - 1)));
    }
    return mem[key][person];
}

int main() {
    //freopen("424D.in", "r", stdin);
    scanf("%d %d %d", &n, &k, &p);
    a.resize(n), b.resize(k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &b[i]);
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            dist[i][j] = abs(a[i] - b[j]) + abs(b[j] - p);
        }
    }
    memset(mem, -1, sizeof(mem));
    int ans = INF;
    for (int i = k - 1; i >= 0; i--) {
        ans = min(ans, dp(i, n - 1));
    }
    printf("%d\n", ans);
    return 0;
}
