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

const long long INF = 1e18 + 1;
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

const int maxn = 5e3 + 5;
int a[maxn];
int x1, x2, x3, n;
long long psum[maxn], mx;

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    for (int i = 0; i <= n; i++) {
        int t1, t2 = i, t3;
        long long ans1 = -INF, ans2 = -INF;
        for (int j = 0; j <= i; j++) {
            long long x = psum[j] - (psum[i] - psum[j]);
            if (x > ans1) {
                ans1 = x;
                t1 = j;
            }
        }
        for (int j = i; j <= n; j++) {
            long long x = psum[j] - psum[i] - (psum[n] - psum[j]);
            if (x > ans2) {
                ans2 = x;
                t3 = j;
            }
        }
        if (ans1 + ans2 > mx) {
            mx = ans1 + ans2;
            x1 = t1, x2 = t2, x3 = t3;
        }
    }
    cout << x1 << ' ' << x2 << ' ' << x3 << endl;
    return 0;
}




