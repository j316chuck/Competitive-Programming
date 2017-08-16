#include <bits/stdc++.h>
using namespace std;

struct pp {
    string s;
    vector<int> index;
};

const int maxn = 2e6+5;
int mp[maxn]; //stores the index
char ans[maxn];
int mn;

int main() {
    //freopen("423C.in", "r", stdin);
    int n, t;
    cin >> n;
    memset(mp, -1, sizeof(mp));
    memset(ans, '\0', sizeof(ans));
    vector<pp> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].s >> t;
        v[i].index.resize(t);
        for (int j = 0; j < t; j++) {
            cin >> v[i].index[j];
            if (mp[v[i].index[j]] == -1 || v[mp[v[i].index[j]]].s.size() < v[i].s.size()) {
                mp[v[i].index[j]] = i;
            }
            mn = max(mn, (int) v[i].s.size() + v[i].index[j] - 1);
        }
    }
    /*cout << mn << endl;
    for (int i = 1; i <= mn; i++) {
        cout << mp[i] << endl;
    }*/
    int r = 0;
    for (int l = 1; l <= mn; l++) {
        if (l > r && mp[l] == -1) {
            ans[l] = 'a';
            r++;
        } else if (l > r && mp[l] != -1) {
            for (int i = 0; i < v[mp[l]].s.size(); i++) {
                r++;
                ans[r] = v[mp[l]].s[i];
            }
        } else if (l <= r && mp[l] != -1) {
            int mr = v[mp[l]].s.size() + l - 1;
            if (mr > r) {
                int i = mr;
                int k = v[mp[l]].s.size() - 1;
                while (i > r) {
                    ans[i] = v[mp[l]].s[k];
                    i--;
                    k--;
                }
                r = mr;
            }
        }
    }
    for (int i = 1; i <= mn; i++) {
        cout << ans[i];
    } cout << endl;
}

