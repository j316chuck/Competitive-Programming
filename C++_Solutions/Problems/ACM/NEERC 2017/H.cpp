#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18 + 5;

int main() {
    //freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    vector<long long> a(n + 1), inc(n + 1), dec(n + 1), left(n + 1), right(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    inc[1] = 0;
    left[1] = a[1];
    long long mx = a[1];
    for (int i = 2; i <= n; i++) {
        inc[i] += inc[i - 1];
        if (mx >= a[i]) {
            mx++;
            inc[i] += mx - a[i];
        } else {
            mx = a[i];
        }
        left[i] = mx;
    }

    dec[n] = 0;
    right[n] = a[n];
    mx = a[n];
    for (int i = n - 1; i >= 1; i--) {
        dec[i] += dec[i + 1];
        if (mx >= a[i]) {
            mx++;
            dec[i] += mx - a[i];
        } else {
            mx = a[i];
        }
        right[i] = mx;
    }

    mx = INF;
    for (int i = 1; i <= n; i++) {
        //cout << dec[i] << ' ' << inc[i] << ' ' << right[i] << ' ' << left[i] << ' ' << a[i] << endl;
        mx = min(mx, dec[i] + inc[i] - min(right[i], left[i]) + a[i]);
    }
    cout << mx << endl;
}


