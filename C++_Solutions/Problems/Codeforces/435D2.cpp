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

int n, one, c, s0, s1;
string s;

void match() {
    cout << "? " << s << '\n';
    fflush(stdout);
    cin >> c;
    c = n - c;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        s[i] = '1';
    }
    match();
    one = c;
    s[0] = '0';
    match();
    if (c > one) {
        s0 = 1;
    } else {
        s1 = 1;
    }
    s[0] = '1';

    int lo = 0, hi = n;
    while (lo < hi - 1) {
        int mid = (lo + hi) >> 1;
        for (int i = 1; i <= mid; i++) {
            s[i] = '0';
        }
        match();
        if ((one - c) * (s1 ? 1 : -1) == mid) {
            lo = mid;
        } else {
            hi = mid;
        }
        for (int i = 1; i <= mid; i++) {
            s[i] = '1';
        }
    }

    if (s1) {
        s0 = hi + 1;
    } else {
        s1 = hi + 1;
    }
    cout << "! " << s0 << ' ' << s1 << '\n';
    fflush(stdout);
    return 0;
}




