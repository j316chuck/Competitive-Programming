#include <bits/stdc++.h>
using namespace std;

char grid[101][101];
int main() {
    //freopen("423B.in", "r", stdin);
    int n, m, black = 0;
    int lx = 105, rx = -1, uy = 105, ly = -1;
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < n; i++) {
        char s[101];
        scanf("%s", s);
        for (int j = 0; j < m; j++) {
            if (s[j] == 'B') {
                black++;
                lx = min(lx, j);
                rx = max(rx, j);
                uy = min(uy, i);
                ly = max(ly, i);
            }
        }
    }
    //cout << lx << ' ' << rx << ' ' << uy << ' ' << ly << endl;
    //cout << black << endl;
    int width = rx - lx + 1;
    int height = ly - uy + 1;
    int mx = max(width, height);
    if (mx > n || mx > m) {
        printf("-1\n");
        return 0;
    } else if (black == 0) {
        printf("1\n");
        return 0;
    }  else {
        printf("%d\n", mx * mx - black);
        return 0;
    }
}

