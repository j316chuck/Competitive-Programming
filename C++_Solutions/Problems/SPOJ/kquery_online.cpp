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

const int maxn = 3e4 + 5;
vector<int> v[4 * maxn];
int a[maxn];
int n, q;

void build(int x, int st, int en) {
    if (st == en) {
        v[x].push_back(a[st]);
        return;
    }
    int mid = (st + en) >> 1;
    build(2 * x, st, mid);
    build(2 * x + 1, mid + 1, en);
    merge(v[2 * x].begin(), v[2 * x].end(), v[2 * x + 1].begin(), v[2 * x + 1].end(), back_inserter(v[x]));
}

int query(int x, int st, int en, int l, int r, int val) {
    if (r < st || en < l) {
        return 0;
    }
    if (l <= st && en <= r) {
        return v[x].size() - (int) (upper_bound(v[x].begin(), v[x].end(), val) - v[x].begin());
    }
    int mid = (st + en) >> 1;
    return query(2 * x, st, mid, l, r, val) + query(2 * x + 1, mid + 1, en, l, r, val);
}

int main() {
    //Rd("input.in");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &q);
    build(1, 0, n - 1);
    int last_ans = 0;
    int i, j, k;
    for (int qq = 0; qq < q; qq++) {
        scanf("%d %d %d", &i, &j, &k);
        i ^= last_ans;
        j ^= last_ans;
        k ^= last_ans;
        i--, j--, k;
        last_ans = query(1, 0, n - 1, i, j, k);
        printf("%d\n", last_ans);
    }
    return 0;
}




