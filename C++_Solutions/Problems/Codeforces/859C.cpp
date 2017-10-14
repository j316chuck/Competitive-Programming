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

const int maxn = 55;
int a[maxn], dp[maxn][2], dp2[maxn][2];
int n;

void dfs(int u, int p) {
    if (dp[u][p] != -1) {
        return;
    } if (u == n - 1) {
        dp[u][p] = a[u];
        dp2[u][p ^ 1] = 0;
    } if (u == n) {
        dp[u][p] = 0;
        dp2[u][p ^ 1] = 0;
        return;
    }

    dfs(u + 1, p ^ 1);
    dp[u][p] = a[u] + dp2[u + 1][p];
    dp2[u][p ^ 1] = dp[u + 1][p ^ 1];

    dfs(u + 1, p);
    if (dp[u][p] < dp[u + 1][p]) {
        dp[u][p] = dp[u + 1][p];
        dp2[u][p ^ 1] = a[u] + dp2[u + 1][p ^ 1];
    }
    return;
}
//do game dp problems :D

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(dp, -1, sizeof(dp));
    dfs(0, 1);
    cout << dp2[0][0] << ' ' << dp[0][1] << endl;

    return 0;
}


//bugs to check
//long long vs int
//mod when subtracting s = (((v1 - v2) % mod) + mod) % mod;
//base case missing
//continue/for loop iteration
//sort(1, n + 1) or sort(1, m + 1)
//uninitialized/wrongly initialized variables
//check if your input file "input.in" is right
//check if your expected answer is what you want
//re-read question / extra constraints
//re-check thought process


//how to solve problem
//attack vs scout
//scout = see constraints, time limit, variable etc.
//attack = find brute force way/easy for loop way to solve
//classify problem type and possible solutions
//known problem/solved before?
//binary search on answer if max or min?
//partial sums to reduce complexity
//fix a node?
//consider easier examples of the problem... 2D -> 1D
//use hashing / rng to check equalities?
//for dp = base case, state, recurrence
//what are your states you need to solve problem... define extra useful states.
//independence, one to one, simplify problem state
//hashing!!!
//bold hypothesis





