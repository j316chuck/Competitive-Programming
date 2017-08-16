#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("423A.in", "r", stdin);
    int n, a, b, half_a = 0, deny = 0;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        int t1;
        scanf("%d", &t1);
        if (t1 == 1) {
            if (a != 0) {
                a--;
            } else if (b != 0) {
                b--;
                half_a++;
            } else if (half_a != 0) {
                half_a--;
            } else {
                deny++;
            }
        } else {
            if (b != 0) {
                b--;
            } else {
                deny += 2;
            }
        }
    }
    printf("%d\n", deny);
    return 0;
}
