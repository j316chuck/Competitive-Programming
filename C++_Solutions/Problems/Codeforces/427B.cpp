#include <bits/stdc++.h>
using namespace std;

int a[10], k, sum;
char s[100005];

int main() {
    //freopen("427B.in", "r", stdin);
    scanf("%d ", &k);
    scanf("%s", s);
    int sz = strlen(s);
    for (int i = 0; i < sz; i++) {
        sum += s[i] - '0';
        a[s[i] - '0']++;
    }
    /*for (int i = 0; i < 10; i++) {
        cout << a[i] << ' ';
    } cout << endl;*/
    k -= sum;
    if (k <= 0) {
        printf("0");
        return 0;
    }
    int ret = 0;
    for (int i = 0; i < 10; i++) {
        if (k - (9 - i) * a[i] > 0) {
            k -= (9 - i) * a[i];
            ret += a[i];
        } else {
            ret += (k + 9 - i - 1) / (9 - i);
            break;
        }
    }
    printf("%d\n", ret);
    return 0;
}

