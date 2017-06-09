/*
ID: j316chuck
PROG:
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

class Point {
public:
    double x, y; //may include angle...
    int idx;
    Point(double x = 0, double y = 0) {
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

class Line { //may have some bugs bc POJ_2242 no pass...
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
        if (abs(b) <= EPS) {
            return new Point(c / a, p.y);
        } else if (abs(a) <= EPS) {
            return new Point(p.x, c / b);
        }
        Line perp(p, b / a);
        return intersection_point(perp);
    }

    //distance between point and line
    double point_distance(const Point &p) {
        return abs(a * p.x + b * p.y - c) / sqrt(a * a + b * b);
    }

    //perpendicular bisector between two points on this line
    Line* perpendicular_bisector (const Point &p1, const Point &p2) {
        Point mid((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
        if (abs(a) <= EPS) {
            return new Line(mid , 0);
        } else if (abs(b) <= EPS) {
            return new Line(mid, INT_MAX);
        } else {
            return new Line(mid, b/a);
        }
    }
};

double dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

ostream &operator << (ostream & os, const Point &p) {
    os << "Point: (" << p.x << ", " << p.y;
    return os << ")";
}

ostream &operator << (ostream & os, const Line &l) {
    os << "Line: " << l.a << "x + " << l.b << "y = " << l.c;
    return os << "";
}

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

int points_in_circle(const Circle &c, const vector<Point> &points) {
    int total = 0;
    for (int i = 0; i < points.size(); i++) {
        if (c.contains(points[i])) total++;
    }
    return total;
}

ostream &operator << (ostream & os, const Circle &c) {
    os << "Circle: " << "Center: (" << c.x <<"," << c.y << "), radius = " << c.r << '\n';
    return os << "";
}

int main() {

    //time_t start=clock();
    //Rd("2693.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    Point p;
    vector<Point> points;
    while (~scanf("%lf %lf", &p.x, &p.y)) {
        points.push_back(p);
    }
    //deb(points);
    int result = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < points.size(); j++) {
            if (i == j)
                continue;
            Point mid_point((points[i].x + points[j].x) / 2, (points[i].y + points[j].y) / 2);
            double d = dist(points[i], mid_point);
            if (d - 2.5 > EPS)
                continue;
            Line line(points[i], points[j]);
            Line* perp_bisector = line.perpendicular_bisector(points[i], points[j]);
            double m = -(perp_bisector -> a / perp_bisector -> b);
            double k = sqrt((2.5 * 2.5 - d * d) / (m + 1));
            Circle c1(mid_point.x + k, mid_point.y + m * k, 2.5);
            Circle c2(mid_point.x - k, mid_point.y - m * k, 2.5);
            if (m > INF || m < -INF) {
                c1.x = mid_point.x;
                c1.y = mid_point.y - sqrt(2.5 * 2.5 - d * d);
                c2.x = mid_point.x;
                c2.y = mid_point.y + sqrt(2.5 * 2.5 - d * d);
            }
            //cout << c1 << ' ' << points[i] << points[j] << endl;
            result = max(result, points_in_circle(c1, points));
            result = max(result, points_in_circle(c2, points));
        }
    }
    printf("%I64d\n", result);
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




