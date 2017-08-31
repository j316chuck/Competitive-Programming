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

const int modular = 1e9 + 7;
const int maxn = 2005;
int m, d;
int dp[maxn][maxn][2][2];
string a, b;

int dfs(int pos, int mod, bool under, bool over) {
    if (pos == a.size()) {
        return mod == 0 ? 1 : 0;
    }
    int &ret = dp[pos][mod][under][over];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    int st = over ? 0 : a[pos] - '0';
    int en = under ? 9 : b[pos] - '0';
    for (int i = st; i <= en; i++) {
        if ((pos & 1) && i != d) continue;
        if (!(pos & 1) && i == d) continue;
        int nmod = (mod * 10 + i) % m;
        ret = (ret + dfs(pos + 1, nmod, (under || i < b[pos] - '0'), (over || i > a[pos] - '0'))) % modular;
    }
    return ret;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> m >> d >> a >> b;
    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}




