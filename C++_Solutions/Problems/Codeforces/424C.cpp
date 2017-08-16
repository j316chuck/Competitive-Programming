#include <bits/stdc++.h>
using namespace std;

int k, n, a[2005], b[2005]; set<int> valid;

bool calc(int st, int &ret) {
    int mid = b[0];
    valid.clear();
    for (int i = st; i >= 0; i--) {
        valid.insert(mid);
        mid -= a[i];
    }
    ret = mid;
    mid = b[0];
    for (int i = st + 1; i < k; i++) {
        mid += a[i];
        valid.insert(mid);
    }
    for (int i = 0; i < n; i++) {
        if (valid.find(b[i]) == valid.end()) {
            return false;
        }
    }
    return true;
}

int main() {
   // freopen("424C.in", "r", stdin);
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", b + i);
    }
    set<int> ans;
    for (int i = 0; i < k; i++) {
        int ret = -1;
        if (calc(i, ret)) {
            ans.insert(ret);
        }
    }
    printf("%d\n", ans.size());
    return 0;
}

