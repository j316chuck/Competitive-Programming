#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
const int maxm = 1005;
int old[maxm], cur[maxm];
int h[maxn];

int main() {
    freopen("running.in", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> d(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= m; k++) {
            if (old[k-1] == 0 && k!=1) continue;
            cur[k] = old[k-1] + d[i];
        }
        for (int k = 1; k <= m; k++) {
            if (k + i >= maxn) continue;
            h[k+i] = max(h[k+i], cur[k]);
        }
        cur[0] = max(old[0], h[i]);
        for (int k = 0 ; k <= m; k++) {
            old[k] = cur[k];
        }
    }
    printf("%d\n", cur[0]);
}

