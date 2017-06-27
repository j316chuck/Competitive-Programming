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
    //sorts from low to high in y;
    bool operator < (const PT &p) const {
        return p.y > y || p.y == y && p.x > x;
    }
};

ostream &operator << (ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << "," << p.idx << ")";
}

// tells if the direction between ab -> bc is straight, turns left (counter clockwise), or turns right (clockwise).
// 1 if left counterclockwise turn, 0 if collinear, -1 if right clockwise turn;
int CCW(PT a, PT b, PT c) {
    double cr = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);;
    if (fabs(cr) < EPS) return 0;
    else if (cr > 0) return 1;
    else return -1;
}

void ConvexHull(vector<PT> &p1, vector<PT> &p2, vector<PT> &ret) {
    ret.clear();
    //p1.erase(unique(p1.begin(), p1.end()), p1.end());
    //p2.erase(unique(p2.begin(), p2.end()), p2.end());
    p1.insert(p1.end(), p2.begin(), p2.end());
    //deb(p1);
    sort(p1.begin(), p1.end());
    vector<PT> up, dn;
    for (auto it = p1.begin(); it != p1.end(); it++) {
        while (up.size() >= 2 && CCW(up[up.size() - 2], up[up.size() - 1], *it) > 0)
            up.pop_back();
        while (dn.size() >= 2 && CCW(dn[dn.size() - 2], dn[dn.size() - 1], *it) < 0)
            dn.pop_back();
        up.push_back(*it);
        dn.push_back(*it);
    }
    ret = dn;
    for (int i = up.size() - 2; i >= 1; i--) {
        ret.push_back(up[i]);
    }
    //deb(ret);
}

int main() {

    //time_t start=clock();
    //Rd("166B.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n;
    vector<PT> pts;
    PT p; p.idx = 1;
    for (int i = 0; i < n; i++) {
        cin >> p.x >> p.y;
        pts.push_back(p);
    }
    cin >> m; p.idx = 0;
    for (int i = 0; i < m; i++) {
        cin >> p[i].x >> p[i].y;
        pts.push_back(p);
    }
    ConvexHull(pts);
    for (int i = 0; i < pts.size(); i++) {
        if (pts[i].idx == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




