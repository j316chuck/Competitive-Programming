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

//http://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
//initial array can be 0 - n - 1 or 1 - n indexed;
//bit is 1 - n indexed
struct BIT {
    long long bit[maxn];
    long long sum(int x) {
        x++;
        long long ret = 0;
        while (x > 0) {
            ret += bit[x];
            x -= x & -x;
        }
        return ret;
    }
    long long update(int x, long long val) {
        x++;
        while (x < maxn) {
            bit[x] += val;
            x += x & -x;
        }
    }
    long long build(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            update(i, arr[i]);
        }
    }
    long long init() {
        memset(bit, 0, sizeof(bit));
    }
} b1, b2;

void range_update(int l, int r, long long val) {
    b1.update(l, val);
    b1.update(r + 1, -val);
    b2.update(l, (long long) (l - 1) * val);
    b2.update(r + 1, (long long) -r * val);
}

long long range_sum(int x) {
    return (long long) (x * b1.sum(x)) - b2.sum(x);
}

long long range_sum(int l, int r) {
    return range_sum(r) - range_sum(l - 1);
}

long long point_query(int x) {
    return range_sum(x) - range_sum(x - 1);
}

void solve() {
    int n, q, t, l, r; long long val;
    scanf("%d %d", &n, &q);
    b1.init(), b2.init();
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &t, &l, &r);
        if (t == 0) {
            scanf("%lld", &val);
            range_update(l, r, val);
        } else {
            printf("%lld\n", range_sum(l, r));
        }
    }
}

int main() {
    //freopen("input.in", "r", stdin);
    int t;
    scanf("%d ", &t);
    for (int i = 0; i < t; i++) {
        solve();
    }
}
