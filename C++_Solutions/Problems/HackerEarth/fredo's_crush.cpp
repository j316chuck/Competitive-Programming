/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#include <cstdio>
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


const int maxn = 16;
const int maxm = 1 << 16;
int dp[maxm][maxn];
int graph[maxn][maxn];
int ret[maxn];
int n, m, t;

void solve() {
    memset(graph, 0, sizeof(graph));
    memset(dp, 0, sizeof(dp));
    scanf("%d %d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u][v] = graph[v][u] = 1;
    }
    for (int i = 0; i < n; i++) {
        ret[i] = (i + 1);
        dp[1 << i][i] = (i + 1);
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!dp[i][j]) continue;
            for (int k = 0; k < n; k++) {
                if ((i & (1 << k)) || !graph[j][k]) {
                    continue;
                }
                dp[i | (1 << k)][k] = dp[i][j] + (k + 1);
                ret[k] = max(ret[k], dp[i | (1 << k)][k]);
            }
        }
    }
    int a = INF, b = 0;
    for (int i = 0; i < n; i++) {
        a = min(ret[i], a);
        b = max(ret[i], b);
    }
    //cout << a << ' ' << b << endl;
    int gcd = __gcd(a, b);
    a /= gcd; b /= gcd;
    printf("%d %d\n", b, a);
}

int main() {
    Rd("input.in");
    //ios_base::sync_with_stdio(0);
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}




