#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
int f[maxn]; //next value that has not been updated from position i
int getf(int x) {
    return x == f[x] ? x : f[x] = getf(f[x]);
}
int unite(int x, int y) {
    int px = getf(x), py = getf(y);
    if (px != py) {
        f[px] = f[py];
    }
}


char ans[maxn];
//solves CF423C Div 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("423C.in", "r", stdin);
    int n, mn = -1;
    for (int i = 1; i < maxn; i++) f[i] = i;
    cin >> n;
    for (int ii = 0; ii < n; ii++) {
        string x; int t, s1;
        cin >> x >> t;
        int sz = x.size();
        for (int jj = 0; jj < t; jj++) {
            cin >> s1;
            for (int i = f[s1]; i < s1 + sz; i = f[i] = getf(i+1)) {
                ans[i] = x[i - s1];
                mn = max(mn, i);
            }
        }
    }
    for (int i = 1; i <= mn; i++) {
        ans[i] ? cout << ans[i] : cout << 'a';
    }
}

