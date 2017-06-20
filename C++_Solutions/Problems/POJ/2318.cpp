/*
ID: j316chuck
PROG: 2318
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

// determine if point is in a possibly non-convex polygon (by William
// Randolph Franklin); returns 1 for strictly interior points, 0 for
// strictly exterior points, and 0 or 1 for the remaining points.
// Note that it is possible to convert this into an *exact* test using
// integer arithmetic by taking care of the division appropriately
// (making sure to deal with signs properly) and then by writing exact
// tests for checking point on polygon boundary
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

/*bool inBox(point t,SEG ls,SEG rs)
{
    point a,b,c,d;
    a.x = ls.x1; a.y = ls.y1;
    b.x = ls.x2; b.y = ls.y2;
    c.x = rs.x2; c.y = rs.y2;
    d.x = rs.x1; d.y = rs.y1;
    if( crossProduct(b,t,c) >= 0 && crossProduct(c,t,d) >= 0
        && crossProduct(d,t,a) >= 0 && crossProduct(a,t,b) >= 0 )
            return true;
    return false;
} */

int main() {

    //time_t start=clock();
    Rd("2318.in"); //make sure to put it in the correct folder
    int n, m, x1, y1, x2, y2, Ui, Li;
    PT p;
    vector<PT> pts(4);
    vector< pair<PT, PT> > segs;
    while (scanf("%d", &n) != EOF && n != 0) {
        scanf("%d", &m);
        segs.clear();
        segs.resize(n + 2);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        vector<int> mp (n + 1, 0);
        segs[0] = make_pair(PT(x1, y1), PT(x1, y2));
        segs[n + 1] = make_pair(PT(x2, y1), PT(x2, y2));
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", &Ui, &Li);
            segs[i] = make_pair(PT(Ui, y1), PT(Li, y2));
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &p.x, &p.y);
            pts[0] = segs[0].first;
            pts[1] = segs[0].second;
            pts[2] = segs[1].first;
            pts[3] = segs[1].second;
            if (PointInPolygon(pts, p)) {
                mp[0]++;
                break;
            }
            for (int i = 2; i <= n + 1; ++i) {
                pts[0] = pts[2];
                pts[1] = pts[3];
                pts[2] = segs[i].first;
                pts[3] = segs[i].second;
                if (PointInPolygon(pts, p)) {
                    mp[i - 1]++;
                    break;
                }
            }
        }

        for (int i = 0; i < mp.size(); ++i) {
            printf("%d: %d\n", i, mp[i]);
        }
        printf("\n");
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




