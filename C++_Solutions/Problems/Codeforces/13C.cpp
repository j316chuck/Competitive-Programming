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

const int maxn = 5e3 + 5;
long long dp1[maxn], dp2[maxn];

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        a[i] = v[i];
    }
    sort(a.begin(), a.end());
    memset(dp2, 0x7f, sizeof(dp2));

    dp1[0] = abs(a[0] - v[0]);
    for (int i = 1; i < n; i++) {
        dp1[i] = dp1[i - 1] + abs(a[0] - v[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                dp2[j] = min(dp1[j], 1LL * abs(a[i] - v[0]));
            } else {
                dp2[j] = min(dp2[j - 1] + abs(a[i] - v[j]), dp1[j]);
            }
        }
        memcpy(dp1, dp2, sizeof(dp2));
        //memcpy(dp[(i % 2)], dp[(i + 1) % 2], sizeof(dp[(i + 1) % 2]));
    }
    cout << dp1[n - 1] << endl;
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




