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

#define x first
#define y second

long long CCW(pair<int,int> &a, pair<int,int> &b, pair<int,int> &c) {
    return (1LL * (b.x - a.x) * (c.y - a.y)) - (1LL * (b.y - a.y) * (c.x - a.x));
}

int main() {

    //time_t start=clock();
    Rd("166B.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n;
    vector< pair<int, int> > pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    pair<int, int> p;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> p.x >> p.y;
        //checking if the point is outside the half-planes of n-1 and 1-2
        if (CCW(pts[pts.size()-1], pts[0], p) >= 0 || CCW(pts[0], pts[1], p) >= 0) {
            cout << "NO" << endl;
            return 0;
        }
        //goal: lo becomes the point right below
        int lo = 1, hi = n-1, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (CCW(pts[0], pts[mid], p) <= 0) lo = mid;
            else hi = mid;
        }
        //cout << pts[lo] << ' ' << pts[hi] << ' '<< CCW(pts[lo], pts[hi], p) << p << endl;
        if (CCW(pts[lo], pts[hi], p) >= 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




