#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
long long bit[2*maxn + 5];
void update(int i, int v) {
    for (; i < 2 * maxn + 5; i += (i & -i)) {
        bit[i] += v;
    }
    return;
}

long long query(int i) {
    long long sum = 0;
    for (; i > 0; i -= (i & -i)) {
        sum += bit[i];
    }
    return sum;
}

int main() {
    freopen("median.in", "r", stdin);
    //freopen("median.out", "w", stdout);
    int n, x, y; long long total = 0, psum = maxn;
    scanf("%d %d", &n, &x);
    update(psum, 1);
    for (int i = 0 ; i < n; i++) {
        scanf("%d", &y);
        psum += y >= x ? 1 : -1;
        total += query(psum);
        update(psum, 1);
    }
    printf("%lld\n", total);
}
