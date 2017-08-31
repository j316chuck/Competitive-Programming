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

const int maxn = 1e5 + 25;
int a[maxn];

struct SegmentTree {
    long long seg[4 * maxn];
    void init() {
        memset(seg, 0, sizeof(seg));
    }
    long long query(int node, int st, int en, int l, int r) {
        if (r < st || en < l) {
            return 0;
        }
        if (l <= st && en <= r) {
            return seg[node];
        }
        int mid = (st + en) >> 1;
        return query(2*node, st, mid, l, r) + query(2*node+1, mid+1, en, l, r);
    }
    void update(int node, int st, int en, int id, long long val) {
        if (st == en) {
            seg[node] += val;
            return;
        }
        int mid = (st + en) >> 1;
        if (id <= mid) {
            update(2*node, st, mid, id, val);
        } else {
            update(2*node+1, mid+1, en, id, val);
        }
        seg[node] = seg[2*node] + seg[2*node+1];
    }
} tree[12];

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    k++;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 11; i++) {
        tree[i].init();
    }
    tree[0].update(1, 0, n, 0, 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            long long s = tree[j - 1].query(1, 0, n, 0, a[i] - 1);
            tree[j].update(1, 0, n, a[i], s);
        }
    }
    cout << tree[k].query(1, 0, n, 0, n) << endl;
    return 0;
}




