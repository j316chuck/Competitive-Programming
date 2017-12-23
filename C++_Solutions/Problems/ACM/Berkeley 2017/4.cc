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

const int maxn = 1e3 + 5;
long long mod = 1e9 + 7;
long long dp[maxn];
int p[maxn];

int main() {
    //freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    dp[1] = 2;
    for (int i = 2; i <= n; i++) {
        dp[i] = 2;
        for (int j = p[i]; j < i; j++) {
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dp[i];
        sum %= mod;
    }
    cout << sum << endl;
   // cout << dp[n] << endl;
    return 0;
}


