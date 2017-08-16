#include <bits/stdc++.h>
using namespace std;

char s1[52], s2[52], s[1005];

int main() {
    //freopen("424B.in", "r", stdin);
    scanf("%s %s %s", s1, s2, s);
    for (int i = 0; i < 26; i++) {
        s1[i + 26] = s1[i] - 32;
        s2[i + 26] = s2[i] - 32;
    }
    int sz = strlen(s);
    for (int i = 0; i < sz; i++) {
        if (0 <= s[i] - '0' && s[i] - '0' <= 9) {
            printf("%d", s[i] - '0');
        } else {
            for (int j = 0; j < 52; j++) {
                if (s1[j] == s[i]) {
                    printf("%c", s2[j]);
                    break;
                }
            }
        }
    }
    return 0;
}
