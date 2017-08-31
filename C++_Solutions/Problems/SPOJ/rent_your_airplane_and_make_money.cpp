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

struct pp {
    int s, len, p;
    bool operator < (const pp &a) const {
        return s < a.s;
    }
};

const int maxn = 1e5 + 5;
int n;
int dp[maxn], sorted[maxn];
vector<pp> v;

void solve() {
    memset(dp, 0, sizeof(dp));
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &v[i].s, &v[i].len, &v[i].p);
        sorted[i] = v[i].s;
    }
    sort(sorted, sorted + n);
    sort(v.begin(), v.end());
    dp[n] = 0; int x;
    for (int i = n - 1; i >= 0; i--) {
        x = lower_bound(sorted, sorted + n, v[i].s + v[i].len) - sorted;
        dp[i] = max(v[i].p + dp[x], dp[i + 1]);
    }
    cout << dp[0] << endl;
}
int main() {
    //Rd("input.in");
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}




