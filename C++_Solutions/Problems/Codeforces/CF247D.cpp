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


const int maxn = 65;
long long comb[maxn][maxn];

void precalc() {
    comb[0][0] = 1;
    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) comb[i][j] = 1;
            else comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
}

int bcount(long long m) {
    int ret = 0;
    for (long long i = m; i > 0; i &= (i - 1)) {
        ret++;
    }
    return ret;
}

long long solve(long long m, int k) {
    long long ans = 0;
    for (int i = maxn - 2; i >= 0 && k >= 0; i--) {
        if ((m >> i) & 1) {
            ans += comb[i][k--];
        }
    }
    ans += (__builtin_popcountll(m) == k);
    return ans;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    precalc();
    long long m, k;
    cin >> m >> k;
    long long lo = 0, hi = 1e18 + 1;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) >> 1;
        if (solve (2 * mid, k) - solve(mid, k) < m) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << hi << endl;
    return 0;
}



