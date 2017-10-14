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
const long long INF = 1e18;
int n;
long long a[maxn], b[maxn], sum[maxn], cost[maxn];
vector<int> graph[maxn];
bool ok = true;

void fail() {
    cout << "NO" << endl;
    exit(0);
}

long long calc(int u) {
    if (sum[u] >= 0) {
        if (sum[u] > INF) {
            fail();
        }
        return sum[u];
    } else {
        long long k = sum[u] * cost[u];
        if (k / cost[u] != sum[u]) {
            fail();
        } if (k < -INF) {
            fail();
        }
        return k;
    }
}

long long dfs(int u, int par) {
    for (int v : graph[u]) {
        sum[u] += dfs(v, u);
        if (sum[u] < -INF) {
            fail();
        }
    }
    return calc(u);
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = b[i] - a[i];
    }
    cost[1] = 1;
    for (int i = 2; i <= n; i++) {
        int xi, ki;
        cin >> xi >> ki;
        graph[xi].push_back(i);
        cost[i] = ki;
    }
    if (dfs(1, -1) < 0 || ok == false) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}


