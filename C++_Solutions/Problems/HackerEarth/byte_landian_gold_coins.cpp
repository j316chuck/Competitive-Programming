#include <bits/stdc++.h>
using namespace std;

map<long long, long long> mp;
long long dfs(long long t) {
    if (mp[t]) return mp[t];
    if (t == 0) return 0;
    return mp[t] = max(t, dfs(t / 2) + dfs(t / 3) + dfs(t / 4));
}
int main() {
    long long t; 
    while (cin >> t) {
        cout << dfs(t) << endl;
    }
    return 0;
}
