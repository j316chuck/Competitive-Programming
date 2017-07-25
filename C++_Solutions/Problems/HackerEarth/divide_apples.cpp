#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("divide_apples.in", "r", stdin);
    int n; vector< pair<int, int> > st;
    long long total = 0;
    scanf("%d", &n); vector<int> v(3*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        v[i + n] = v[i];
        v[i + 2 *n] = v[i];
        total += v[i];
    }

    int expected = total / n;
    vector<int> d(3*n);
    for (int i = 0; i < 3*n; i++) {
        d[i] = v[i] - expected;
        if (d[i] > 0) {
            st.push_back({i, d[i]});
        }
    }
    sort(st.begin(), st.end());
    for (int i = 0; i < n; i++) {
        while (d[i] < 0) {
            auto it = upper_bound(st.begin(), st.end(), make_pair(i, d[i]));
            auto it2 = it--;
            int d1 = abs(it -> first) - i;
            int d2 = abs(it2 -> first) - i;
            if (d1 <= d2)) {

            } else {

            }
        }
    }

    return 0;
}

