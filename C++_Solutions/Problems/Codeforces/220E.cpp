#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n; long long k;
int a[maxn], b[maxn], bit[maxn];

void update(int x, int val) {
    while (x > 0) {
        bit[x] += val;
        x -= x & -x;
    }
}

long long sum(int x) {
    long long result = 0;
    while (x < maxn) {
        result += bit[x];
        x += x & -x;
    }
    return result;
}

long long rsum(int x) {
    long long result = 0;
    while (x > 0) {
        result += bit[x];
        x -= x & -x;
    }
    return result;
}

int main() {
    freopen("220E.in", "r", stdin);
    scanf("%d %I64d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b, b + n, a[i]) - b + 1;
    }
    /*for (int i = 0; i < n; i++) {
        update(a[i], 1);
        cout << sum(a[i] + 1) << endl;
    }*/
    int l = 0, r = 1;
    update(a[0], 1);
    long long inversions = 0, total = 0;
    while (r < n) {
        while (r < n) {
            inversions += sum(a[r] + 1);
            update(a[r], 1);
            r++;
            if (inversions > k) break;
            total += r - l - 1;
        }
        while (inversions > k) {
            inversions -= rsum(a[l] - 1);
            update(a[l], -1);
            l++;
        }
    }
    total += r - l;
    printf("%I64d\n", total);
}
