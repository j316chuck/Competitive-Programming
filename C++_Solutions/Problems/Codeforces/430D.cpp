#include <bits/stdc++.h>
using namespace std;


const int maxn = 3e5 + 5;
int n, m;
int trie[20][1 << 20];

int main() {
    // freopen("input.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (!trie[0][x]) {
            for (int j = 0; j <= 19; j++) {
                trie[j][x >> j]++;
            }
        }
    }

    int x = 0, y;
    for (int i = 0; i < m; i++) {
        cin >> y;
        x ^= y;
        int ans = 0;
        for (int j = 19; j >=0; j--) {
            if (trie[j][(ans ^ x) >> j] == (1 << j)) {
                ans |= (1 << j);
            }
        }
        cout << ans << endl;
    }

}
