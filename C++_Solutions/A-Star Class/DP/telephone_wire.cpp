#include <bits/stdc++.h>
using namespace std;

const int maxh = 101;
const int maxn = 1e5+5;
const int INF = 1e9+1;
int n, c;
int h[maxn];
int old[maxh];
int cur[maxh];

int square(int x) {
    return x * x;
}

int main() {
    freopen("telephone_wire.in", "r", stdin);
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++) {
        scanf("%d", h+i);
    }
    for (int i = 1; i < maxh; i++) {
        if (h[1] > i) {
            old[i] = INF;
        } else {
            old[i] = square(h[1] - i);
        }
    }
    for (int i = 2; i <= n; i++) {
        int min_val = INF;
        for (int j = 1; j < maxh; j++) {
            int val = old[j] - c * j;
            min_val = min(min_val, val);
            cur[j] = min_val + c * j;
        }
        min_val = INF;
        for (int j = maxh-1; j >= 1; j--) {
            int val = old[j] + c * j;
            min_val = min(min_val, val);
            cur[j] = min(cur[j], min_val - c * j);
        }

        for (int j = 1; j < maxh; j++) {
            if (h[i] > j) {
                cur[j] = INF;
            } else {
                cur[j] += square(h[i] - j);
            }
        }
        for (int j = 0; j < maxh; j++) {
            old[j] = cur[j];
        }
    }
    cout << *min_element(cur+1, cur+maxh) << endl;
    return 0;
}
