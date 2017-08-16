#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
long long cubic_root(long long a, long long b) {
    long long prod = a * b;
    long long l = 0, r = maxn;
    while (l + 1 < r) {
        long long mid = (l + r) >> 1;
        if (mid * mid * mid < prod){
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long a, b;
        scanf("%I64d %I64d", &a, &b);
        long long root = cubic_root(a, b);
        if (root * root * root != a * b) {
            puts("No");
        } else if (a % root != 0 || b % root != 0) {
            puts("No");
        } else {
            puts("Yes");
        }
    }
}
