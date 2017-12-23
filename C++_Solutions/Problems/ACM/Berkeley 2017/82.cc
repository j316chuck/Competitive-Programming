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


const int maxn = 50;
int dp[maxn][maxn][maxn][maxn];
int n, m, r, c, t;

int dfs(int r1, int r2, int c1, int c2) {
    if (dp[r1][r2][c1][c2] != -1) {
        return dp[r1][r2][c1][c2];
    }
    dp[r1][r2][c1][c2] = 0;
    for (int i = r1 - 1; i >= 0; i--) {
        if (!dfs(i, r2, c1, c2)) {
            return dp[r1][r2][c1][c2] = 1;
        }
    }
    for (int i = r2 - 1; i >= 0; i--) {
        if (!dfs(r1, i, c1, c2)) {
            return dp[r1][r2][c1][c2] = 1;
        }
    }
    for (int i = c1 - 1; i >= 0; i--) {
        if (!dfs(r1, r2, i, c2)) {
            return dp[r1][r2][c1][c2] = 1;
        }
    }

    for (int i = c2 - 1; i >= 0; i--) {
        if (!dfs(r1, r2, c1, i)) {
            return dp[r1][r2][c1][c2] = 1;
        }
    }
    return dp[r1][r2][c1][c2];
}

int main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> t;
    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int i = 0; i < t; i++) {
        cin >> n >> m >> r >> c;
        if (dfs(r, n - 1 - r, c, m - 1 - c)) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    return 0;
}



