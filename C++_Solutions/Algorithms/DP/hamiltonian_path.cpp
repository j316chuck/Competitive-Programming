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


int graph[20][20];
int dp[1 << 20][20];

int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        graph[x][y] = graph[y][x] = w;
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 0;
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!((1 << j) & i)) continue;
            for (int k = 0; k < n; k++) {
                if (((1 << k) & i) && graph[j][k]) {
                    dp[i][k] = min(dp[i][k], dp[i ^ (1 << k)][j] + graph[j][k]);
                }
            }
        }
    }
    int ret = INF;
    for (int i = 0; i < n; i++) {
        ret = min(ret, dp[(1 << n) - 1][i]);
    }
    cout << ret << endl;
    return 0;
}



