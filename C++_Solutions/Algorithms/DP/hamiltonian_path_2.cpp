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
const int maxm = 1 << 20;
const int INF = 1e9 + 1;
int dp[maxm][maxn];
int graph[maxn][maxn];

int main()
{
    //freopen("input.in", "r", stdin);
    memset(dp, 0x3f, sizeof(dp));
    memset(graph, -1, sizeof(graph));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; v--, u--;
        graph[u][v] = w;
    }
    /*for (int i = 0; i < n; i++) {
        deb_array(graph[i], n);
    }*/
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] > INF) continue;
            for (int k = 0; k < n; k++) {
                if (graph[j][k] == -1 || (1 << k) & i) continue;
                dp[(1 << k) | i][k] = min(dp[(1 << k) | i][k], graph[j][k] + dp[i][j]);
            }
        }
    }

    int ret = INF;
    for (int i = 0; i < n; i++) {
        ret = min(ret, dp[(1 << n) - 1][i]);
    }
    cout << (ret != INF ? "YES" : "NO" )<< endl;
}

