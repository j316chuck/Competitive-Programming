#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("taking_turns.in", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = n-1; i >= 0; i--) {
        scanf("%d", &v[i]);
    }
    //base case where i = 0;
    long long mx = v[0], mn = 0, tmp;
    for (int i = 1; i < n; i++) {
        if (mx <= v[i] + mn) {
            tmp = mn;
            mn = mx;
            mx = v[i] + tmp;
        }
    }
    printf("%lld %lld\n", mx, mn);
    return 0;
}
