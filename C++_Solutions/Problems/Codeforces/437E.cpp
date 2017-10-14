#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    vector<long long> cost(n);
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!ms.empty() && *ms.rbegin() > cost[i]) {
            ans += *ms.rbegin() - cost[i];
            ms.erase(ms.find(*ms.rbegin()));
            ms.insert(cost[i]);
        }
        ms.insert(cost[i]);
    }
    cout << ans << endl;
}

