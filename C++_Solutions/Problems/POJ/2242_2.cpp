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
const double EPS = 1e-9;
typedef long long LL;
using namespace std;

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

class Circle {
public:
    double r, x, y;
    Circle(double rr, double xx, double yy) : r(rr), x(xx), y(yy) {}
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
    bool contains(Point &p) {
        return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)) <= r;
    }
};

int main() {
    Rd("2242.in");
    Point a, b, c;
    while(cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y) {
        printf("%0.2f\n", 2 * PI * Circle(a, b, c).r);
    }
}
