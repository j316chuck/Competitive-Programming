#include <bits/stdc++.h>
using namespace std;

int main() {
    char c1, c2;
    int n;
    scanf("%c %c %d", &c1, &c2, &n);
    n = n % 4;
    if (n == 0 || n == 2) {
        printf("undefined\n");
        return 0;
    }
    int d = c1 - c2;
    if (n == 1 && (d == 32 || d == -56 || d == 58 || d == -34)) {
        printf("cw\n");
    } else if (n == 3 && (d == 32 || d == -56 || d == 58 || d == -34)) {
        printf("ccw\n");
    } else if (n == 3 && (d == 34 || d == -32 || d == 56 || d == -58)) {
        printf("cw\n");
    } else {
        printf("ccw\n");
    }
    return 0;
}
