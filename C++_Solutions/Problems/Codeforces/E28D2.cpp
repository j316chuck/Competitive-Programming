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

const int INF = 1e9 + 5;
const int maxn = 505;
int n, m, k, q;
int ans[maxn][maxn];
int d[maxn][maxn];

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k >> q;
    for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++) ans[i][j] = INF;
    for (int i = 1; i <= q; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        ans[x][y] = w;
    }

    for (int i = 1; i <= n; i++) {
        deque< pair<int, int> > q;
        for (int j = 1; j <= m; j++) {
            while (!q.empty() && q.front().first < ans[i][j]) {
                q.pop_front();
            }
            q.push_front({ans[i][j], j});
            if (j >= k) {
                while (!q.empty() && q.back().second + k <= j) {
                    q.pop_back();
                }
                d[i][j] = q.back().first;
            }
        }
    }

    for (int j = k; j <= m; j++) {
        deque< pair<int, int> > q;
        for (int i = 1; i <= n; i++) {
            while (!q.empty() && q.front().first < d[i][j]) {
                q.pop_front();
            }
            q.push_front({d[i][j], i});
            if (i >= k) {
                while (!q.empty() && q.back().second + k <= i) {
                    q.pop_back();
                }
                ans[i][j] = q.back().first;
            }
        }
    }

    int ret = INF;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            ret = min(ret, ans[i][j]);
        }
    }
    if (ret == INF) cout << -1 << endl;
    else cout << ret << endl;
    return 0;
}




