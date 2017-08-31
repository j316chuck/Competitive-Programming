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
vector<int> a;
int f[maxn];
int low[maxn];

int getf(int x) {
    return x == f[x] ? x : f[x] = getf(f[x]);
}

int solve(int x) {
    int id = lower_bound(a.begin(), a.end(), x) - a.begin();
    if (id >= a.size() || a[id] != x) {
        return 0;
    } else {
        return getf(x) - low[x];
    }
}

int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]] = getf(a[i] + 1);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int l, r = 0;
    for (l = 0; l < maxn; l++) {
        while(r <= getf(l)) {
            low[r] = l;
            r++;
        }
    }
    //deb(a);
    int cur = 0, x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cur ^= x;
        cout << solve(cur) << endl;
    }
}




