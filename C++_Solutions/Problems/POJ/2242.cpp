/*
ID: j316chuck
PROG: 2242
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
const double EPS = pow(10, -5);
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

class Point {
public:
    double x, y;
    Point(double xx, double yy) {x = xx; y = yy;}
};

ostream &operator << (ostream & os, const Point p) {
    os << "Point: (" << p.x << ", " << p.y;
    return os << ")";
}

class Line {
public:
    // ax + by = c;
    double a, b, c;
    Line() {a = 0; b = 0; c = 0;}
    Line(double aa, double bb, double cc) {a = aa; b = bb; c = cc;}

    //unique line between two points
    Line(const Point &p1, const Point &p2) {
        if (p1.x == p2.x && p1.y == p2.y) { //edge case figure out how to deal (most of time is noncollinear)
            //
        } else if (p1.x == p2.x) {
            a = 1; b = 0; c = p1.x;
        } else {
            b = 1;
            a = -(p1.y - p2.y) / (p1.x - p2.x);
            c = b * p1.y + a * p1.x;
        }
    }

    Line(const Point &p, double m) {
        if (isinf(m)) {
            a = 1;
            b = 0;
            c = p.x;
            return;
        }
        a = -m;
        b = 1;
        c = a * p.x + b * p.y;
    }

    bool parallel(Line l) {
        return (abs(a - l.a) <= EPS && abs(b - l.b) <= EPS);
    }
    bool same_line(Line l) {
        return parallel(l) && abs(c - l.c) <= EPS;
    }

    Point* intersection_point(Line l) { //can either be array or a pointer &array[0]
        Point p(INF, INF);
        if (same_line(l)) {
            return &p;
        } else if (parallel(l)) {
            return nullptr;
        }
        p.x = (l.b * c - b * l.c) / (a * l.b - l.a * b);
        p.y = (-l.a * c + a * l.c) / (a * l.b - l.a * b);
        return &p;
    }

    //To Do: Finds point closest to p lying on this line;
    Point* closest_point(Point p);
};

ostream &operator << (ostream & os, const Line l) {
    os << "Line: " << l.a << "x + " << l.b << "y = " << l.c;
    return os << "";
}

double dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    //Rd("2242.in");
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
        Point a(x1, y1);
        Point b(x2, y2);
        Point c(x3, y3);
        Line l1(Point((a.x + b.x) / 2.0, (a.y + b.y) / 2.0), -(a.x - b.x) / (a.y - b.y));
        Line l2(Point((b.x + c.x) / 2.0, (b.y + c.y) / 2.0), -(b.x - c.x) / (b.y - c.y));
        Point *intersect = l1.intersection_point(l2);
        printf("%.2f\n", dist(*intersect, a) * 2.0 * PI);
    }

    //Tests:
    //cout << l1 << endl;
    //cout << l2 << endl;
    /*Line x(Point(3, 4), Point(4, 5));
    cout << x << endl;
    cout << x.parallel(Line(Point(3, 4), 1.0))<< endl;
    Point *p = (x.intersection_point(Line(Point(3, 8), 2.0))); //
    if (p == nullptr) cout << "NULL" << endl;
    else cout << *p << endl;
    Point *p1 = (Line(Point(0, 4), 3)).intersection_point(Line(Point(0, 0), 1)); //
    cout << *p1 << endl; */
    //cout << a << '\n' << b << '\n' << c << '\n';
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}


