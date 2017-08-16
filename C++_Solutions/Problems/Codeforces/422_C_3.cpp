#include <bits/stdc++.h>
using namespace std;

struct pp {
    int l, r, c;
    bool operator < (const pp &a) const {
        return r > a.r;
    }
};
const int maxn = 2e5 + 5;
int best[maxn];
bool cmp(const pp &a, const pp &b) {return a.l < b.l;}

int main() {
    //freopen("422C_2.in", "r", stdin);
    int n, t;
    cin >> n >> t;
    vector<pp> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].c;
    }
    memset(best, -1, sizeof(best));
    sort(a.begin(), a.end(), cmp);
    priority_queue<pp> pq;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top().r < a[i].l) {
            pp top = pq.top(); pq.pop();
            int c = top.r - top.l + 1;
            if (best[c] == -1) best[c] = top.c;
            else best[c] = min(best[c], top.c);
        }
        pq.push(a[i]);
        int x = a[i].r - a[i].l + 1;
        x = t - x;
        if (x < 0 || best[x] == -1) {
            continue;
        }
        ans = min(ans, best[x] + a[i].c);
    }
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
