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
const long long mod = 1e9 + 7;
int n, q;
vector<int> graph[maxn];
int h[maxn], l[maxn], r[maxn], counter = 0;

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

//bit[0] = huk, bit[1] = vk;
long long bit[2][maxn];
void update(int t, int x, long long val) {
    while (x < maxn) {
        bit[t][x] = (bit[t][x] + val) % mod;
        x += x & -x;
    }
}

long long sum (int t, int x) {
    long long ret = 0;
    while (x > 0) {
        ret = (ret + bit[t][x]) % mod;
        x -= x & -x;
    }
    return ret;
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
    long long x, k, val, ans;
    for (int i = 0, t, v; i < q; i++) {
        cin >> t >> v;
        if (t == 1) {
            cin >> x >> k;
            val  = (x + 1LL * h[v] * k) % mod;
            update(0, l[v], val); update(0, r[v] + 1, -val);
            update(1, l[v], k); update(1, r[v] + 1, -k);
        } else {
            ans = (sum(0, l[v]) - 1LL * h[v] * sum(1, l[v])) % mod;
            if (ans < 0) ans += mod;
            cout << ans << endl;
        }
    }
    return 0;
}




