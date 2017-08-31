/*
ID: j316chuck
PROG: 312E
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
char s[maxn];
int n, q;

struct SegmentTree {
    int lazy[4 * maxn], seg[4 * maxn];
    void init() {
        memset(lazy, -1, sizeof(lazy));
        memset(seg, 0, sizeof(seg));
    }
    void build(int x, int st, int en, int i) {
        if (st == en) {
            seg[x] = (s[st] - 'a' == i);
            return;
        }
        int mid = (st + en) >> 1;
        build(2 * x, st, mid, i);
        build(2 * x + 1, mid + 1, en, i);
        seg[x] = seg[2 *x] + seg[2 * x + 1];
    }
    void push(int x, int st, int en) {
        if (lazy[x] != -1) {
            seg[x] = lazy[x] * (en - st + 1);
            if (st != en) {
                lazy[2 * x] = lazy[x];
                lazy[2 * x + 1] = lazy[x];
            }
            lazy[x] = -1;
        }
    }
    int query_range(int x, int st, int en, int l, int r) {
        push(x, st, en);
        if (r < st || en < l) {
            return 0;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return query_range(2 * x, st, mid, l, r) + query_range(2 * x + 1, mid + 1, en, l, r);
    }
    void update_range(int x, int st, int en, int l, int r, int val) {
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
        update_range(2 * x, st, mid, l, r, val);
        update_range(2 * x + 1, mid + 1, en, l, r, val);
        seg[x] = seg[2 * x] + seg[2 * x + 1];
    }
    void solve(int x, int st, int en, int i) {
        push(x, st, en);
        if (st == en && seg[x]) {
            s[st] =  i + 'a';
            return;
        }
        if (!seg[x]) {
            return;
        }
        int mid = (st + en) >> 1;
        solve(2 * x, st, mid, i);
        solve(2 * x + 1, mid + 1, en, i);
    }
} v[26];


int main() {
    //Rd("input.in");
    Rd("input.txt");
    Wt("output.txt");
    scanf("%d %d ", &n, &q);
    scanf("%s", s);
    for (int i = 0; i < 26; i++) {
        v[i].init();
        v[i].build(1, 0, n - 1, i);
    }
    int l, r, cnt[26], odd; bool valid;
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        l--, r--, odd = -1; valid = true;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < 26; j++) {
            cnt[j] = v[j].query_range(1, 0, n - 1, l, r);
            if (cnt[j] % 2 == 1 && odd == -1) {
                odd = j;
            } else if (cnt[j] % 2 == 1 && odd != -1) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;
        int lcnt = l, rcnt = r;
        for (int j = 0; j < 26; j++) {
            v[j].update_range(1, 0, n - 1, l, r, 0);
            if (!cnt[j] || j == odd) continue;
            cnt[j] = cnt[j] >> 1;
            v[j].update_range(1, 0, n - 1, lcnt, lcnt + cnt[j] - 1, 1);
            lcnt += cnt[j];
            v[j].update_range(1, 0, n - 1, rcnt, rcnt - cnt[j] + 1, 1);
            rcnt -= cnt[j];
        }
        if (odd != -1) v[odd].update_range(1, 0, n - 1, lcnt, rcnt, 1);
    }
    for (int i = 0; i < 26; i++) {
        v[i].solve(1, 0, n - 1, i);
    }
    printf("%s\n", s);
    return 0;
}

