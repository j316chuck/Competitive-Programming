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

const int maxn = 35e3 + 5;
const int maxk = 55;
int n, k;
int dp[maxn][maxk], a[maxn], last[maxn];
map<int, int> mp;

struct RMQ {
    int seg[4 *maxn], lazy[4 * maxn];
    void build(int k, int x, int st, int en) {
        if (st == en) {
            seg[x] = dp[st][k];
            lazy[x] = 0;
            return;
        }
        int mid = (st + en) >> 1;
        build(k, 2 * x, st, mid);
        build(k, 2 * x + 1, mid + 1, en);
        lazy[x] = 0;
        seg[x] = max(seg[2 * x], seg[2 * x + 1]);
    }
    void push(int x, int st, int en) {
        if (lazy[x]) {
            seg[x] += lazy[x];
            if (st != en) {
                lazy[2 * x] += lazy[x];
                lazy[2 * x + 1] += lazy[x];
            }
            lazy[x] = 0;
        }
    }
    void update(int x, int st, int en, int l, int r, int val) {
        push(x, st, en);
        if (l > r) return;
        if (r < st || en < l) {
            return;
        }
        if (l <= st && en <= r) {
            lazy[x] += val;
            push(x, st, en);
            return;
        }
        int mid = (st + en) >> 1;
        update(2 * x, st, mid, l, r, val);
        update(2 * x + 1, mid + 1 , en, l, r, val);
        seg[x] = max(seg[2 * x], seg[2 * x + 1]);
    }
    int query(int x, int st, int en, int l, int r) {
        push(x, st, en);
        if (l > r) return 0;
        if (r < st || en < l) {
            return 0;
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
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        last[i] = mp[a[i]];
        mp[a[i]] = i;
        dp[i][1] = mp.size();
    }
    for (int j = 2; j <= k; j++) {
        rmq.build(j - 1, 1, 0, n - 1);
        for (int i = 0; i < n; i++) {
            rmq.update(1, 0, n - 1, last[i], i - 1, 1);
            dp[i][j] = max(rmq.query(1, 0, n - 1, 0, i - 1), dp[i][j - 1]);
        }
    }
    cout << dp[n - 1][k] << endl;
    return 0;
}




