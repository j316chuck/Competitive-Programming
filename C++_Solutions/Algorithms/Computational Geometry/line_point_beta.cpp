/*
ID: j316chuck
PROG: line point beta
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

    //point-slope formula
    //y = mx + b
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

ostream &operator << (ostream & os, const Line &l) {
    os << "Line: " << l.a << "x + " << l.b << "y + " << l.c << " = 0";
    return os << "";
}

//equivalent function
bool equivalent(const int p1, const int p2) {
    return abs(p1 - p2) < EPS;
}

//perpendicular bisector between two points
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

//returns whether the two lines are parallel or not
//checks if the determinant is equal to 0
bool ParallelLine(const Line &l1, const Line &l2) {
    return (l1.a * l2.b - l2.a * l1.b == 0);
}

//lines must be parallel and a1 * c2 = a2 * c1 && b1 * c2 = b2 * c1
bool SameLine(const Line &l1, const Line &l2) {
    if (!ParallelLine(l1, l2)) return false;
    return (l1.a * l2.c - l2.a * l1.c == 0)
        && (l1.b * l2.c - l2.b * l1.c == 0);
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

int main() {
    Line l1(2, 3, 5);
    Line l2(4, 6, 10);
    Line l3(4, 6, 8);
    Line l4(4, 7, 9);
    Line l5(0, 3, 6);
    Line l6(0, 6, 12);
    cout << Line({3, 4}, {5, 6}) << endl;
    cout << Line({0, 10}, {0, 11}) << endl;
    cout << Line({3, 3}, {6, 3}) << endl;
    cout << Line({3, 4}, (LL) 10000000000) << ' ' << Line({3, 4}, 0) <<endl;
    cout << ParallelLine(l1, l2) << endl;
    cout << SameLine(l1, l2) << endl;
    cout << ParallelLine(l1, l4) << endl;
    cout << "SAME LINE: " << SameLine(l1, l3) << endl;
    cout << SameLine(l5, l6) << endl;
    cout << LineLineIntersection(l1, l4) << endl;
    cout << LineLineIntersection(Line(PT(3, 4), 2), Line(PT(3, 4), (LL) 10000000000)) << endl;
    cout << LineLineIntersection(Line(PT(3, 4), 2), Line(PT(4, 4), 2)) << endl;
    cout << LineLineIntersection(l1, Line(3, 9, 12)) << endl;
    cout << CCW(l1, {-100, -100}) << ' ' << CCW(l1, {0, 0}) << endl;
}
