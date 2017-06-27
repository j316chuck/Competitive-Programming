/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
#define endl '\n'

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-9;
typedef long long LL;
using namespace std;

struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (double c) const { return PT(x * c, y * c); }
    PT operator / (double c) const { return PT(x / c, y / c); }

    //sorts from low to high in y;
    bool operator < (const PT &p) const {
        if (p.y > y) return true;
        else if (p.y < y) return false;
        return p.x > x;
    }

    bool operator == (const PT &p) const {
         return make_pair(p.x, p.y) == make_pair(x, y);
    }
};

ostream &operator << (ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}

double dot(PT p, PT q)     { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q)   { return dot(p - q, p - q); }
double dist(PT p, PT q)    { return sqrt(dist2(p, q)); }
double cross(PT p, PT q)   { return p.x * q.y - p.y * q.x; }

// tells if the direction between ab -> bc is straight, turns left (counter clockwise), or turns right (clockwise).
// 1 if left counterclockwise turn, 0 if collinear, -1 if right clockwise turn;
//double cr = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
int CCW(PT a, PT b, PT c) {
    double cr = cross(b - a, c - a);
    if (fabs(cr) < EPS) return 0;
    else if (cr > 0) return 1;
    else return -1;
}

int num[500][500];
vector<PT> pts;

bool Below(int k, int i) {
    return fabs(pts[k].x - pts[i].x) < EPS && pts[i].y > pts[k].y;
}

bool BetweenBelow(int k, int i, int j) {
    if (pts[i].x < pts[j].x) {
        return pts[i].x < pts[k].x && pts[k].x < pts[j].x && CCW(pts[i], pts[j], pts[k]) < 0;
    } else {
        return pts[j].x < pts[k].x && pts[k].x < pts[i].x && CCW(pts[j], pts[i], pts[k]) < 0;
    }
}

int main() {

    //time_t start=clock();
    Rd("triangles.in"); //make sure to put it in the correct folder
    Wt("triangles.out");
    ios_base::sync_with_stdio(0);
    int n;
    scanf("%d", &n);
    pts.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &pts[i].x, &pts[i].y);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (pts[i].x < pts[j].x) {
            for (int k = 0; k < n; k++) if (k != i && k != j) {
                if (Below(k, i)) num[i][j]++;
                if (Below(k, j)) num[i][j]++;
                if (BetweenBelow(k, i, j)) num[i][j] += 2;
            }
            num[j][i] = -num[i][j];
        }
    }

    int ret[500];
    memset(ret, 0, sizeof(ret));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int tmp = 0;
            for (int k = 0; k < j; k++) {
                tmp = fabs(num[i][j] + num[j][k] + num[k][i])/2;
                tmp -= BetweenBelow(k, i, j);
                tmp -= BetweenBelow(i, j, k);
                tmp -= BetweenBelow(j, i, k);
                ret[tmp]++;
            }
        }
    }
    for (int i = 0; i < n - 2; i++) {
        printf("%d\n", ret[i]);
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



