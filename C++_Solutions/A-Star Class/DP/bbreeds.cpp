#include <bits/stdc++.h>
using namespace std;

//1. states are the states i, starting from 0 and a starting from 0 and B starting from 0
//2. states can transition from i , a, b = f(i+1, a+1, b) + f(i+1, b+1, a)
//3. end case/base = i = n; done;
//4. but to reduce states start from O = O[i-1] += S[i];
const int maxn = 1005;
int dp[maxn][maxn];
string s;

int mem(int a, int i, int *open, int n) {
    if (i >= n) {
        return 1;
    }
    if (dp[i][a] != -1) {
        return dp[i][a];
    }
    int b = open[i] - a;
    if (s[i] == '(') {
        return dp[i][a] = (mem(a+1, i+1, open, n) + mem(a, i+1, open, n))%2012;
    } else {
        dp[i][a] = 0;
        if (b > 0) {
            dp[i][a] += mem(a, i+1, open, n);
        }
        if (a > 0) {
            dp[i][a] += mem(a-1, i+1, open, n);
        }
        dp[i][a] = dp[i][a] % 2012;
        return dp[i][a] ;
    }
}

int main() {
    freopen("bbreeds.in", "r", stdin);
    freopen("bbreeds.out", "w", stdout);
    cin >> s;
    int n = s.length();
    int open[n+1];
    memset(open, 0, sizeof(open));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = -1;
    for (int i = 0; i < n; i++) {
        open[i+1] = open[i] + (s[i] == '(' ? 1 : -1);
    }
    cout << mem(0, 0, open, n) << endl;
}
