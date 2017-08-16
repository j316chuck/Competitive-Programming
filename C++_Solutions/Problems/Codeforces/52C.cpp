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

const long long INF = 1e18+5;
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

const int maxn = 2e5 + 5;
int n, q;
long long a[maxn];

struct RMQ {
    long long a[maxn], lazy[4 * maxn], seg[4 * maxn];
    void init(long long *arr, int n) {
        //fill(seg, seg + maxn, INF);
        //fill(a, a + maxn, INF);
        for (int i = 0; i < n; i++) {
            a[i] = arr[i];
        }
    }
    void build(int x, int st, int en) {
        if (st == en) {
            seg[x] = a[st];
            return;
        }
        int mid = (st + en) >> 1;
        build(2 * x, st, mid);
        build(2 * x + 1, mid + 1, en);
        seg[x] = min(seg[2 * x], seg[2 * x + 1]);
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
    void update(int x, int st, int en, int l, int r, long long val) {
        push(x, st, en);
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
        seg[x] = min(seg[2 * x], seg[2 * x + 1]);
    }
    long long query(int x, int st, int en, int l, int r) {
        push(x, st, en);
        if (r < st || en < l) {
            return INF;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return min(query(2 * x, st, mid, l, r), query(2 * x + 1, mid + 1, en, l, r));
    }
} rmq;


int main() {
    //Rd("input.in");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%I64d", a + i);
        //rmq.update(1, 0, n - 1, i, i, a[i]);
    }
    rmq.init(a, n);
    rmq.build(1, 0, n - 1);
    char s[1024]; int l, r; long long val;
    scanf("%d ", &q);
    for (int i = 0; i < q; i++) {
        gets(s);
        if (sscanf(s, "%d %d %I64d", &l, &r, &val) == 3) {
            if (l <= r) {
                rmq.update(1, 0, n - 1, l, r, val);
            } else {
                rmq.update(1, 0, n - 1, l, n - 1, val);
                rmq.update(1, 0, n - 1, 0, r, val);
            }
        } else {
            if (l <= r) {
                printf("%I64d\n", rmq.query(1, 0, n - 1, l, r));
            } else {
                printf("%I64d\n", min(rmq.query(1, 0, n - 1, l, n - 1), rmq.query(1, 0, n - 1, 0, r)));
            }
        }
    }
    return 0;
}




