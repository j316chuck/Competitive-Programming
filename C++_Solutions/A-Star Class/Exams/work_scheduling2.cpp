#include <bits/stdc++.h>
using namespace std;

struct pp {
    int t, p;
    bool operator < (const pp &a) const {
        return p > a.p || p == a.p && t < a.t;
    }
};

map<int, int> mp;
int Find(int x) {
    if (mp[x] == 0) {
        return x;
    } else if (mp[x] == -1) return x;
    return mp[x] = Find(mp[x]);
}

int main() {
    freopen("work_scheduling.in", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<pp> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].t, &v[i].p);
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    int x;
    for (int i = 0; i < n; i++) {
        x = Find(v[i].t);
        if (mp[x] == 0) {
            ans += v[i].p;
            mp[x] = x-1;
            if (x == 1) {
                mp[x] = -1;
            }
        }
    }
    printf("%lld\n", ans);
}






