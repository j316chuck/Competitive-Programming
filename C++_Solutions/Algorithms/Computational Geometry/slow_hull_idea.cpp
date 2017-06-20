/*
ID: j316chuck
PROG: solves POJ 1696 which is basically slow hull
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
    int idx;
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
    double cr = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (fabs(cr) < EPS) return 0;
    else if (cr > 0) return 1;
    else return -1;
}

bool ThreePointsCollinear(PT a, PT b, PT c) {
    return CCW(a, b, c) == 0;
}


int main() {

    //time_t start=clock();
    //Rd(".in"); //make sure to put it in the correct folder
    int testcases, n, counter;
    vector<PT> pts;
    bool used[100];
    scanf("%d", &testcases);
    for (int tt = 1; tt <= testcases; ++tt) {
        scanf("%d", &n);
        pts.clear();
        pts.resize(n + 1);
        memset(used, false, sizeof(used));
        counter = 1;
        int mindex = -1;

        for (int i = 0; i < n; ++i) {
            scanf("%d %lf %lf", &pts[i].idx, &pts[i].x, &pts[i].y);
            if (mindex == -1 || pts[mindex].y > pts[i].y) {
                mindex = i;
            }
        }
        used[mindex] = true;
        printf("%d ", n);
        printf("%d ", mindex + 1);

        //slow hull idea
        int p = mindex, q;
        do {
            q = -1;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && (q == -1 || CCW(pts[p], pts[i], pts[q]) > 0
                    || (CCW(pts[p], pts[i], pts[q]) == 0 && dist2(pts[q], pts[p]) > dist2(pts[i], pts[p])))) {
                    q = i;
                }
            }
            printf("%d ", q + 1);
            used[q] = true;
            p = q;
            ++counter;
        } while (counter != n);
        printf("\n");
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}





