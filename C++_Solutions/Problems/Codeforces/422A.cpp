#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("422A.in", "r", stdin);
    int a, b; cin >> a >> b;
    int m = min(a, b);
    long long ret = 1;
    for (int i = 1; i <= m; i++) {
        ret *= i;
    }
    cout << ret << endl;
}
