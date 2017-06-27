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

const int INF = 0x3f3f3f3f;
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

int moves[30][2000]; //char, moves;

int main() {

    //time_t start=clock();
    Rd("418C.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    vector<int> v(n + 1, 0);
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        v[i] = c - 'a';
    }
    int dp[n+1][n+1]; //moves position
    for (int ch = 0; ch < 26; ch++) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = 0;

        dp[0][0] = moves[ch][0] = ch == v[0];
        for (int i = 1; i < n; i++) { //0 moves;
            if (v[i] == ch) {dp[0][i] = dp[0][i-1] + 1;}
            else dp[0][i] = 0;
            moves[ch][0] = max(dp[0][i], moves[ch][0]);
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = moves[ch][i] = 1;
            for (int j = 1; j < n; j++) {
                if (v[j] == ch) dp[i][j] = dp[i][j-1] + 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
                moves[ch][i] = max(moves[ch][i], dp[i][j]);
            }
        }
    }
    int q, k;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> k >> c;
        cout << moves[c - 'a'][k] << endl;
    }
    cout << 289.02652413/3.1415926 << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



