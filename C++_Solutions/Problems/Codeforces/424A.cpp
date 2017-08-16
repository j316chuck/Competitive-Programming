#include <bits/stdc++.h>
using namespace std;

int a[1005];
int main() {
    //freopen("424A.in", "r", stdin);
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    vector<int> inc, dec, con;
    for (int i = 0; i < n-1; i++) {
        if (a[i] < a[i+1]) {
            inc.push_back(i);
        } else if (a[i] == a[i+1]) {
            con.push_back(i);
        } else {
            dec.push_back(i);
        }
    }
    for (int i = 0; i < con.size() - 1 && !con.empty(); i++) {
        if (con[i] + 1 != con[i+1]) {
            puts("NO");
            return 0;
        }
    }

    for (int i = 0; i < inc.size() - 1 && !inc.empty(); i++) {
        if (inc[i] + 1 != inc[i+1]) {
            puts("NO");
            return 0;
        }
    }
    for (int i = 0; i < dec.size() - 1 && !dec.empty(); i++) {
        if (dec[i] + 1 != dec[i+1]) {
            puts("NO");
            return 0;
        }
    }
    if (!dec.empty() && !inc.empty() && !con.empty()) {
        if (inc.back() > dec[0] || inc.back() > con[0] || con.back() > dec[0]) {
            puts("NO");
            return 0;
        }
    } else if (!dec.empty() && !inc.empty()) {
        if (inc.back() > dec[0]) {
            puts("NO");
            return 0;
        }
    } else if (!inc.empty() && !con.empty()) {
        if (inc.back() > con[0]) {
            puts("NO");
            return 0;
        }
    } else if (!dec.empty() && !con.empty()) {
        if (con.back() > dec[0]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
