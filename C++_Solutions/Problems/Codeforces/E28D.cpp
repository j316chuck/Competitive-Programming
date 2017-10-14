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

const int maxn = 505;

struct pp {
    int x, y, t;
    bool operator < (const pp &a) const {
        return t < a.t;
    }
} qq[maxn * maxn];
int n, m, k, q;
int psum[maxn][maxn];

bool check(int c) {
    memset(psum, 0, sizeof(psum));
    int chk = qq[c].t;
    for (int i = 1; i <= q; i++) {
        if (qq[i].t <= chk) {
            psum[qq[i].x][qq[i].y] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            int sum = psum[i][j] - psum[i - k][j] - psum[i][j - k] + psum[i - k][j - k];
            if (sum == k * k) {
                return true;
            }
        }
    }
    return false;
}

int main() {
   // Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= q; i++) {
        cin >> qq[i].x >> qq[i].y >> qq[i].t;
    }
    sort(qq + 1, qq + 1 + q);
    int l = 0, r = q + 1;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == q + 1) {
        cout << -1 << endl;
    } else {
        cout << qq[r].t << endl;
    }
    return 0;
}




