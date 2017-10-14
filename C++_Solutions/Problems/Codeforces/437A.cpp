#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    char a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int one = 0, two = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 'S' && a[i + 1] == 'F') {
            one++;
        } else if (a[i] == 'F' && a[i + 1] == 'S') {
            two++;
        }
    }
    if (one > two) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
