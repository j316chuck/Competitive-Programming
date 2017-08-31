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
#include <cmath>

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
const int maxn = 20;
double x[maxn], y[maxn], a[maxn], dp[1 << maxn];
double l, r; int n;

double calc(double m, int id) {
    double angle = a[id] - atan2((x[id] - m), y[id]);
    //double angle = a[id] + atan((m - x[id]) / y[id]);
    if (2 * angle >= PI) return r;
    return y[id] * tan(angle) + x[id];
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> a[i];
        a[i] *= acos(-1.0) / 180.0;
    }
    dp[0] = l;
    for (int i = 1; i < (1 << n); i++) {
        dp[i] = l;
        for (int j = 0; j < n; j++) if (i & (1 << j)) {
            dp[i] = max(dp[i], calc(dp[i ^ (1 << j)], j));
        }
    }
           //deb_array(dp, n);

    cout << setprecision(8) <<  min(r, dp[(1 << n) - 1]) - l << endl;
    return 0;
}




