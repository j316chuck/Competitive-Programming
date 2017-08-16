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

const int maxn = 1e6 + 5;
int ic[4 * maxn], dc[4 * maxn], n4[maxn], n7[maxn];
bool lazy[4 * maxn];
char s[maxn];

void combine(int x) {
    n4[x] = n4[2 * x] + n4[2 * x + 1];
    n7[x] = n7[2 * x] + n7[2 * x + 1];
    ic[x] = max(ic[2 * x] + n7[2 * x + 1], n4[2 * x] + ic[2 * x + 1]);
    dc[x] = max(dc[2 * x] + n4[2 * x + 1], n7[2 * x] + dc[2 * x + 1]);
}

void build(int x, int st, int en) {
    if (st == en) {
        ic[x] = dc[x] = 1;
        n4[x] = s[st] == '4';
        n7[x] = s[st] == '7';
        return;
    }
    int mid = (st + en) >> 1;
    build(2 * x, st, mid);
    build(2 * x + 1, mid + 1, en);
    combine(x);
}

void push(int x, int st, int en) {
    if (lazy[x]) {
        swap(n4[x], n7[x]);
        swap(ic[x], dc[x]);
        if (st != en) {
            lazy[2 * x] = !lazy[2 * x];
            lazy[2 * x + 1] = !lazy[2 * x + 1];
        }
        lazy[x] = false;
    }
}

void update(int x, int st, int en, int l, int r) {
    if ()
    push(x, st, en);
    int mid = (st + en) >> 1;
    update(2 * x, st, mid, l, r);
    update(2 * x + 1, mid + 1, en, l, r);
    combine(x);
}


int main() {
    //Rd("input.in");
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s ", &s);
    build(1, 0, n - 1);
    char s1[50]; int l, r;
    for (int i = 0; i < m; i++) {
        scanf("%s1 ", &s1);
        if (s1[0] == 'c') {
            printf("%d\n", ic[1]);
        } else {
            scanf("%d %d ", &l, &r);
            l--, r--;
            update(1, 0, n - 1, l, r);
        }
        //deb_array(ic, 20);
        //deb_array(dc, 20);
        //cout << endl << endl;
    }
    return 0;
}



