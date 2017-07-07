#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int cnt[maxn];
int input[maxn];

int main() {
    //freopen("632D.in", "r", stdin);
    int n, m, a;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        input[i] = a;
        cnt[a > m ? 0 : a]++;
    }

    //20 million iterations or less m (1 + 1/2 + 1/3 ... 1/100000)
    for (int i = m; i >= 1; i--) {
        for (int j = 2; j * i <= m; j++) if (cnt[i]) {
            cnt[i*j] += cnt[i];
        }
    }

    int lcm = 1, k = 0;
    for (int i = 1; i <= m; i++) {
        if (k < cnt[i]) {
            k = cnt[i];
            lcm = i;
        }
    }
    printf("%d %d\n", lcm, k);
    for (int i = 0; i < n; i++) {
        if (lcm % input[i] == 0) {
            printf("%d ", i+1);
        }
    }
    printf("\n");
}
