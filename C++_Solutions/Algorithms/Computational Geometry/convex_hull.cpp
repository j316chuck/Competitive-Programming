/*
ID: j316chuck
PROG: convex_hull
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
        return make_pair(y, x) < make_pair(p.y, p.x);
    }
    bool operator == (const PT &p) const {
        return make_pair(p.x, p.y) == make_pair(x, y);
    }
};

inline bool LowXSort(const PT &p1, const PT &p2) {
    if (p2.x > p1.x) return true;
    else if (p2.x < p1.x) return false;
    return p2.y > p1.y;
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

bool ThreePointsCollinear(PT a, PT b, PT c) {
    return CCW(a, b, c) == 0;
}

//returns the convex hull of the points in the vector points;
//points starts from the lowest point to the most left and circles in a counterclockwise order (lower + upper)
//if remove_redundant is defined the points that are collinear are removed
#define REMOVE_REDUNDANT

void ConvexHull(vector<PT> &pts) {

    sort(pts.begin(), pts.end());
    //remove repeated points
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<PT> dn, up;
    for (int i = 0; i < pts.size(); ++i) {
        while (dn.size() >= 2 && CCW(dn[dn.size() - 2], dn[dn.size() - 1], pts[i]) <= 0) {
            dn.pop_back();
        }
        while (up.size() >= 2 && CCW(up[up.size() - 2], up[up.size() - 1], pts[i]) >= 0) {
            up.pop_back();
        }
        dn.push_back(pts[i]);
        up.push_back(pts[i]);
    }
    pts = dn;
    for (int i = up.size() - 2; i >= 1; --i) {
        pts.push_back(up[i]);
    }
    #ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;

    for (int i = 0; i < pts.size(); ++i) {
        if (dn.size() >= 2 && ThreePointsCollinear(dn[dn.size() - 2], dn[dn.size() - 1], pts[i])) {
            dn.pop_back();
        }
        dn.push_back(pts[i]);
    }
    while (dn.size() >= 3 && ThreePointsCollinear(dn.back(), dn[0], dn[1])) {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
    #endif // REMOVE_REDUNDANT
}

int main() {

    //time_t start=clock();
    //Rd("convex_hull.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int testcases, n;
    map<PT, int> mp;
    vector<PT> hull;
    scanf("%d", &testcases);
    for (int t = 0; t < testcases; ++t) {
        mp.clear();
        scanf("%d", &n);
        hull.clear();
        hull.resize(n);
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf", &hull[i].x, &hull[i].y);
        }
        //vector<PT> h(hull);
        for (int i = n - 1; i >= 0; --i) {
            mp[hull[i]] = i + 1;
        }
        ConvexHull(hull);
        double len = 0;
        for (int i = 0; i < hull.size(); ++i) {
            len += dist(hull[i], hull[(i + 1) % hull.size()]);
        }

        if (t > 0) printf("\n");
        printf("%.2f\n", len);
        for (int i = 0; i < hull.size(); ++i) {
            printf("%d ", mp[hull[i]]);
        }
        printf("\n");
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



