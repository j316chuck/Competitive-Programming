#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
const int INF = 2e9 + 10;
int n, k, m, sum, ans;
int a[maxn];

int solve(int total, int used) {
    int ret = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n - used; j++) {
            total -= a[i];
            if (total < 0) return ret;
            else ret++;
        }
    }
    return ret;
}

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + k);
    for (int i = 0; i <= n; i++) {
        if (m - (sum * i) >= 0) {
            ans = max(ans, solve(m - sum * i, i) + i * (k + 1));
        }
    }
    cout << ans << endl;
}
