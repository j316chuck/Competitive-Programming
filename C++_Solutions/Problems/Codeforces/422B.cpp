#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("422B.in", "r", stdin);
    string s, t;
    int n, m;
    cin >> n >> m >> s >> t;
    vector<int> ans;
    int ret = INT_MAX;
    for (int i = 0; i + n <= m; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            if (s[j] != t[j + i]) {
                tmp.push_back(j + 1);
            }
        }
        if (ret > tmp.size()) {
            ret = tmp.size();
            ans = tmp;
        }
    }
    cout << ret << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    } cout << endl;
    return 0;
}

