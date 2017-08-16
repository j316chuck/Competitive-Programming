#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
short f[maxn][maxn];
bool mark[maxn][maxn];
int ans[maxn];
string s;

int main() {
    //freopen("427D.in", "r", stdin);
    cin >> s;
    for (int len = 1; len <= s.length(); len++) {
        for (int i = 0; i + len <= s.length(); i++) {
            int j = i + len - 1;
            if ((len == 1 || len == 2 || mark[i+1][j-1]) && s[i] == s[j]) {
                mark[i][j] = true;
                if (len == 1) {
                    f[i][j] = 1;
                } else {
                    f[i][j] = f[(i + j) / 2 + 1][j] + 1;
                }
                ans[f[i][j]]++;
            }
        }
    }
    for (int i = s.length(); i >= 1; i--) {
        ans[i] += ans[i + 1];
    }
    for (int i = 1; i <= s.length(); i++) {
        cout << ans[i] << ' ';
    } cout << endl;
}
