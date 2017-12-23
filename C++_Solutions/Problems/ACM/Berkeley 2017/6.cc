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

const int maxn = 1e5 + 5;
int dp[maxn];
int n;
vector< pair<int, int> > v;

int dfs(int x) {
    if (x >= n) {
        return 0;
    } if (dp[x] != -1) {
        return dp[x];
    }

    int nx = (upper_bound(v.begin(), v.end(), make_pair(v[x].second + 1, -1)) - v.begin());
    return dp[x] = max(1 + dfs(nx), dfs(x + 1));
}

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    memset(dp, -1, sizeof(dp));
    cout << dfs(0) << endl;
    return 0;
}


