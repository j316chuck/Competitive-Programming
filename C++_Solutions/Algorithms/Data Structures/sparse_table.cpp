#include <bits/stdc++.h>
using namespace std;

const int k = 20;
const int maxn = 1e5+5;
//rows stand for starting position, k is 1 << k indexed length (inclusive)
//0 indexed
int table[maxn][k];
int arr[maxn];

int main() {
    freopen("sparse_table.in", "r", stdin);
    int n, l, r, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        table[i][0] = arr[i];
    }
    for (int j = 1; j <= k; j++) {
        for (int i = 0; i <= n - (1 << j); i++) {
            table[i][j] = table[i][j - 1] + table[i + (1 << (j - 1))][j - 1];
        }
    }
    cin >> q;
    for (int j = 0; j < q; j++) {
        cin >> l >> r;
        int sum = 0;
        for (int i = k; i >= 0; i--) {
            if (l + (1 << i) - 1 <= r) {
                sum += table[l][i];
                l += 1 << i;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
