#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-9;
typedef long long LL;
using namespace std;


struct PT {
    double x, y, k;
    PT(double x = 0, double y = 0) : x(x), y(y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (double c) const { return PT(x * c, y * c); }
    PT operator / (double c) const { return PT(x / c, y / c); }

    //sorts from low to high in k;
    bool operator < (const PT &p) const {
        return k - p.k < -EPS;
    }
} a, b, c, o;


ostream &operator << (ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}

double dot(PT p, PT q)     { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q)   { return dot(p - q, p - q); }
double dist(PT p, PT q)    { return sqrt(dist2(p, q)); }
double cross(PT p, PT q)   { return p.x * q.y - p.y * q.x; }


double CCW(const PT &a,const PT &b,const PT &c) {
    return cross(b-a, c-a);
}

set<PT> s;
set<PT>::iterator inc(set<PT>::iterator it) {
    if (++it == s.end()) it = s.begin(); return it;
}
set<PT>::iterator dec(set<PT>::iterator it) {
    if (it == s.begin()) it = s.end();
    return --it;
}

bool PointInSegment(const PT &a, const PT &b,const PT &c) {
    return dot((b-a), (c-a)) >= 0 && dot((b-a), (c-a)) <= dot((b-a), (b-a));
}

bool PointInPolygon(PT &p) {
    if (s.size() == 0) return false;
    set<PT>::iterator it = s.upper_bound(p);
    if (it == s.end()) it = s.begin();
    set<PT>::iterator it2 = dec(it);
    if (CCW(*it, *it2, p) < 0) return true;
    if (CCW(*it, *it2, p) == 0 && PointInSegment(*it, *it2, p)) return true;
    return false;
}

void Insert(PT &p) {
    if (PointInPolygon(p)) return;
    auto lo = s.upper_bound(p);
    if (lo == s.end()) lo = s.begin();
    auto up = dec(lo);
    /*
    for (;k=pred(u),(*k-*u)*(p-*u)>-eps; u=k) F.erase(u);
	for (;k=succ(v),(p-*v)*(*k-*v)>-eps; v=k) F.erase(v);
    */
    /*for (auto it = s.begin(); it != s.end(); it++) cout << *it << ' ';
        cout << endl;*/
    //set<PT>::iterator up2 = dec(up), lo2;
    //for (up2 = dec(up); CCW(*up2, *up, p) <= 0; up = up2) s.erase(up);
    //for (lo2 = inc(lo); CCW(*lo2, *lo, p) <= 0; lo = lo2) s.erase(lo);
    //cout << *up << *up2 << endl;
    /*while (s.size() >= 2 && CCW(*up2, *up, p) < EPS) {
        s.erase(up);
        up = up2;
        dec(up2);
    }
    lo2 = inc(lo);
    while (s.size() >= 2 && CCW(*lo, *lo2, p) < EPS) {
        s.erase(lo);
        lo = lo2;
        inc(lo2);
    }
    /*for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
	}*/
    s.insert(p);

}

int main() {
    Rd("70D.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n, t;
    cin >> n >> t >> a.x >> a.y >> t >> b.x >> b.y >> t >> c.x >> c.y;
    o.x = (a.x + b.x + c.x) / 3; o.y = (a.y + b.y + c.y) / 3;
    a.k = atan2((a.y - o.y), (a.x - o.x)), b.k = atan2((b.y - o.y), (b.x - o.x)), c.k = atan2((c.y - o.y), (c.x - o.x));
    s.insert(a); s.insert(b); s.insert(c);
    PT p;
    /*for (auto it = s.begin(); it != s.end(); it++) {
        cout << it -> k << endl;
	}*/
    for (int i = 3; i < n; i++) {
        cin >> t >> p.x >> p.y;
        p.k = atan2((p.y - o.y), (p.x - o.x));
        if (t == 1) Insert(p);
        else cout << (PointInPolygon(p) ? "YES" : "NO") << endl;
    }

    return 0;
}
