#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("work_scheduling.in", "r", stdin);
    int n;
    scanf("%d", &n);
    map<int, vector<int> > mp;
    int d, p;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &d, &p);
        if (mp.find(d) != mp.end()) {
            mp[d].push_back(p);
        } else {
            mp[d] = vector<int>();
            mp[d].push_back(p);
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        sort((it -> second).begin(), (it -> second).end());
        reverse((it -> second).begin(), (it -> second).end());
        for (int i = 0; i < (it -> second).size(); i++) {
            cout << (it -> second)[i] << ' ';
        }cout << endl;
    }
    mp[0] = vector<int>();
    int t; long long ans = 0;
    for (auto it = next(mp.begin()); it != mp.end(); it++) {
        t = (it -> first) - (prev(it) -> first);
        for (int i = 0; i < t && i < (it -> second).size(); i++) {
            ans += 1LL * (it -> second)[i];
        }
    }
    printf("%lld\n", ans);
}





