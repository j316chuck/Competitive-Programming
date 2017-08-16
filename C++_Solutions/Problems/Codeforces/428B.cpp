#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > m = {{4, 0}, {3, 1}, {2, 2}, {1, 3}, {0, 4}};
int moves[401][401];
void bfs() {
    queue< pair<int, int> > pq;
    memset(moves, -1, sizeof(moves));
    pq.push({0, 0});
    moves[0][0] = 0;
    while (!pq.empty()) {
        pair<int, int> top = pq.front();
        pq.pop();
        for (int i = 0; i < m.size(); i++) {
            int x = top.first + m[i].first;
            int y = top.second + m[i].second;
            if (x < 401 && y < 401 && moves[x][y] == -1) {
                moves[x][y] = moves[top.first][top.second] + 1;
                pq.push({x, y});
            }
        }
    }
}

const int INF = 1e9+1;
int n, k;
bool solve(int one, int two) {
    int mo = INF;
    for (int i = max(0, one); i < 401; i++) {
        for (int j = max(0, two); j < 401; j++) {
            if (moves[i][j] != -1) {
                mo = min(moves[i][j], mo);
            }
        }
    }
    return mo <= k;
}

bool solve(int one, int two, int four) {
    k -= (four + 1) / 2;
    four = four % 2;
    if (k < 0) return false;
    if (four) {
        return solve(one - 1, two - 1) || solve(one - 2, two) || solve(one, two - 2);
    } else {
        return solve(one, two);
    }
}

int a[5];
int main() {
    //freopen("428B.in", "r", stdin);
    bfs();
    cin >> k >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        while (v[i] >= 8) {
            v[i] -= 8;
            k--;
        }
        if (v[i] == 7) {
            a[4]++; a[3]++;
        } else if (v[i] == 6) {
            a[4]++; a[2]++;
        } else if (v[i] == 5) {
            a[4]++; a[1]++;
        } else {
            a[v[i]]++;
        }
    }
    for (int i = 0; i <= a[3]; i++) {
        if (solve (a[1] + i, a[2] + i, a[4] + a[3] - i)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
