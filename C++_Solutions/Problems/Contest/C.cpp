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

const int maxn = 2e5 + 5;
vector<int> graph[maxn];
set<int> st[maxn];
int a[maxn], used[maxn], gcd[maxn];

void dfs(int u, int par) {
    for (int v : graph[u]) {
        if (v != par) {
            gcd[v] = __gcd(a[v], gcd[u]);
            st[v].insert(gcd[u]);
            for (auto it = st[u].begin(); it != st[u].end(); it++) {
                st[v].insert(__gcd(*it, a[v]));
            }
            dfs(v, u);
        }
    }
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    st[1].insert(0);
    gcd[1] = a[1];
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        int mx = gcd[i];
        /*for (auto it = st[i].begin(); it != st[i].end(); it++) {
            mx = max(mx, *it);
        }*/
        mx = max(gcd[i], *(prev(st[i].end())));
        cout << mx << ' ';
    } cout << endl;
    return 0;
}



