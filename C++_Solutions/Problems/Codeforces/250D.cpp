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
long long s[4 * maxn];
int a[4 * maxn];

void push(int x, int st, int en) {
    if (st != en) {
        a[x] = max(a[x << 1], a[x << 1 | 1]);
        s[x] = s[x << 1] + s[x << 1 | 1];
    }
}

void update(int x, int st, int en, int l, int val) {
    if (st == en) {
        a[x] = val;
        s[x] = val;
        return;
    }
    int mid = (st + en) >> 1;
    if (l <= mid) {
        update(x << 1, st, mid, l, val);
    } else {
        update(x << 1 | 1, mid + 1, en, l, val);
    }
    push(x, st, en);
}

long long sum(int x, int st, int en, int l, int r) {
    if (r < st || en < l) {
        return 0;
    } if (l <= st && en <= r) {
        return s[x];
    }
    int mid = (st + en) >> 1;
    return sum(x << 1, st, mid, l, r) + sum(x << 1 | 1, mid + 1, en, l, r);
}

void mod(int x, int st, int en, int l, int r, int m) {
    if (r < st || en < l) {
        return;
    }
    if (m > a[x]) {
        return;
    }
    if (st == en) {
        a[x] %= m;
        s[x] %= m;
        return;
    }
    int mid = (st + en) >> 1;
    mod(x << 1, st, mid, l, r, m);
    mod(x << 1 | 1, mid + 1, en, l, r, m);
    push(x, st, en);
}

int main() {
    //Rd("input.in");
    int n, m, val, l, r, q;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        update(1, 0, n - 1, i, val);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d %d", &l, &r);
            printf("%I64d\n", sum(1, 0, n - 1, l - 1, r - 1));
        } else if (q == 2) {
            scanf("%d %d %d", &l, &r, &val);
            mod(1, 0, n - 1, l - 1, r - 1, val);
        } else if (q == 3) {
            scanf("%d %d", &l, &val);
            update(1, 0, n - 1, l - 1, val);
        }
    }
    return 0;
}




