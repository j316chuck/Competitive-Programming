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
    bool e;
    int p, s, t;
    bool operator < (const pp &a) const {
        return p < a.p || (p == a.p && e < a.e);
    }
};

const int maxn = 10000;
int n, ans;
vector<pp> x, y;
int level[2 * maxn + 5];

void solve(vector<pp> &x) {
    memset(level, 0, sizeof(level));
    for (int i = 0; i < x.size(); i++) {
        if (!x[i].e) {
            for (int j = x[i].s; j < x[i].t; j++) {
                level[j]++;
                if (level[j] == 1) ans++;
            }
        } else {
            for (int j = x[i].s; j < x[i].t; j++) {
                level[j]--;
                if (level[j] == 0) ans++;
            }
        }
    }
}

int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    x.resize(2 * n); y.resize(2 * n);
    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += maxn, y1 += maxn, x2 += maxn, y2 += maxn;
        x[2 * i] = {false, y1, x1, x2}; x[2 * i + 1] = {true, y2, x1, x2};
        y[2 * i] = {false, x1, y1, y2}; y[2 * i + 1] = {true, x2, y1, y2};
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    solve(x);
    solve(y);
    cout << ans << endl;
    return 0;
}




