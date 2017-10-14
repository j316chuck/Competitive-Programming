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

const long long INF = 4e18 + 10;
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

const int maxn = 1e5 + 5;
long long a[maxn];
int n;
multiset<long long> s1, s2;
long long ans = -INF, p, q, r;

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> p >> q >> r;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s2.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        s1.insert(a[i]);
        long long sum = q * a[i];
        if (p < 0) {
            sum += p * (*s1.begin());
        } else {
            sum += p * (*prev(s1.end()));
        }
        if (r < 0) {
            sum += r * (*s2.begin());
        } else {
            sum += r * (*prev(s2.end()));
        }
        ans = max(ans, sum);
        s2.erase(a[i]);
    }
    cout << ans << endl;
    return 0;
}





