/*
ID: j316chuck
PROG: 3525
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
const double EPS = 1e-8;

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

int sgn(double x) {
    if(fabs(x) < EPS) return 0;
    if(x < 0) return -1;
    return 1;
}

struct Point {
    double x, y;
    Point(){}
    Point(double xx, double yy) : x(xx), y(yy){} //这里一定要 赋初值为0，要不编译错误。。
    Point operator - (const Point &b) const {
        return Point(x-b.x, y-b.y);
    }
    double operator ^ (const Point &b) const {
        return x*b.y-y*b.x;
    }
    double operator *(const Point &b) const {
        return x*b.x + y*b.y;
    }
};

struct Line {
    Point s, e;
    double k;
    Line(){}
    Line(Point ss, Point ee) {
        s = ss; e = ee;
        k = atan2(e.y-s.y, e.x-s.x);
    }
    Point operator &(const Line &b) const {
        Point res = s;
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return res;
    }
};

#define eps EPS
//half plane intersection
int HPIcmp(Line a, Line b) {
    if(fabs(a.k-b.k) > eps) return a.k < b.k;
    return ((a.s-b.s)^(b.e-b.s)) < 0;
}

Line Q[110];
void HPI(Line line[], int n, Point res[], int &resn) {
    int tot = n;
    sort(line, line+n, HPIcmp);
    tot = 1;
    for(int i = 1; i < n; i++)
        if(fabs(line[i].k-line[i-1].k) > eps)
        line[tot++] = line[i];
    int head = 0, tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for(int i = 2; i < tot; i++) {
        if(fabs((Q[tail].e-Q[tail].s)^(Q[tail-1].e-Q[tail-1].s)) < eps ||
           fabs((Q[head].e-Q[head].s)^(Q[head+1].e-Q[head+1].s)) < eps)
            return;
        while(head < tail && (((Q[tail]&Q[tail-1])-line[i].s)^(line[i].e-line[i].s)) > eps)
            tail--;
        while(head < tail && (((Q[head]&Q[head+1])-line[i].s)^(line[i].e-line[i].s)) > eps)
            head++;
        Q[++tail] = line[i];
    }
    while(head < tail && (((Q[tail]&Q[tail-1])-Q[head].s)^(Q[head].e-Q[head].s)) > eps)
        tail--;
    while(head < tail && (((Q[head]&Q[head-1])-Q[tail].s)^(Q[tail].e-Q[tail].e)) > eps)
        head++;
    if(tail <= head+1) return;
    for(int i = head; i < tail; i++)
        res[resn++] = Q[i]&Q[i+1];
    if(head < tail-1)
    res[resn++] = Q[head]&Q[tail];
}

//distance function
double dist(Point a, Point b) {
    return sqrt((a-b)*(a-b));
}

void change(Point a, Point b, Point &c, Point &d, double p) {
    double dx = (a.y - b.y) * p / dist(a, b);
    double dy = (b.x - a.x) * p / dist(a, b);
    c.x = a.x + dx; c.y = a.y + dy;
    d.x = b.x + dx; d.y = b.y + dy;
}

Line lns[110];
Point pts[110];
Point res[110];

ostream &operator << (ostream &os, const Point &p) {
    os << "(" << p.x << "," << p.y << ")";
}

inline bool check(double len, int n) {
    Point s, e;
    for (int i = 0; i < n; ++i) {
        change(pts[i], pts[(i + 1) % n], s, e, len);
        lns[i] = Line(s, e);
        /*if (pts[2].x == 5000)
                cout << "Line: " << lns[i].s << " " << lns[i].e << endl;*/
    }
    //cout << endl;
    int resn;
    HPI(lns, n, res, resn);
    return resn != 0;
}


int main() {

    //time_t start=clock();
    //Rd("3525.in"); //make sure to put it in the correct folder
    int n;
    while (~scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &pts[i].x, &pts[i].y);
        double lo = 0, hi = 100000, mid, ans;
        for (int i = 0; i < 100; i++) {
            mid = (lo + hi) / 2;
            if (check(mid, n)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        ans = lo;
        /*while (hi - lo >= EPS) {
            double mid = (hi + lo)/2;
            if (check(mid, n)) {
                ans = mid;
                lo = mid + EPS;
            } else {
                hi = mid - EPS;
            }
        }*/
        printf("%.6f\n", ans);
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




