/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
#define endl '\n'

const int INF = 1e9+1;
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

const int maxn = 2e5 + 5;
struct pp {
    int t, l, r;
} qq[maxn];

int n, q, m, b;
int a[maxn];

int one(int c, int l, int r) {
    if (c < l || c > r) return c;
    else if (c == l) return r;
    else return c - 1;
}

int two(int c, int l, int r) {
    if (c < l || c > r) return c;
    else if ((c - l) > (r - c)) return r - (c - l);
    else return l + (r - c);
}

int solve(int c) {
    for (int i = q; i >= 1; i--) {
        if (qq[i].t == 1) {
            c = one(c, qq[i].l, qq[i].r);
        } else {
            c = two(c, qq[i].l, qq[i].r);
        }
    }
    return a[c];
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> qq[i].t >> qq[i].l >> qq[i].r;
    }
    for (int i = 0; i < m; i++) {
        cin >> b;
        cout << solve(b) << ' ';
    } cout << endl;
    return 0;
}




