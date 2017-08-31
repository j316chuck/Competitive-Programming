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

int n;
int a[20][2];
int dp[1 << 18][18];

int dist(int u, int v) {
    return fabs(a[u][0] - a[v][0]) + fabs(a[u][1] - a[v][1]);
}

bool valid (int n) {
    int c = 0;
    for (int i = 0; i < n; i += 2) {
        if ((n & (1 << i)) && !(n & (1 << (i + 1)))) {
            c++;
        } if (!(n & (1 << i)) && (n & (1 << (i + 1)))) {
            c = 3; break;
        }
    }
    return c < 3;
}

void solve() {
    cin >> n;
    n *= 2;
    for (int i = 0; i < n; i += 2) {
        cin >> a[i][0] >> a[i][1] >> a[i + 1][0] >> a[i + 1][1];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        if (!valid(i)) continue;
        //cout << i << endl;
        for (int j = 0; j < n; j++) {
            if (__builtin_popcount(i) == 1 && ((1 << j) & i)) {
                dp[i][j] = abs(a[j][0]) + abs(a[j][1]);
                break;
            }
            if (!(i & (1 << j))) continue;
            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) && j != k) {
                    dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] +  abs(a[j][0] - a[k][0]) + abs(a[j][1] - a[k][1]));
                    if (dp[i][j] < INF) {
                        cout << dp[i][j] << endl;
                    }
                }
            }
        }
    }
    int ret = INF;
    for (int i = 1; i < n; i += 2) {
        ret = min(dp[(1 << n) - 1][i] + abs(a[i][0]) + abs(a[i][1]), ret);
    }
    cout << ret << endl;
}

int main() {
    Rd("input.in");
    Wt("output.out");
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}




