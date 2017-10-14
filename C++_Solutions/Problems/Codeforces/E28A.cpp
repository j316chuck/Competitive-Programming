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


int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> v(n), one(n, 0), zero(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    one[0] = v[0] == 1 ? 1 : 0;
    zero.back() = v.back() == 0 ? 1 : 0;
    for (int i = 1; i < n; i++) {
        one[i] = one[i - 1] + (v[i] == 1 ? 1 : 0);
    }
    for (int i = n - 2; i >= 0; i--) {
        zero[i] = zero[i + 1] + (v[i] == 0 ? 1 : 0);
    }
    //deb(zero); deb(one);
    int ans = INF, c;
    for (int i = 0; i < n; i++) {
        c = zero[i] + one[i]; c--;
        ans = min(ans, c);
    }
    ans = n - ans;
    cout << ans << endl;
    return 0;
}




