/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const double Pi= acos(-1.0);
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

//may overflow if mod p > long long maxvalue  / 2 = around 10^18
long long mod_mult(long long x, long long y, long long p) {
    if (x == 0 || y == 0) return 0;
    long long a = x, b = y, c = 0;
    while (a > 0) {
        if (a & 1) {
            c = (c + b) % p;
        }
        a >>= 1;
        b = (b * 2) % p;
    }
    return c;
}

long long mod_exp(long long b, long long e, long long mod) {
    if (b == 0 || b == 1) return b;
    long long res = 1;
    while (e > 0) {
        if (e & 1) {
            res = mod_mult(res, b, mod);
        }
        e >>= 1;
        b = mod_mult(b, b, mod);
    }
    return res;
}

int main() {
    cout << mod_mult(11, 7, 1000000) << endl;
    cout << mod_exp(8, 3, 100) << endl;
}
