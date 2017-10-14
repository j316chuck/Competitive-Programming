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

int pw = (1 << 18);

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n >> x;
    if (n == 1) {
        cout << "YES\n" << x << endl;
    } else if (n == 2 && x == 0) {
        cout << "NO\n" << endl;
    } else if (n == 2) {
        cout << "YES\n" << x << ' ' << 0 << endl;
    } else {
        cout << "YES" << endl;
        int xo = 0;
        for (int i = 0; i < n - 3; i++) {
            xo ^= i;
            cout << i << ' ';
        }
        if (xo == x) {
            cout << pw << ' ' << 2 * pw << ' ' << 2 * pw + pw << endl;
        } else {
            cout << (pw ^ xo) << ' ' << 2 * pw << ' ' << ((2 * pw + pw) ^ x) << endl;
        }
    }
    return 0;
}





