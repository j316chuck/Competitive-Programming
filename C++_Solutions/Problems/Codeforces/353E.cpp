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

const int maxn = 1e5 + 5;
int a[maxn]; long long dp[maxn];

struct SegmentTree {
    pair<int, int> seg[4 * maxn];
    void init(){
        fill(seg, seg + 4 * maxn, make_pair(0, -1));
    }
    void build(int x, int st, int en) {
        if (st == en) {
            seg[x] = make_pair(a[st], st);
            return;
        }
        int mid = (st + en) >> 1;
        build(2 * x, st, mid);
        build(2 * x + 1, mid + 1, en);
        seg[x] = max(seg[2 * x], seg[2 * x + 1]);
    }
    pair<int, int> query(int x, int st, int en, int l, int r) {
        if (r < st || en < l) {
            return make_pair(0, -1);
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return max(query(2 * x, st, mid, l, r), query(2 * x + 1, mid + 1, en, l, r));
    }
} rmq;

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
        a[i]--;
    }
    a[n - 1] = n - 1;
    rmq.init();
    rmq.build(1, 0, n - 1);
    dp[n - 1] = 0;
    long long ans = 0; int m;
    for (int i = n - 2; i >= 0; i--) {
        m = rmq.query(1, 0, n - 1, i + 1, a[i]).second;
        dp[i] = n - 1 - i + dp[m] - (a[i] - m);
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}



