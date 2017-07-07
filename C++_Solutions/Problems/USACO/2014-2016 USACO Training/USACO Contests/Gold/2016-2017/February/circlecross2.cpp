#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int bit[maxn];

long long sum(int x) {
    long long total = 0;
    for (; x > 0; x -= x & -x) {
        total += bit[x];
    }
    return total;
}

void update(int x, int val) {
    for (; x < maxn; x += x & -x) {
        bit[x] += val;
    }
}

int main () {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int cnt = n+1, c; long long total = 0;
    map<int, int> mp;
    for (int i = 0; i < 2*n; i++) {
        scanf("%d", &c);
        if (mp[c]) {
            total += sum(mp[c] - 1);
            update(mp[c], -1);
        } else {
            mp[c] = --cnt;
            update(cnt, 1);
        }
    }
    printf("%lld", total);
}

