#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    scanf("%I64d %I64d", &n, &k);
    ((n / k) % 2) == 1 ? printf("YES\n") : printf("NO\n");
}
