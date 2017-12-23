#include <cstdlib>
#include <cstdio>
#include <climits>
#include <stdarg.h>
#include <cstring>
#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;


const int maxn = 48;
short dp[maxn][maxn][maxn][maxn];
int n, m, r, c, t;
int dfs(int r1, int r2, int c1, int c2) {
    /*if (r1 > r || r2 < r || c1 > r || c2 < r) {
        return -1;
    }*/
    if (dp[r1][r2][c1][c2] != -1) {
        //cout << "DP: " << dp[r1][r2][c1][c2] << " r1: " << r1 << " r2: " << r2 << " c1: " << c1 << " c2: " << c2 << endl;
        return dp[r1][r2][c1][c2];
    }
    dp[r1][r2][c1][c2] = 0;
    for (int i = r - 1; i >= r1; i--) {
        if (!dfs(i + 1, r2, c1, c2)) {
            //cout << "DP: " << 1 << " r1: " << r1 << " r2: " << r2 << " c1: " << c1 << " c2: " << c2 << endl;
            return dp[r1][r2][c1][c2] = 1;
        }
    }
    for (int i = r + 1; i <= r2; i++) {
        if (!dfs(r1, i - 1, c1, c2)) {
            //cout << "DP: " << 1 << " r1: " << r1 << " r2: " << r2 << " c1: " << c1 << " c2: " << c2 << endl;
            return dp[r1][r2][c1][c2] = 1;
        }
    }
    for (int i = c - 1; i >= c1; i--) {
        if (!dfs(r1, r2, i + 1, c2)) {
            //cout << "DP: " << 1 << " r1: " << r1 << " r2: " << r2 << " c1: " << c1 << " c2: " << c2 << endl;
            return dp[r1][r2][c1][c2] = 1;
        }
    }
    for (int i = c + 1; i <= c2; i++) {
        if (!dfs(r1, r2, c1, i - 1)) {
            dp[r1][r2][c1][c2] = 1;
        }
    }
    return dp[r1][r2][c1][c2];
}

int main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m >> r >> c;
        memset(dp, -1, sizeof(dp));
        dp[r][r][c][c] = 0;
        if (dfs(0, n - 1, 0, m - 1)) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
        //cout << endl << endl;
    }
    return 0;
}


