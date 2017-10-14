#include <bits/stdc++.h>
using namespace std;

long long exp(int x) {
    if (x == 0) return 1LL;
    else if (x == 1) return 10LL;
    else if (x % 2) return 10LL * exp(x / 2) * exp(x / 2);
    else return exp(x / 2) * exp(x / 2);
}

int main() {
    //freopen("input.in", "r", stdin);
    long long n; int k;
    cin >> n >> k;
    long long x = exp(k);
    for (long long i = 1; i <= x; i++) {
        long long prod = i * n;
        if (prod % (x) == 0) {
            cout << prod << endl;
            break;
        }
    }
}

