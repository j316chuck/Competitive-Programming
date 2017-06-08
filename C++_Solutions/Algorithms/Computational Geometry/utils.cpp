/*
ID: j316chuck
PROG: line_point
LANG: C++
*/

//TODO: Test all functions..
#include <bits/stdc++.h>
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

class Point {
public:
    double x, y; //may include angle...
    int idx;
    Point(double x, double y) {
        this -> x = x;
        this -> y = y;
    }
    Point(double x, double y, int idx) {
        this -> x = x;
        this -> y = y;
        this -> idx = idx;
    }

    bool operator == (const Point &p1) {
        return abs(p1.x - x) < EPS && abs(p1.y - y) < EPS;
    }
    // Declare operator < taking precision into account
    bool operator < (const Point& p) const {
        if(x < p.x - EPS) return true;
        if(x > p.x + EPS) return false;
        if(y < p.y - EPS) return true;
        if(y > p.y + EPS) return false;
        return false;
    }
};

class Line {
public:
    // ax + by = c;
    double a, b, c;
    Line() {a = 0; b = 0; c = 0;}
    Line(double aa, double bb, double cc) {a = aa; b = bb; c = cc;}

    //unique line between two points (most problems should have unique points)
    Line(const Point &p1, const Point &p2) {
        if (p1.x == p2.x && p1.y == p2.y) { //edge case: deal with non-unique points
            //
        } else if (p1.x == p2.x) {
            a = 1; b = 0; c = p1.x;
        } else {
            b = 1;
            a = -(p1.y - p2.y) / (p1.x - p2.x);
            c = b * p1.y + a * p1.x;
        }
    }

    //point-slope formula
    //y = mx + b
    Line(const Point &p, double m) {
        if (m > INF) {
            a = 1;
            b = 0;
            c = p.x;
            return;
        }
        a = -m;
        b = 1;
        c = a * p.x + b * p.y;
    }

    bool parallel(const Line &l) {
        return (abs(a - l.a) <= EPS && abs(b - l.b) <= EPS);
    }

    bool same_line(const Line &l) {
        return parallel(l) && abs(c - l.c) <= EPS;
    }

    Point* intersection_point(const Line &l) { //can either be array or a pointer &array[0]
        Point p(INF, INF);
        if (same_line(l)) {
            return &p;
        } else if (parallel(l)) {
            return 0; // 0 = nullptr = NULL
        }
        p.x = (l.b * c - b * l.c) / (a * l.b - l.a * b);
        p.y = (-l.a * c + a * l.c) / (a * l.b - l.a * b);
        return &p;
    }

    //Finds point closest to p lying on this line;
    Point* closest_point(const Point &p) {
        Point p_c(INF, INF);
        if (abs(b) <= EPS) {
            p_c.x = c / a;
            p_c.y = p.y;
            return &p_c;
        } else if (abs(a) <= EPS) {
            p_c.x = p.x;
            p_c.y  = c / b;
            return &p_c;
        }
        Line perp(p, b / a);
        return intersection_point(perp);
    }

    //distance between point and line
    double point_distance(const Point &p) {
        return abs(a * p.x + b * p.y - c) / sqrt(a * a + b * b);
    }
};

double dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

//returns dot product of |a-b| * |b-c|
double dot (Point &a, Point &b, Point &c) {
    Point ab(b.x - a.x, b.y - a.y);
    Point bc(c.x - b.x, c.y - b.y);
    return ab.x * bc.x + ab.y * bc.y;
}

//returns if a, b, and c are collinear
bool colinear(const Point &a, const Point &b, const Point &c) {
    return (a.x - b.x) * (a.y - c.y) == (a.x - c.x) * (a.y - b.y);
}

//cross product of |b-a|x|c-a| //is also area formula for triangle 1/2 ||b-a|x|c-a||
double cross(const Point &a, const Point &b, const Point &c) {
    Point ab(b.x - a.x, b.y - a.y);
    Point ac(c.x - a.x, c.y - a.y);
    return ab.x * ac.y - ab.y * ac.x;
}

ostream &operator << (ostream & os, const Point &p) {
    os << "Point: (" << p.x << ", " << p.y;
    return os << ")";
}

ostream &operator << (ostream & os, const Line &l) {
    os << "Line: " << l.a << "x + " << l.b << "y = " << l.c;
    return os << "";
}

int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    // point_tests
    cout << EPS << endl;
    cout << Point(3, 4) << endl;
    cout << Point(3, 4, 1) << endl;
    cout << (Point(3, 4) < Point(3, 4)) << endl;
    cout << (Point(3, 4) < Point(4, 4)) << endl;
    cout << (Point(3, 3) < Point(3, 5)) << endl; //only < and ==
    cout << (Point(3, 3) == Point(3, 3)) << ' ' << (Point(3, 3) == Point(3, 4)) << endl;

    //Line Tests
    cout << Line(Point(3, 4), Point(4, 5)) << ' ' << Line(Point(3, 4), Point(3, 5)) << ' ' << Line(Point(3, 4), Point(6, 4)) <<endl;
    cout << Line(Point(3, 4), (LL) 10000000000) << ' ' << Line(Point(3, 4), 0) <<endl;
    cout << *(Line(Point(3, 4), 2).intersection_point(Line(Point(3, 4), (LL) 10000000000))) <<endl;
    if (Line(Point(3, 4), 2).intersection_point(Line(Point(4, 5), 2)) == nullptr) {
        cout << "null" << endl;
    }
    cout << *Line(Point(3, 4), 0).closest_point(Point(3, 4)) << endl;
    cout << *Line(Point(3, 4), 0).closest_point(Point(3, 10)) << endl;
    cout << Line(Point(0, 1.25), -0.5).point_distance(Point(-3, 2)) << ' ' << 3.0 / (2 * sqrt(5)) << endl;
    cout << *Line(Point(3, 4), INF + 10).closest_point(Point(5, 10)) << endl; //okay may be a little janky
    cout << *Line(Point(1, 1), 1).closest_point(Point(-3, 3)) << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



