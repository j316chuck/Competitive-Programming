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


string s;
int ans = 6;
bool valid(int n) {
    int s1 = 0, s2 = 0;
    for (int i = 0; i < 3; i++) {
        s1 += n % 10;
        n /= 10;
    }
    for (int i = 0; i < 3; i++) {
        s2 += n % 10;
        n /= 10;
    }
    return s1 == s2;
}

void dfs(int n, int stp, int diff) {
    if (stp == 6) {
        if (valid(n)) {
            //cout << n << endl;
            ans = min(ans, diff);
        }
        return;
    }
    n *= 10;
    for (int i = 0; i < 10; i++) {
        if (s[stp] - '0' == i) {
            dfs(n + i, stp + 1, diff);
        } else {
            dfs(n + i, stp + 1, diff + 1);
        }
    }
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> s;
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}



