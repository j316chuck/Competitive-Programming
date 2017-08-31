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

const int maxn = 1e5 + 10;
struct RMQ {
    int lazy[4 * maxn], seg[4 * maxn];
    void init() {
        memset(lazy, sizeof(lazy), 0);
        memset(seg, sizeof(seg), 0);
    }
    void push(int x, int st, int en) {
        if (lazy[x]) {
            seg[x] = (en - st + 1) - seg[x];
            if (st != en) {
                lazy[2 * x] ^= 1;
                lazy[2 * x + 1] ^= 1;
            }
            lazy[x] = 0;
        }
    }
    void update(int x, int st, int en, int l, int r) {
        push(x, st, en);
        if (r < st || en < l) {
            return;
        }
        if (l <= st && en <= r) {
            lazy[x]++;
            push(x, st, en);
            return;
        }
        int mid = (st + en) >> 1;
        update(2 * x, st, mid, l, r);
        update(2 * x + 1, mid + 1 , en, l, r);
        seg[x] = seg[2 * x] + seg[2 * x + 1];
    }
    int query(int x, int st, int en, int l, int r) {
        push(x, st, en);
        if (r < st || en < l) {
            return 0;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return query(2 * x, st, mid, l, r) + query(2 * x + 1, mid + 1, en, l, r);
    }
} tree[3];

void solve() {
    int mx, my, mz, qq, x1, x2, y1, y2, z1, z2, q;
    long long x, y, z, dx, dy, dz, ans, cx, cy, cz;
    scanf("%d %d %d %d", &mx, &my, &mz, &qq);
    for (int i = 0; i < 3; i++) tree[i].init();
    for (int i = 0; i < qq; i++) {
        scanf("%d", &q);
        if (q == 0) {
            scanf("%d %d", &x1, &x2);
            tree[q].update(1, 0, mx - 1, x1, x2);
        } else if (q == 1) {
            scanf("%d %d", &y1, &y2);
            tree[q].update(1, 0, my - 1, y1, y2);
        } else if (q == 2) {
            scanf("%d %d", &z1, &z2);
            tree[q].update(1, 0, mz - 1, z1, z2);
        } else {
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            x = tree[0].query(1, 0, mx - 1, x1, x2);
            y = tree[1].query(1, 0, my - 1, y1, y2);
            z = tree[2].query(1, 0, mz - 1, z1, z2);
            dx = x2 - x1 + 1;
            dy = y2 - y1 + 1;
            dz = z2 - z1 + 1;
            cx = dx - x;
            cy = dy - y;
            cz = dz - z;
            ans = x * y * z;
            ans += x * cy * cz + y * cx * cz + z * cy * cx;
            printf("%lld\n", ans);
            /*ans = x * dy * dz + y * dx * dz + z * dx * dy;
            ans -= (x * y * dz + y * z * dx + z * x * dy);
            ans += x * y *z;
            printf("%lld\n", ans);*/
        }
   }
}

int main() {
    //Rd("input.in");
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}




