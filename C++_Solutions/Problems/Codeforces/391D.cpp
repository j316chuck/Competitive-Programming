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

const int mod = 1e9 + 7;
inline int mult(int a, int b) { long long x = a; x *= (long long) b; if(x >= mod) x %= mod; return x; }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? mod - b + a : a - b; }

const int maxm = 76;
const int maxn = 20;
int n, ans;
string s;
int dp[1 << maxn][maxm];
bool valid[1 << maxn];

bool ok(int mask) {
    return mask != 0 && (mask & (mask + 1)) == 0;
}

int dfs(int i, int mask) {
    if (i == n) {
        //return ok(mask);
        return valid[mask] ? 1 : 0;
    }
    if (dp[mask][i] != -1) {
        return dp[mask][i];
    }
    int &ret = dp[mask][i] = 0;
    if (valid[mask]) ret++;
    int num = 0;
    for (int j = i; j < n; j++) {
        num *= 2;
        num += (s[j] == '1');
        if (num > 20) break;
        if (num <= 0) continue;
        ret = add(ret, dfs(j + 1, mask | (1 << (num - 1))));
    }
    return ret;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    memset(valid, false, sizeof(valid));
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < 21; i++) {
        valid[(1 << i) - 1] = true;
    }
    for (int i = 0; i < n; i++) {
        ans = add(ans, dfs(i, 0));
    }
    cout << ans << endl;
}




