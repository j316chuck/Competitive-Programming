/*
ID: j316chuck
PROG: 2540
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

// line: a*x + b*y + c = 0
struct Line {
    double a, b, c;
    Line() {}
    Line(double a, double b, double c) : a(a), b(b), c(c) {}

    //unique line between two points (most problems should have unique points)
    Line(const PT &p1, const PT &p2) {
        if (p1.x == p2.x && p1.y == p2.y) { //edge case: deal with non-unique points
            //
        } else if (p1.x == p2.x) {
            a = 1; b = 0; c = -p1.x;
        } else {
            b = 1;
            a = -(p1.y - p2.y) / (p1.x - p2.x);
            c = -(a * p1.x) - (b * p1.y);
        }
    }

    //point-slope formula, y = mx + b
    Line(const PT &p, double m) {
        if (m > INF) {
            a = 1;
            b = 0;
            c = -p.x;
            return;
        }
        a = -m;
        b = 1;
        c = -(a * p.x + b * p.y);
    }
};

bool equivalent(const double p1, const double p2) {
    return fabs(p1 - p2) < EPS;
}

ostream &operator << (ostream & os, const Line &l) {
    os << "Line: " << l.a << "x + " << l.b << "y + " << l.c << " = 0";
    return os << "";
}

Line bisector(PT p1, PT p2) {
     Line line;
     if (equivalent(p1.x, p2.x)) {
        line.a = 0.0, line.b = 1.0, line.c = - (p1.y  + p2.y) / 2.0;
     } else if (equivalent(p1.y, p2.y)) {
        line.a = 1.0, line.b = 0.0, line.c = - (p1.x + p2.x) / 2.0;
     } else {
        double k = - (p2.x - p1.x) / (p2.y - p1.y);
        double cx = (p1.x + p2.x) / 2.0;
        double cy = (p1.y + p2.y) / 2.0;
        double b = cy - k * cx;
        line.a = k, line.b = -1, line.c = b;
     }
     return line;
}

//direction between Point and Line
//CCW = 1 if line makes left or counterclockwise turn: a(p.x) + b(p.y) + c <= 0
//CCW = 0 if point is on line or a(p.x) + b(p.y) + c = 0;
//CCW = -1 if line makes right or clockwise turn: a(p.x) + b(p.y) + c >= 0;
int CCW(Line &l, const PT &p) {
    int dir = l.a * p.x + l.b * p.y + l.c;
    if (dir < 0) return 1;
    else if (equivalent(dir,  0)) return 0;
    else return -1;
}

PT LineLineIntersection(const Line &l1, const Line &l2) {
    double det = l1.a * l2.b - l2.a * l1.b;
    //Edge case that lines are parallel or same
    if (det == 0) {
        return PT(INF, INF);
    } else {
        double x = l2.b * l1.c - l1.b * l2.c;
        double y = l1.a * l2.c - l2.a * l1.c;
        return PT(-x / det, -y / det);
    }
}

// tells if the direction between ab -> bc is straight, turns left (counter clockwise), or turns right (clockwise).
// 1 if left counterclockwise turn, 0 if collinear, -1 if right clockwise turn;
int CCW(PT a, PT b, PT c) {
    double cr = cross(b - a, c - a);
    if (fabs(cr) < EPS) return 0;
    else if (cr > 0) return 1;
    else return -1;
}

void ConvexHull(vector<PT> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<PT> dn, up;
    for (int i = 0; i < pts.size(); ++i) {
        while (dn.size() >= 2 && CCW(dn[dn.size() - 2], dn[dn.size() - 1], pts[i]) <= 0) {
            dn.pop_back();
        } while (up.size() >= 2 && CCW(up[up.size() - 2], up[up.size() - 1], pts[i]) >= 0) {
            up.pop_back();
        }
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = up.size() - 2; i >= 1; --i) {
        pts.push_back(up[i]);
    }
}

// computes area of a polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.
double ComputeSignedArea(const vector<PT> &p) {
    if (p.size() <= 2) return 0;
    double area = 0;
    for(int i = 1; i < p.size() - 1; i++) {
        area += cross(p[i] - p[0], p[i + 1] - p[0]);
    }
    return area / 2.0;
}

double IntersectingHalfPlanes(const vector<Line> &lns) {
    PT p;
    vector<PT> pts;
    for (int i = 0; i < lns.size(); ++i) {
        for (int j = i + 1; j < lns.size(); ++j) {
            p = LineLineIntersection(lns[i], lns[j]);
            bool flag = true;
            for (int k = 0; k < lns.size(); ++k) {
                if (lns[k].a * p.x + lns[k].b * p.y + lns[k].c > 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) pts.push_back(p);
        }
    }
    ConvexHull(pts);
    return fabs(ComputeSignedArea(pts));
}


int main() {

    //time_t start=clock();
    Rd("2540.in"); //make sure to put it in the correct folder
    char str[100];
    PT prev(0.0, 0.0), next, ccw;
    double area = -1;
    vector<Line> lns;
    lns.push_back(Line(1, 0, -10));
    lns.push_back(Line(0, 1, -10));
    lns.push_back(Line(-1, 0, 0));
    lns.push_back(Line(0, -1, 0));

    while (~scanf("%lf %lf %s", &next.x, &next.y, str)) {
        if (strcmp(str, "Same") == 0 || abs(area) < EPS) {
            area = 0.00;
            printf("0.00\n");
            continue;
        }
        Line bisect = bisector(prev, next);
        ccw = next;
        if (strcmp(str, "Colder")) {
            ccw = prev;
        }
        //right turn meaning ax + by + c >= 0 thus you need to reverse sign of line
        if (CCW(bisect, ccw) < 0) {
            bisect.a = -bisect.a, bisect.b = -bisect.b, bisect.c = -bisect.c;
        }
        lns.push_back(bisect);
        area = IntersectingHalfPlanes(lns);
        printf("%.2f\n", area);
        prev = next;
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




