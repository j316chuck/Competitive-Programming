#include <bits/stdc++.h>
using namespace std;

int n, k, p;
const int INF = INT_MAX;
vector<int> a, b;
int dist[1005][2005];
int dp[1005][2005];

int main() {
    //freopen("424D.in", "r", stdin);
    scanf("%d %d %d", &n, &k, &p);
    a.resize(n), b.resize(k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &b[i]);
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            dist[i][j] = abs(a[i] - b[j]) + abs(b[j] - p);
            dp[i][j] = INF;
        }
    }

    int ans = INF;
    dp[0][0] = dist[0][0];
    for (int i = 1; i < b.size(); i++) dp[0][i] = min(dp[0][i-1], dist[0][i]);
    for (int i = 1; i < a.size(); i++) {
        int mval = INF;
        for (int j = i; j < b.size(); j++) {
            mval = min(mval, dp[i-1][j-1]);
            dp[i][j] = max(dist[i][j], mval);
        }
        for (int j = i; j < b.size(); j++) {
            dp[i][j] = min(dp[i][j-1], dp[i][j]);
        }
    }
    ans = dp[n-1][k-1];
    printf("%d\n", ans);
    return 0;
}

