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

const int maxn = 105;
const int maxm = 2e3 + 5;
struct pp {
    int t, d, p;
} a[maxn];
int n;
int par[maxn][maxm];
int dp[maxn][maxm];

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].d >> a[i].p;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < maxm; j++) {
            if (j < a[i].t) {
                par[i][j] = par[i - 1][j];
                dp[i][j] = dp[i - 1][j];
            } else if (j >= a[i].d) {
                par[i][j] = par[i - 1][j];
                dp[i][j] = dp[i - 1][j];
            } else {
                if (dp[i - 1][j - a[i].t] + a[i].p > dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j - a[i].t] + a[i].p;
                    par[i][j] = i;
                } else {
                    par[i][j] = par[i - 1][j];
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    int ans = 0, index;
    for (int i = 0; i < maxm; i++) {
        if (ans < dp[n][i]) {
            ans = dp[n][i];
            index = i;
        }
    }
    cout << ans << endl;
    int t = index;
    index = n;
    vector<int> res;
    while (true) {
        index = par[index][t];
        if (index == 0) break;
        res.push_back(index);
        t -= a[index].t;
    }
    reverse(res.begin(), res.end());
    cout << (int) res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    } cout << endl;
    return 0;
}




