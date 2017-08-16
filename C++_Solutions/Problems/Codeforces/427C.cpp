#include <bits/stdc++.h>
using namespace std;

int psum[12][105][105];
int num[105][105];

int main() {
    //freopen("427C.in", "r", stdin);
    int n, q, c, x1, y1, s1;
    scanf("%d %d %d", &n, &q, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x1, &y1, &s1);
        psum[0][x1][y1] += s1;
        num[x1][y1]++;
        psum[c + 1 - s1][x1][y1] -= (c + 1);
    }
    for (int i = 1; i < 12; i++) {
        for (int k = 0; k < 105; k++) {
            for (int j = 0; j < 105; j++) {
                psum[i][k][j] = psum[i][k][j] + psum[i-1][k][j] + num[k][j];
            }
        }
    }
    //psums
    for (int i = 0; i < 12; i++) {
        for (int k = 0; k < 105; k++) {
            for (int j = 1; j < 105; j++) {
                psum[i][k][j] = psum[i][k][j] + psum[i][k][j-1];
            }
        }
    }
    int t, x2, y2;
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
        t %= (c + 1);
        int sum = 0;
        for (int x = x1; x <= x2; x++) {
            sum += psum[t][x][y2] - psum[t][x][y1-1];
        }
        printf("%d\n", sum);
    }
}
