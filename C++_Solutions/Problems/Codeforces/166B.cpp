/*
ID: j316chuck
PROG: 166B
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
    os << "(" << p.x << "," << p.y << "," << p.idx << ")";
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

void ConvexHull(vector<PT> &p1, vector<PT> &p2, vector<PT> &ret) {
    ret.clear();
    p1.erase(unique(p1.begin(), p1.end()), p1.end());
    p2.erase(unique(p1.begin(), p1.end()), p1.end());
    set<PT> s1(p1.begin(), p1.end());
    set<PT> s2(p2.begin(), p2.end());
    s1.insert(s2.begin(), s2.end());
    if (s1.size() != p1.size() + p2.size()) {
        PT p; p.x = -1; p.y = -1; p.idx = 0;
        ret.push_back(p);
        return;
    }
    vector<PT> up, dn;
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        while (up.size() >= 2 && CCW(up[up.size() - 2], up[up.size() - 1], *it) >= 0)
            up.pop_back();
        while (dn.size() >= 2 && CCW(dn[dn.size() - 2], dn[dn.size() - 1], *it) <= 0)
            dn.pop_back();
        up.push_back(*it);
        dn.push_back(*it);
    }
    ret = dn;
    for (int i = up.size() - 2; i >= 1; i--) {
        ret.push_back(up[i]);
    }
    deb(ret);
}

int main() {

    //time_t start=clock();
    Rd("166B.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n;
    vector<PT> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
        pts[i].idx = 1;
    }
    cin >> m;
    vector<PT> pts2(m);
    for (int i = 0; i < m; i++) {
        cin >> pts2[i].x >> pts2[i].y;
        pts2[i].idx = 0;
    }
    vector<PT> ret;
    ConvexHull(pts, pts2, ret);
    for (int i = 0; i < ret.size(); i++) {
        if (ret[i].idx == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



