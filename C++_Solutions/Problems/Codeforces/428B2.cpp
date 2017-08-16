#include <bits/stdc++.h>
using namespace std;

int have[5], cnt[5];
int main() {
    //freopen("input.in", "r", stdin);
    int n, k, x;
    cin >> n >> k;
    have[4] = n, have[2] = 2 * n;
    for (int i = 0; i < k; i++) {
        cin >> x;
        while (x >= 3) {
            if (have[4]) {
                have[4]--;
                x -= 4;
            } else if (have[2]) {
                have[2]--;
                x-= 2;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
        if (x > 0) {
            cnt[x]++;
        }
    }
    while (cnt[2]) {
        if (have[2]) {
            have[2]--;
            cnt[2]--;
        } else if (have[4]) {
            have[4]--;
            have[1]++;
            cnt[2]--;
        } else {
            cnt[2]--;
            cnt[1]+=2;
        }
    }
    if (cnt[1] <= have[1] + have[2] + 2 * have[4]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

