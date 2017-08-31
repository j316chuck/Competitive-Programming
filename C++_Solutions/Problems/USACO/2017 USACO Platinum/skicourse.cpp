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


struct pp {
    int r, s;
    pp(int r, int s) : r(r), s(s) {};
    pp() : r(0), s(0) {};
};

bool r[105][105], s[105][105];
int main() {
    //Rd("input.in");
    Rd("skicourse.in");
    Wt("skicourse.out");
    memset(r, false, sizeof(r));
    memset(s, false, sizeof(s));
    int m, n; char c;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            (c == 'R') ? r[i + 1][j + 1] = true : s[i + 1][j + 1] = true;
        }
    }
    pp mem = {0, 0};
    int ans = 1e9 + 1;
    while (true) {
        int best = -1, bestr, bestc;
        vector<pp> dp, next;
        dp.resize(n + 1); next.resize(n + 1);
        fill(dp.begin(), dp.end(), mem);
        next[0] = {0, 0};
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pp cur;
                if (r[i][j]) {
                    cur.r = min(next[j - 1].r, min(dp[j - 1].r, dp[j].r)) + 1;
                } else {
                    cur.r = 0;
                }
                if (s[i][j]) {
                    cur.s = min(next[j - 1].s, min(dp[j - 1].s, dp[j].s)) + 1;
                } else {
                    cur.s = 0;
                }
                if (cur.s != cur.r) {
                    int tmp = max(cur.r, cur.s);
                    if (tmp > best) {
                        best = tmp;
                        bestr = i;
                        bestc = j;
                    }
                }
                next[j] = {cur.r, cur.s};
            }
            next.swap(dp);
        }
        if (best == -1) {
            break;
        }
        ans = min(ans, best);
        for (int i = bestr; i > bestr - best; i--) {
            for (int j = bestc; j > bestc - best; j--) {
                r[i][j] = s[i][j] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}




