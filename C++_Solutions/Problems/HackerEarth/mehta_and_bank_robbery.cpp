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

const int maxn = 2e3 + 10;
const long long primes[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
long long dp[maxn][maxn][2];
int n, w;

struct pp {
    long long profit; int weight;
    bool operator < (const pp &a) const {
        return profit < a.profit;
    }
} arr[maxn];

int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].profit >> arr[i].weight;
    }
    sort(arr + 1, arr + n + 1);
    //base case
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            dp[i][j][0] = dp[i - 1][j][0];
            if (j >= arr[i].weight) {
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - arr[i].weight][0] + arr[i].profit);
            }
        }
    }
    for (int prime = 1; prime <= 10; prime++) {
        int p = prime % 2;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                dp[i][j][p] = max(dp[i - 1][j][p], max(dp[i][j - 1][p], dp[i][j][p ^ 1]));
                if (j >= arr[i].weight) {
                    dp[i][j][p] = max(dp[i][j][p], max(dp[i - 1][j - arr[i].weight][p] + arr[i].profit, dp[i - 1][j - arr[i].weight][p ^ 1] + arr[i].profit * primes[prime]));
                }
            }
        }
    }
    cout << dp[n][w][0] << endl;
    return 0;
}




