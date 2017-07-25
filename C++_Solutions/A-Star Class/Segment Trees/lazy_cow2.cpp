#include <bits/stdc++.h>
using namespace std;

struct pp {
    int bot, top, x, grass;
    bool operator < (const pp &a) const {
        return x < a.x;
    }
};
int n, k;

const int maxn = 540000;
const int INF = 1e9+1;
int mn[maxn];
int mx[maxn];
int lazy[maxn];
int seg[maxn];
vector<int> ys;
vector<pp> v;

void inc(int node, int bot, int top, int val) {
    if (mn[node] >= top || mx[node] <= bot) return;
    if (bot <= mn[node] && mx[node] <= top) {
        seg[node] += val;
        lazy[node] += val;
        for (int i = (node - 1) >> 1; i >= 0; i = (i-1) >> 1) {
            seg[i] = max(seg[2*i+1], seg[2*i+2]) + lazy[i];
        }
        return;
    }
    inc(2*node+1, bot, top, val);
    inc(2*node+2, bot, top, val);
}

int main() {
    //freopen("lazy_cow.in", "r", stdin);
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    scanf("%d %d", &n, &k);
    int g, x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &g, &x, &y);
        int xl = x - k;
        int xr = x + k;
        int llx = 2 * (xl - y) - 1;
        int lly = 2 * (xl + y) - 1;
        int urx = 2 * (xr - y) + 1;
        int ury = 2 * (xr + y) + 1;
        v.push_back({lly, ury, llx, g});
        v.push_back({lly, ury, urx, -g});
        ys.push_back(ury); ys.push_back(lly);
    }
    sort(v.begin(), v.end());
    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    /*for (int i = 0; i < ys.size(); i++) {
        cout << v[i].x << ' ';
    } cout << endl;*/
    int num = ys.size() - 1, depth;
    for (depth = 0; 1 << depth < num; depth++);
    int first = (1 << depth) - 1;
    //cout << first << endl;
    for (int i = 0; i < num; i++) {
        mn[i+first] = ys[i];
        mx[i+first] = ys[i+1];
    }
    for (int i = first-1; i >= 0; i--) {
        mn[i] = min(mn[(i << 1) + 1], mn[(i << 1) + 2]);
        mx[i] = max(mx[(i << 1) + 1], mx[(i << 1) + 2]);
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        inc(0, v[i].bot, v[i].top, v[i].grass);
        ans = max(ans, seg[0]);
        //cout << ans << endl;
    }
    printf("%d\n", ans);
    /*for (int i = 1; i <= n; i++) {
        cout << mn[i] << ' '  << mx[i] << endl;
    }*/
}

