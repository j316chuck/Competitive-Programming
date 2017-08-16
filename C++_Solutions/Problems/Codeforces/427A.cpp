#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("427A.in", "r", stdin);
    int s, v1, v2, t1, t2;
    scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2);
    int d1 = 2 * t1 + s * v1;
    int d2 = 2 * t2 + s * v2;
    if (d1 == d2) puts("Friendship");
    else if (d1 < d2) puts("First");
    else puts("Second");
}
