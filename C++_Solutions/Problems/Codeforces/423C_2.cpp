#include <bits/stdc++.h>
using namespace std;


const int maxn = 2e6+5;
string str[maxn];
int mp[maxn]; //stores the index
char ans[maxn];
int mn;

int main() {
    //freopen("423C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n;
    memset(mp, -1, sizeof(mp));
    memset(ans, '\0', sizeof(ans));
    for (int i = 0; i < n; i++) {
        cin >> str[i] >> t;
        int index;
        for (int j = 0; j < t; j++) {
            cin >> index;
            if (mp[index] == -1 || str[mp[index]].size() < str[i].size()) {
                mp[index] = i;
            }
            mn = max(mn, (int) str[i].size() + index - 1);
        }
    }
    /*cout << mn << endl;
    for (int i = 1; i <= mn; i++) {
        cout << mp[i] << endl;
    }*/
    int r = 0;
    for (int l = 1; l <= mn; l++) {
        int index = mp[l];
        if (l > r && index == -1) {
            ans[l] = 'a';
            r++;
        } else if (l > r && index != -1) {
            for (int i = 0; i < str[index].size(); i++) {
                r++;
                ans[r] = str[index][i];
            }
        } else if (l <= r && index != -1) {
            int mr = str[index].size() + l - 1;
            if (mr > r) {
                int i = mr;
                int k = str[index].size() - 1;
                while (i > r) {
                    ans[i] = str[index][k];
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


