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

const int maxn = 2e3 + 5;
int n, k;
int a[maxn], dp[maxn];

int abs(int x) {
    return x < 0 ? -x : x;
}

bool ok(long long x) {
    for (int i = 1; i <= n; i++) {
        dp[i] = i - 1;
        for (int j = 1; j < i; j++) {
            if (1LL * abs(a[i] - a[j]) <= x * (i - j)) {
                dp[i] = min(dp[i], dp[j] + i - j - 1);
            }
        }
        if (dp[i] + n - i <= k) return true;
    }
    return false;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long l = 0, r = 2e9 + 5, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}




