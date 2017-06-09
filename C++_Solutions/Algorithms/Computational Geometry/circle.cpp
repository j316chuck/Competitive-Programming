/*
ID: j316chuck
PROG: circle
LANG: C++
*/

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
    Point(double x = 0.0, double y = 0.0) {
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


class Circle { //passed POJ_2242
public:
    double r, x, y;
    Circle(double xx = 0, double yy = 0, double rr = 0) : x(xx), y(yy), r(rr) {}
    Circle(Point &p1, Point &p2, Point &p3) {
        double x12 = p2.x - p1.x;
        double y12 = p2.y - p1.y;
        double x13 = p3.x - p1.x;
        double y13 = p3.y - p1.y;
        double z2 = x12 * (p1.x + p2.x) + y12 * (p1.y + p2.y);
        double z3 = x13 * (p1.x + p3.x) + y13 * (p1.y + p3.y);
        double d = 2.0 * (x12 * (p3.y - p2.y) - y12 * (p3.x - p2.x));
        x = (y13 * z2 - y12 * z3) / d;
        y = (x12 * z3 - x13 * z2) / d;
        r = sqrt((p1.x - x) * (p1.x - x) + (p1.y - y) * (p1.y - y));
    }
    bool contains(const Point &p) const {
        return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)) <= r;
    }
};

double dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

ostream &operator << (ostream & os, const Circle &c) {
    os << "Circle: " << "Center: (" << c.x <<"," << c.y << "), radius = " << c.r << '\n';
    return os << "";
}

int main() {
    Point a, b, c;
    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y) {
        printf("%0.2f\n", 2 * PI * Circle(a, b, c).r);
    }
}
