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

const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;
int n, q;
vector<int> graph[maxn];
int h[maxn], l[maxn], r[maxn], counter = -1;

struct SegmentTree {
    long long lazy[4 * maxn] = {0}, seg[4 * maxn] = {0};
    void push(int x, int st, int en) {
        if (lazy[x]) {
            seg[x] += 1LL * (en - st + 1) * lazy[x];
            seg[x] %= mod;
            if (st != en) {
                lazy[2 * x] += lazy[x];
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x] %= mod;
                lazy[2 * x + 1] %= mod;
            }
            lazy[x] = 0;
        }
    }
    long long query_range(int x, int st, int en, int l, int r) {
        if (r < st || en < l) {
            return 0;
        }
        push(x, st, en);
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return (query_range(2 * x, st, mid, l, r) + query_range(2 * x + 1, mid + 1, en, l, r)) % mod;
    }
    void update_range(int x, int st, int en, int l, int r, int val) {
        if (r < st || en < l) {
            return;
        }
        push(x, st, en);
        if (l <= st && en <= r) {
            lazy[x] += val;
            push(x, st, en);
            return;
        }
        int mid = (st + en) >> 1;
        update_range(2 * x, st, mid, l, r, val);
        update_range(2 * x + 1, mid + 1, en, l, r, val);
        seg[x] = (seg[2 * x] + seg[2 * x + 1]) % mod;
    }
} huk, vk;

void dfs(int u, int par, int height) {
    h[u] = height;
    l[u] = ++counter;
    for (int v : graph[u]) {
        if (par != v) {
            dfs(v, u, height + 1);
        }
    }
    r[u] = counter;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int u;
    for (int v = 2; v <= n; v++) {
        cin >> u;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, -1, 0);
    cin >> q;
    for (int i = 0, t, v; i < q; i++) {
        cin >> t >> v;
        if (t == 1) {
            long long x, k;
            cin >> x >> k;
            vk.update_range(1, 0, n - 1, l[v], r[v], k);
            huk.update_range(1, 0, n - 1, l[v], r[v], (x + 1LL * h[v] * k));
        } else {
            cout << (((huk.query_range(1, 0, n - 1, l[v], l[v]) - 1LL * h[v] * vk.query_range(1, 0, n - 1, l[v], l[v])) % mod) + mod) % mod << endl;
        }
    }
    return 0;
}




