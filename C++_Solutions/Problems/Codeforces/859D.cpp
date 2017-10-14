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

const int maxn = 500;
const double INF = 1e18 + 1;
double p[maxn][maxn], dp[maxn][maxn], prob[maxn][maxn];
int n, m;

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    m = 1 << n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> p[i][j];
            p[i][j] /= 100;
        }
    }
    for(int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            prob[i][j] = 1.0;
        }
    }

    for (int i = 1; i <= n; i++) {
        int k = (1 << i);
        int bonus = k >> 1;
        for (int j = 0; j <= m; j += k) {
            int b = j;
            int e = j + k;
            int m = (b + e) / 2;
            for(int c = j + 1; c <= m; c++) {
                prob[i][c] = 0;
                for (int d = m + 1; d <= e; d++) {
                    prob[i][c] = prob[i][c] + prob[i - 1][c] * prob[i - 1][d] * p[c][d];
                }
            }
            for (int c = m + 1; c <= e; c++) {
                prob[i][c] = 0;
                for (int d = j + 1; d <= m; d++) {
                    prob[i][c] = prob[i][c] + prob[i - 1][c] * prob[i - 1][d] * p[c][d];
                }
            }
            for (int c = m + 1; c <= e; c++) {
                if (prob[i][c] == 0 || (dp[i - 1][c] == 0 && i != 1)) {
                    continue;
                }
                for (int d = j + 1; d <= m; d++) {
                     dp[i][c] = max(dp[i][c], dp[i - 1][c] + dp[i - 1][d] + prob[i][c] * bonus);
                }
            }
            for (int c = j + 1; c <= m; c++) {
                if (prob[i][c] == 0 || (dp[i - 1][c] == 0 && i != 1)) {
                    continue;
                }
                for (int d = m + 1; d <= e; d++) {
                    dp[i][c] = max(dp[i][c], dp[i - 1][c] + dp[i - 1][d] + prob[i][c] * bonus);
                }
            }
        }
    }

    cout << fixed << setprecision(12) << *max_element(dp[n], dp[n] + m + 1) << endl;
    return 0;
}


//bugs to check
//long long vs int
//mod when subtracting s = (((v1 - v2) % mod) + mod) % mod;
//base case missing
//continue/for loop iteration
//sort(1, n + 1) or sort(1, m + 1)
//uninitialized/wrongly initialized variables
//check if your input file "input.in" is right
//check if your expected answer is what you want
//re-read question / extra constraints
//re-check thought process




