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

const int maxn = 4e4 + 5;
struct SegmentTree {
    int lazy[4 * maxn], seg[4 * maxn];
    void init() {
        memset(lazy, 0, sizeof(lazy));
        memset(seg, 0, sizeof(seg));
    }
    void push(int x, int st, int en) {
        if (lazy[x]) {
            seg[x] = lazy[x];
            if (st != en) {
                lazy[2 * x] = lazy[x];
                lazy[2 * x + 1] = lazy[x];
            }
            lazy[x] = 0;
        }
    }
    void update(int x, int st, int en, int l, int r, int val) {
        push(x, st, en);
        if (r < st || en < l) {
            return;
        }
        if (l <= st && en <= r) {
            lazy[x] = val;
            push(x, st, en);
            return;
        }
        int mid = (st + en) >> 1;
        update(2 * x, st, mid, l, r, val);
        update(2 * x + 1, mid + 1 , en, l, r, val);
        seg[x] = val;
    }
    int query(int x, int st, int en, int l, int r) {
        push(x, st, en);
        if (r < st || en < l) {
            return -1;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return max(query(2 * x, st, mid, l, r), query(2 * x + 1, mid + 1, en, l, r));
    }
} tree;


void solve() {
    tree.init();
    int n;
    scanf("%d", &n);
    vector < pair<int, int> > v(n);
    map <int, int> mp;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
        mp[v[i].first] = 1;
        mp[v[i].second] = 1;
    }
    int mn = 0;
    for (auto &x : mp) {
        x.second = mn++;
    }
    for (int i = 0; i < n; i++) {
        tree.update(1, 0, maxn - 1, mp[v[i].first], mp[v[i].second], i + 1);
    }
    set<int> ans;
    for (int i = 0; i < maxn - 1; i++) {
        ans.insert(tree.query(1, 0, maxn - 1, i, i));
    }
    if (ans.find(0) != ans.end()) {
        ans.erase(0);
    }
    printf("%d\n", ans.size());
}

int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}




