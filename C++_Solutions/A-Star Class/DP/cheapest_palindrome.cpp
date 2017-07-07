#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;
char arr[maxn];
int dp[maxn][maxn];
map<char, pair<int, int> > cost; //add and delete

int mem(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    if (arr[l] == arr[r]) {
        return dp[l][r] = mem(l+1, r-1);
    }
    char c = arr[l];
    int c1 = min(cost[c].first, cost[c].second) + mem(l+1, r);
    c = arr[r];
    int c2 = min(cost[c].second, cost[c].first) + mem(l, r-1);
    return dp[l][r] = min(c1, c2);
}

int main() {
    //freopen("palindrome.in", "r", stdin);
    int n, m;
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%c ", &arr[i]);
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = -1;
        }
    }
    char c; int add, del;
    for (int i = 0; i < n; i++) {
        scanf("%c %d %d ", &c, &add, &del);
        cost[c] = make_pair(add, del);
    }
    mem(0, m-1);
    printf("%d\n", dp[0][m-1]);
}
