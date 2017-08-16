#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("428A.in", "r", stdin);
    int n, k, cur, total = 0;
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        total += cur;
        k -= min(total, 8);
        total -= min(total, 8);
        if (k <= 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
