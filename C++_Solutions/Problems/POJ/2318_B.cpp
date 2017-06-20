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

double dot(PT p, PT q)     { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q)   { return dot(p - q, p - q); }
double dist(PT p, PT q)    { return sqrt(dist2(p, q)); }
double cross(PT p, PT q)   { return p.x * q.y - p.y * q.x; }

// tells if the direction between ab -> bc is straight, turns left (counter clockwise), or turns right (clockwise).
// 1 if left counterclockwise turn, 0 if collinear, -1 if right clockwise turn;
int CCW(PT a, PT b, PT c) {
    double cr = cross(b - a, c - a);
    if (fabs(cr) < EPS) return 0;
    else if (cr > 0) return 1;
    else return -1;
}

// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
    return a + (b-a) * dot(c-a, b-a) / dot(b-a, b-a);
}

int BinarySearch(vector< pair<PT, PT> > &segs, PT p, int n) {
    int lo = 0, hi = n + 1, mid;
    //PT newp;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (CCW(segs[mid].second, segs[mid].first, p) >= 0) {
            hi = mid;
        } else {
            lo = mid;
        }
        //cout << mid << ' ' << lo << ' ' << hi << endl;
        /*newp = ProjectPointLine(segs[mid].first, segs[mid].second, p);
        if (newp.x < p.x) {
            lo = mid;
        } else if (newp.x > p.x) {
            hi = mid;
        }*/
        //cout << segs[mid].second << ' ' << segs[mid].first << endl;
    }
    return lo;
}


int main() {

    //time_t start=clock();
    Rd("2318.in"); //make sure to put it in the correct folder
    int n, m, x1, y1, x2, y2, Ui, Li;
    PT p;
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
            scanf("%lf %lf", &p.x, &p.y);
            int x = BinarySearch(segs, p, n);
            mp[x]++;
        }

        for (int i = 0; i < mp.size(); ++i) {
            printf("%d: %d\n", i, mp[i]);
        }
        printf("\n");
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}





