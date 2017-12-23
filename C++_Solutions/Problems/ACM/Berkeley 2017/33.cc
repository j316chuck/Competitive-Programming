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
//#include <bits/stdc++.h>
//#include <contest.h>
using namespace std;

const int maxn = 1e3 + 5;

const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};
int columns, rows, queries;
vector<int> result;
int cnt[maxn][maxn];
int parts = 0;
int parent[maxn][maxn];

struct pp {
    int c1, r1, c2, r2;
};

bool valid (int r, int c) {
    return r >= 1 && r <= rows && c >= 1 && c <= columns && parent[r][c] == -1 && !cnt[r][c];
}

void bfs(int row, int col, int m) {
    queue < pair<int, int> > q;
    q.push({row, col});
    int r, c, nr, nc;
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        parent[r][c] = m;
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

void color1() {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            if (cnt[i][j] == 0 && parent[i][j] == -1) {
                bfs(i, j, ++parts);
            }
        }
    }
    result.push_back(parts);
}

const int maxm = 1e6;
int mark(int row, int col, int mk) {
    set<int> s;
    queue < pair<int, int> > q;
    q.push({row, col});
    int r, c, nr, nc;
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        //cout << r << ' ' << c << ' ' << parent[r][c] << endl;
        parent[r][c] = mk;
        q.pop();
        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            if (nr >= 1 && nr <= rows && nc >= 1 && nc <= columns && !cnt[nr][nc]) {
                if (parent[nr][nc] != mk) {
                    q.push({nr, nc});
                    s.insert(parent[nr][nc]);
                }
            }
        }
    }
    s.erase(-1);
    return (int) s.size();
}

int main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    cin >> columns >> rows >> queries;
    vector<pp> q;
    for (int qq = 0; qq < queries; qq++) {
        int c1, r1, c2, r2;
        cin >> c1 >> r1 >> c2 >> r2;
        if (c1 == c2) {
            for (int i = r1; i <= r2; i++) {
                cnt[i][c1]++;
            }
        } else {
            for (int i = c1; i <= c2; i++) {
                cnt[r1][i]++;
            }
        }
        q.push_back({c1, r1, c2, r2});
    }
    memset(parent, -1, sizeof(parent));
    color1();


    //uncolor;
    int mk = 1e6 + 5;
    for (int qq = queries - 1; qq >= 0; qq--) {
        int c1 = q[qq].c1, c2 = q[qq].c2, r1 = q[qq].r1, r2 = q[qq].r2;
        if (c1 == c2) {
            for (int i = r1; i <= r2; i++) {
                cnt[i][c1]--;
            }
            for (int i = r1; i <= r2; i++) {
                if (cnt[i][c1] == 0 && parent[i][c1] == -1) {
                    int p = mark(i, c1, ++mk);
                    parts -= (p - 1);
                }
            }
        } else {
            for (int i = c1; i <= c2; i++) {
                cnt[r1][i]--;
            }
            for (int i = c1; i <= c2; i++) {
                if (cnt[r1][i] == 0 && parent[r1][i] == -1) {
                    int p = mark(r1, i, ++mk);
                    parts -= (p - 1);
                }
            }
        }

        //cout << endl;
        /*for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= columns; j++) {
                cout << parent[i][j] << ' ';
            } cout << endl;
        }*/
        //cout << parts << endl;

        result.push_back(parts);
    }

    result.pop_back();
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    } cout << endl;
    return 0;
}


