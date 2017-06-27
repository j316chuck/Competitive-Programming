/*
ID: j316chuck
PROG: curling
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
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

struct PT{
    int x, y;
    /*bool operator < (const PT &p) {
        return y < p.y || (y == p.y && x < p.x);
    }*/
    PT(int x, int y) : x(x), y(y) {}
    PT() {}
    bool operator == (const PT &p) {
        return x == p.x && y == p.y;
    }
    bool operator < (const PT &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
};

ostream &operator << (ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
}

long long CCW(const PT &a,const PT &b, const PT &c) {
    return 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);
}

//O(n) passing in time
//changed CCW so its faster
void ConvexHull(vector<PT> pts, vector<PT> &result) {
    sort(pts.begin(), pts.end());
    vector<PT> dn, up;
    for (int i = 0; i < pts.size(); ++i) {
        while (dn.size() >= 2 && CCW(dn[dn.size() - 2], dn[dn.size() - 1], pts[i]) <= 0) {
            dn.pop_back();
        }
        while (up.size() >= 2 && CCW(up[up.size() - 2], up[up.size() - 1], pts[i]) >= 0) {
            up.pop_back();
        }
        dn.push_back(pts[i]);
        up.push_back(pts[i]);
    }
    result = dn;
    for (int i = up.size() - 2; i >= 1; --i) {
        result.push_back(up[i]);
    }
}

double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }

bool ThreePointsCollinear(PT a, PT b, PT c) {
    return CCW(a, b, c) == 0;
}

bool PointInSegment(const PT &a, const PT &b,const PT &c) {
    return ThreePointsCollinear(a, b, c) && dot((b-a), (c-a)) >= 0 && dot((b-a), (c-a)) <= dot((b-a), (b-a));
}

bool PointInConvexPolygon(const vector<PT> &pts, PT &p) {
    if (CCW(pts[pts.size()-1], pts[0], p) > 0 || CCW(pts[0], pts[1], p) > 0) {
        return false;
    }
    if (CCW(pts[pts.size()-1], pts[0], p) == 0) {
        return PointInSegment(pts[pts.size() - 1], pts[0], p);
    }
    if (CCW(pts[0], pts[1], p) == 0) {
        return PointInSegment(pts[0], pts[1], p);
    }
    //binary search so that lo becomes the point right below
    int lo = 1, hi = pts.size()-1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (CCW(pts[0], pts[mid], p) <= 0) lo = mid;
        else hi = mid;
    }
    //cout << pts[lo] << ' ' << pts[hi] << ' '<< CCW(pts[lo], pts[hi], p) << p << endl;
    if (CCW(pts[lo], pts[hi], p) > 0) {
        return false;
    }
    return true;
}



int solve(vector<PT> &a, vector<PT> &b) {
    vector<PT> hull;
    ConvexHull(a, hull);
    reverse(hull.begin(), hull.end());
    int total = 0;
    for (int i = 0; i < b.size(); i++) {
        total += PointInConvexPolygon(hull, b[i]);
    }
    return total;
}

ifstream fin("curling.in");
ofstream fout("curling.out");

int main() {

    //time_t start=clock();
    //Rd("curling.in");
    //Wt("curling.out");
    //ios_base::sync_with_stdio(0);
    int n;
    fin >> n;
    vector<PT> a(n), b(n);
    for (int i = 0; i < n; i++) {
        fin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < n; i++) {
        fin >> b[i].x >> b[i].y;
    }
    int a1 = solve(a, b);
    int a2 = solve(b, a);
    fout << a1 << ' ' << a2 << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



