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


const int maxn = 20;
string str[maxn];
int graph[maxn][maxn];
int cost[maxn][maxn];
int trans[maxn][maxn];
int dp[1 << maxn];

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int maxv = 0;
            for (int k = 0; k < n; k++) if (str[j][i] == str[k][i]) {
                maxv = max(maxv, graph[k][i]);
                cost[j][i] += graph[k][i];
                trans[j][i] |= (1 << k);
            }
            cost[j][i] -= maxv;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++) {
        int b = 0;
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                b = j;
                break;
            }
        }
        for (int j = 0; j < m; j++) {
            dp[i] = min(dp[i], dp[i & (i ^ trans[b][j])] + cost[b][j]);
            dp[i] = min(dp[i], dp[i & (i ^ (1 << b))] + graph[b][j]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}




