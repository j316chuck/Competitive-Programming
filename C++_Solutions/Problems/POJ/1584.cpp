/*
ID: j316chuck
PROG: 1584
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

//tells whether polygon is convex given input of ccw or cw orientation
//of a series of pts. (correct)
bool PolygonIsConvex(const vector<PT> &pts) {
    int t1 = 0, t2;
    for (int i = 0; i < pts.size(); ++i) {
        t2 = CCW(pts[i], pts[(i+1)%pts.size()], pts[(i+2)%pts.size()]);
        if (t1 * t2 < 0) return false;
        else t1 = t2;
    }
    return true;
}

//may be wrong... use stanford one
bool PointInConvexPolygon(const vector<PT> &pts, PT q) {
    int t1 = 0, t2;
    for (int i = 0; i < pts.size(); ++i) {
        t2 = CCW(pts[i], pts[(i+1)%pts.size()], q);
        if (t1 * t2 < 0) return false;
        else t1 = t2;
    }
    return true;
}

bool PointInPolygon(const vector<PT> &p, PT q) {
    bool c = 0;
    for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y ||
        p[j].y <= q.y && q.y < p[i].y) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
        c = !c;
    }
    return c;
}


// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
    return a + (b-a) * dot(c-a, b-a) / dot(b-a, b-a);
}

//checks whether circle lies in polygon.
bool CircleInPolygon(const vector<PT> &pts, PT c, double r) {
    PT project;
    for (int i = 0; i < pts.size(); ++i) {
        project = ProjectPointLine(pts[i], pts[(i+1)%pts.size()], c);
        if (dist(project, c) < r) return false;
    }
    return true;
}

int main() {

    //time_t start=clock();
    //Rd("1584.in"); //make sure to put it in the correct folder
    int n;
    double r;
    PT c;
    vector<PT> pts;
    while (scanf("%d", &n) != EOF && n >= 3) {
        scanf("%lf %lf %lf", &r, &c.x, &c.y);
        pts.clear();
        pts.resize(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &pts[i].x, &pts[i].y);
        }
        if (!PolygonIsConvex(pts)) {
            printf("HOLE IS ILL-FORMED\n");
        } else if (!PointInPolygon(pts, c) || !CircleInPolygon(pts, c, r)) {
            printf("PEG WILL NOT FIT\n");
        } else {
            printf("PEG WILL FIT\n");
        }
    }

    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




