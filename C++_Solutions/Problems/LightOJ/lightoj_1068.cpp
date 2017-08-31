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

int a, b, k, t, n;
string s;

const int maxn = 11;
const int maxm = 95;
const int maxk = 1000;
int dp[maxn][maxm][maxk][2];

int dfs(int pos, int sum, int mod, bool under) {
    if (pos == n) {
        return (sum % k == 0 && mod == 0) ? 1 : 0;
    }
    if (dp[pos][sum][mod][under] != -1) {
        return dp[pos][sum][mod][under];
    }
    int &ret = dp[pos][sum][mod][under] = 0;
    for (int dig = 0; dig < 10; dig++) {
        if (!under && dig > s[pos] - '0') {
            break;
        } else {
            ret += dfs(pos + 1, sum + dig, (mod * 10 + dig) % k, (under || dig < s[pos] - '0'));
        }
    }
    return ret;
}

int solve(int x) {
    //if (x == 0) return 0;
    memset(dp, -1, sizeof(dp));
    stringstream ss;
    ss << x;
    s = ss.str();
    n = s.size();
    return dfs(0, 0, 0, false);
}

int digit(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int naive() {
    int ans = 0;
    for (int i = 0; i <= b; i += k) {
        if (i < a) {
            continue;
        }
        ans += (digit(i) % k == 0);
    }
    return ans;
}

int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b >> k;
        if (k < maxk) {
            cout << "Case " << i <<  ": " << solve(b) - solve(a - 1) << endl;
        } else {
            cout << "Case " << i <<  ": " << naive() << endl;
        }
    }
    return 0;
}




