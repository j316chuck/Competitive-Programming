/*
ID: j316chuck
PROG: 417B
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = pow(10, -5);
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

int dp[110][2];
int l[110];
int r[110];
int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    Rd("417B.in");
    int n, m;
    cin >> n >> m;
    for (int i = n; i >= 1; i--) {
        string s;
        cin>> s;
        l[i] = s.find('1');  // -1 if not found;
        r[i] = s.rfind('1'); // -1 if not found;
        if (l[i] == -1) l[i] = m + 1, r[i] = 0;
        //cout << l[i] << ' ' << r[i] << endl;
    }
    //reverse(l + 1, l + n + 1);
    //reverse(r + 1, r + n + 1);
    for (int i = n; i >= 0; i--) {
        if (r[i] == -1) n--;
        else break;
    }
    dp[1][1] = INF;
    for (int i = 1; i < n; i++) {
        dp[i+1][0] = min(dp[i][0] + 2 * r[i] + 1, dp[i][1] + m + 2);
        dp[i+1][1] = min(dp[i][1] + 2 * (m + 1 - l[i]) + 1, dp[i][0] + m + 2);
        //cout << dp[i+1][0] << ' ' << dp[i+1][1] << endl;
    }

    dp[n][0] = min(dp[n][0] + r[n], dp[n][1] + m + 1 - l[n]);
    cout << dp[n][0]  << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




