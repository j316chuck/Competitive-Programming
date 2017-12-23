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

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};
const int maxn = 1e3 + 5;
int w, h, q;
bool mark[maxn][maxn];
int graph[maxn][maxn];
bool visit[maxn][maxn];


bool valid (int r, int c) {
    return r >= 1 && r <= h && c >= 1 && c <= w && !visit[r][c] && !mark[r][c];
}

void bfs(int row, int col) {
    queue < pair<int, int> > q;
    q.push({row, col});
    int r, c, nr, nc;
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        visit[r][c] = true;
        q.pop();
        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            if (valid(nr, nc)) {
                q.push({nr, nc});
            }
        }
    }
}

void solve() {
    memset(visit, false, sizeof(visit));
    int total = 0;
    for (int r = 1; r <= h; r++) {
        for (int c = 1; c <= w; c++) {
            if (!mark[r][c] && !visit[r][c]) {
                bfs(r, c);
                total++;
            }
        }
    }
    cout << total << endl;
}

int main() {
    freopen("input.in", "r", stdin);
    cin >> w >> h >> q;
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (y1 == y2) {
            for (int c = x1; c <= x2; c++) {
                mark[y1][c] = true;
            }
        } else if (x2 == x1) {
            for (int r = y1; r <= y2; r++) {
                mark[r][x1] = true;
            }
        }
        solve();
    }
    return 0;
}


