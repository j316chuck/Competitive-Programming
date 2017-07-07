#include <bits/stdc++.h>
using namespace std;

struct PT{
    int x, y; char c;
    bool operator < (const PT &p) const {
        return x < p.x || x == p.x && y < p.y;
    }
};

int maxcnt = -1, maxarea = 1e9;
vector<PT> pts;

/*void update(int l, int r, int dn, int up) {
    int cnt = 0;
    int area = abs(up - dn);
    int xleft = pts[l].x;
    int xright = pts[r].x;
    //middle sweep;
    for (int i = lower_bound(pts.begin(), pts.end(), pts[l]) - pts.begin(); i != pts.size(); i++) {
        if (pts[r] < pts[i]) {
            break;
        } else if (pts[i].y > up || pts[i].y < dn) {
            continue;
        } else if (pts[i].c == 'G') {
            return;
        } else {
            cnt++;
        }
    }
    //left sweep
    for (int a = lower_bound(pts.begin(), pts.end(), pts[l]) - pts.begin(); a >= 0; ) {
        int b = a;
        bool brk = false;
        int counter = 0;
        while (b >= 0 && pts[b].x == pts[a].x) {
            if (pts[b].y < dn || pts[b].y > up) {
                continue;
            } else if (pts[b].y == 'H') {
                counter++;
            } else {
                brk = true;
                break;
            }
            b--;
        }
        if (brk) break;
        cnt += counter;
        xleft = pts[a].x;
        a = b;
    }
    //right sweep
    for (int a = lower_bound(pts.begin(), pts.end(), pts[r]) - pts.begin(); a < pts.size(); ) {
        int b = a;
        bool brk = false;
        int counter = 0;
        while (b < pts.size() && pts[b].x == pts[a].x) {
            if (pts[b].y < dn || pts[b].y > up) continue;
            else if (pts[b].y == 'H') counter++;
            else {
                brk = true;
                break;
            }
            b++;
        }
        if (brk) break;
        cnt += counter;
        xright = pts[a].x;
        a = b;
    }
    area = area * (xright - xleft);
    if (cnt > maxpts || cnt == maxpts && maxarea > area) {
        maxpts = cnt;
        maxarea = area;
    }
}*/

bool cmp(const PT &p1, const PT &p2) {
    return p1.y < p2.y || p2.y == p1.y && p1.x < p2.x;
}

int main() {
    freopen("cowrect.in", "r", stdin);
    freopen("cowrect.out", "w", stdout);
    int n;
    scanf("%d", &n);
    pts.resize(n);
    vector<int> ysort(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %c", &pts[i].x, &pts[i].y, &pts[i].c);
        ysort[i] = pts[i].y;
    }
    sort(ysort.begin(), ysort.end());
    sort(pts.begin(), pts.end());
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            bool valid = false;
            int lastx = -1;
            int cnt = 0;
            for (int a = 0; a < n; ) {
                int b = a;
                int good = 0, bad = 0;
                while (b < n && pts[b].x == pts[a].x) {
                    if (pts[b].y >= ysort[i] && pts[b].y <= ysort[j]) {
                        if (pts[b].c == 'G') {
                            bad++;
                        } else {
                            good++;
                        }
                    }
                    b++;
                }
                if (bad > 0) {
                    valid = false;
                    cnt = 0;
                } else if (bad + good > 0) {
                    if (!valid) {
                        valid = true;
                        lastx = pts[a].x;
                    }
                    cnt += good;
                    int area = (pts[a].x - lastx) * (ysort[j] - ysort[i]);
                    if (cnt > maxcnt || (cnt == maxcnt && area < maxarea)) {
                        maxcnt = cnt;
                        maxarea = area;
                    }
                }
                a = b;
            }
        }
    }
    printf("%d\n%d\n", maxcnt, maxarea);
}
