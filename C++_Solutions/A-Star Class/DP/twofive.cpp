#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;
char t[maxn];
int f[6][6][6][6][6];
bool ok(int i, int moves) {
    return !t[i] || (t[i] == 'A' + moves);
}

long long dfs(int a, int b, int c, int d, int e, int moves) {
    if (moves == 25) return 1; //base case
    int &now = f[a][b][c][d][e]; //recurrence relationship
    if (now) return now;
    if (a < 5 && ok(a, moves)) {
        now += dfs(a+1, b, c, d, e, moves+1);
    } if (b < a && ok(b + 5, moves)) {
        now += dfs(a, b+1, c, d, e, moves+1);
    } if (c < b && ok(c + 10, moves)) {
        now += dfs(a, b, c+1, d, e, moves+1);
    } if (d < c && ok(d + 15, moves)) {
        now += dfs(a, b, c, d+1, e, moves+1);
    } if (e < d && ok(e + 20, moves)) {
        now += dfs(a, b, c, d, e+1, moves+1);
    }
    return now;
}

int main() {
    //freopen("twofive.in", "r", stdin);
    char c;
    scanf("%c", &c);
    if (c == 'N') {
        int n, tmp;
        scanf("%d", &n);
        for (int i = 0; i < 25; i++) {
            t[i] = 'A';
            while (true) {
                memset(f, 0, sizeof(f));
                if ((tmp = dfs(0, 0, 0, 0, 0, 0)) >= n) {
                    break;
                }
                n -= tmp;
                t[i]++;
            }
         }
        printf("%s", t);
    } else {
        char s[maxn];
        scanf("%s", s);
        int ans = 0;
        for (int i = 0; i < 25; i++) {
            for (t[i] = 'A'; t[i] < s[i]; t[i]++) {
                memset(f, 0, sizeof(f));
                ans += dfs(0, 0, 0, 0, 0, 0);
            }
        }
        printf("%d\n", ans+1);
    }
    //t[0] = 'A', t[1] = 'B', t[2] = 'C', t[5] = 'D';
    //cout << dfs(0, 0, 0, 0, 0, 0) << endl;
    return 0;
}
