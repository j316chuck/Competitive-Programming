#include <bits/stdc++.h>
using namespace std;

struct pp {
    int x, y;
};

const int maxn = 35;
const int INF = 1e9+5;
int graph[maxn][maxn][maxn][maxn];
int mx, my, kx, ky;
vector<pp> pts;
pair<int, int> best[maxn][maxn];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

bool valid(int x, int y) {
    return 1 <= x && x <= mx && 1 <= y && y <= my;
}

void bfs(int y, int x) {
    graph[y][x][y][x] = 0;
    queue<pp> q;
    q.push({x, y});
    pp top;
    int nx, ny;
    while (!q.empty()) {
        top = q.front();
        q.pop();
        for (int k = 0; k < 8; k++) {
            nx = dx[k] + top.x;
            ny = dy[k] + top.y;
            if (valid(nx, ny) && graph[y][x][ny][nx]  == -1) {
                graph[y][x][ny][nx] = graph[y][x][top.y][top.x] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    freopen("camelot.in", "r", stdin);
    scanf("%d %d ", &my, &mx);
    char c; int y;
    scanf("%c %d ", &c, &ky);
    kx = c - 'A' + 1;
    for (int i = 0; i < maxn; i++)
    for (int j = 0; j < maxn; j++)
    for (int k = 0; k < maxn; k++)
    for (int l = 0; l < maxn; l++)
        graph[i][j][k][l] = -1;

    for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++) best[i][j] = make_pair(-1, INF);

    while (~scanf("%c %d ", &c, &y)) {
        pts.push_back({c - 'A' + 1, y});
    }
    if (pts.size() <= 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= my; i++) {
        for (int j = 1; j <= mx; j++) {
            bfs(i, j);
        }
    }
    int ret = INF, sum, counter, mini, p, curx, cury;
    bool valid = true;
    int lx = kx - 2 >= 1 ? kx - 2 : 1;
    int rx = kx + 2 <= mx ? kx + 2 : mx;
    int ly = ky - 2 >= 1 ? ky - 2 : 1;
    int ry = ky + 2 <= my ? ky + 2 : my;
    for (int i = 1; i <= my; i++) {
        for (int j = 1; j <= mx; j++) {
            sum = 0;
            valid = true;
            for (int k = 0; k < pts.size(); k++) {
                curx = pts[k].x;
                cury = pts[k].y;
                sum += graph[i][j][cury][curx];
                valid = valid & graph[i][j][cury][curx] >= 0;
            }
            if (!valid) continue;
            mini = 1e9+1;
            for (int y = ly; y <= ry; y++) {
                for (int x = lx; x <= rx; x++) {
                    for (int k = 0; k < pts.size(); k++) {
                        if (graph[y][x][pts[k].y][pts[k].x] < 0) continue;
                        counter = max(abs(kx - x), abs(ky - y)) + graph[y][x][i][j] + graph[y][x][pts[k].y][pts[k].x] - graph[i][j][pts[k].y][pts[k].x];
                        if (counter < mini) {
                            mini = counter;
                        }
                    }
                }
            }
            sum += mini;
            ret = min(ret, sum);
        }
    }
    printf("%d\n", ret);
}

