#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int maxn = 105;
int old[maxn][maxn];
int dp[maxn][maxn];
char graph[maxn][maxn];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, t;

bool valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && graph[r][c] != '*';
}

int main() {
    //freopen("traveling.in", "r", stdin);
    scanf("%d %d %d ", &n, &m, &t);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c ", &graph[i][j]);
        }
    }
    int sr, sc, er, ec;
    scanf("%d %d %d %d", &sr, &sc, &er, &ec);
    old[sr-1][sc-1] = 1;
    int r, c;
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == '*') continue;
                for (int k = 0; k < 4; k++) {
                    r = dx[k] + i, c = dy[k] + j;
                    if (valid(r, c)) {
                        dp[i][j] += old[r][c];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                old[i][j] = dp[i][j];
                dp[i][j] = 0;
            }
        }
    }
    printf("%d\n", old[er-1][ec-1]);
    return 0;
}
