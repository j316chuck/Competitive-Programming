#include <bits/stdc++.h>
using namespace std;

struct PT{
    long long x, y;
};

int main() {
    freopen("33D.in", "r", stdin);
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<PT> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d %I64d", &v[i].x, &v[i].y);
    }
}
