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

int n, k;
int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    vector<int> v(n), psum(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (v[0] == 0) psum[0] = 1;
    else psum[0] = 0;
    for (int i = 1; i < n; i++) {
        psum[i] = psum[i - 1] + (v[i] == 0);
    }
    int ans = 0, query, pos, st = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) query = psum[i] + k;
        else query = psum[i] + k + 1;
        pos = lower_bound(psum.begin(), psum.end(), query) - psum.begin();
        if (ans < pos - i) {
            ans = pos - i;
            st = i;
        }
    }
    if (st == -1) {
        cout << 0 << endl;
        for (int i = 0; i < n; i++) cout << v[i] << ' ';
        return 0;
    }
    int counter = 0;
    for (int i = st; i < n && counter < k; i++) {
        if (v[i] == 0) {
            v[i] = 1;
            counter++;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << endl;
    //deb(psum);
    return 0;
}




