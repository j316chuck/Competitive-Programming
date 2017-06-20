/*
ID: j316chuck
PROG: 1228
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>
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

template <class T> void deb_array(T *arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << ' ';
    } cout << '\n';
}

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
int CCW(PT a, PT b, PT c) {
    double cr = cross(b - a, c - a);
    if (fabs(cr) < EPS) return 0;
    else if (cr > 0) return 1;
    else return -1;
}

bool ThreePointsCollinear(PT a, PT b, PT c) {
    return CCW(a, b, c) == 0;
}

void ConvexHull(vector<PT> &pts) {
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    sort(pts.begin(), pts.end());

    vector<PT> up, dn;
    for (int i = 0; i < pts.size(); ++i) {
        while(up.size() >= 2 && CCW(up[up.size() - 2], up[up.size() - 1], pts[i]) >= 0) {
            up.pop_back();
        }
        while (dn.size() >= 2 && CCW(dn[dn.size() - 2], dn[dn.size() - 1], pts[i]) <= 0) {
            dn.pop_back();
        }
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }

    pts = dn;
    for (int i = up.size() - 2; i >= 1; --i) {
        pts.push_back(up[i]);
    }
}

bool DefiniteConvexPolygon(vector<PT> &pts) {
    //vector<PT> oldpts = pts;
    if (pts.size() < 6) return false;
    ConvexHull(pts);
    int m = pts.size();
    for (int i = 0; i < pts.size(); ++i) {
        if (!ThreePointsCollinear(pts[i], pts[(i + 1) % m], pts[(i + 2) % m]) &&
            !ThreePointsCollinear(pts[(i - 1) % m], pts[i], pts[(i + 1) % m])) {
            return false;
        }
    }
    return true;
}

int main() {
    Rd("1228.in");
    int testcases, n;
    vector<PT> pts;
    scanf("%d", &testcases);
    for (int tt = 0; tt < testcases; ++tt) {
        scanf("%d", &n);
        pts.clear();
        pts.resize(n + 1);
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &pts[i].x, &pts[i].y);
        }
        if (DefiniteConvexPolygon(pts)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
