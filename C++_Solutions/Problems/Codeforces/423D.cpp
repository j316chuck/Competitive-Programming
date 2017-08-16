#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("423D.in", "r", stdin);
    int n, k;
    cin >> n >> k;
    cout << 2 * ((n - 1) / k) + min(2, (n - 1) % k) << endl;
    for (int i = 2; i <= n; i++) {
        cout << (i - k <= 1 ? 1 : i - k) << ' ' << i << endl;
    }
    return 0;
}

