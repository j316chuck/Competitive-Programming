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

const int maxn = 45;
int dp[maxn][maxn][maxn][maxn], mn[maxn][maxn][maxn][maxn], graph[maxn][maxn];
int n, m;

//O(n^2m^2(n + m))
int dfs(int left, int right, int down, int up) {
    if (dp[left][right][down][up] != -1) {
        return dp[left][right][down][up];
    }
    if (left == right && down == up) {
        return 0;
    }
    int mx = 0;
    for (int i = left + 1; i <= right; i++) {
        mx = max(mx, dfs(left, i - 1, down, up) + dfs(i, right, down, up));
    }
    for (int i = down + 1; i <= up; i++) {
        mx = max(mx, dfs(left, right, down, i - 1) + dfs(left, right, i, up));
    }
    dp[left][right][down][up] = mn[left][right][down][up] + mx;
    //cout << dp[left][right][down][up] << ' ' << mx << ' ' << left << ' ' << right << " " << down << " " << up <<  endl;
    return dp[left][right][down][up];
}


void construct_min(int si, int sj) {
    mn[si][si][sj][sj] = graph[si][sj]; //i - left, right -> m, j - down, up -> n;
    for (int i = si + 1; i <= m; i++) {
        mn[si][i][sj][sj] = min(mn[si][i - 1][sj][sj], graph[sj][i]);
    }
    for (int j = sj + 1; j <= n; j++) {
        mn[si][si][sj][j] = min(mn[si][si][sj][j - 1], graph[j][si]);
    }
    for (int r = sj + 1; r <= n; r++) {
        for (int c = si + 1; c <= m; c++) {
            mn[si][c][sj][r] = min(graph[r][c], min(mn[si][c - 1][sj][r], mn[si][c][sj][r - 1]));
        }
    }
}

//O(n^2m^2)
void construct_mn() {
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            construct_min(i, j);
        }
    }
}

int solve() {
    memset(mn, 0, sizeof(mn));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++) dp[i][i][j][j] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
        }
    }
    construct_mn();
    return dfs(1, m, 1, n);
}

int main() {
    Rd("input.in");
    Wt("output.out");
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": "<< solve() << endl;
    }
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
//fix a node/constraint?
//consider easier examples of the problem... 2D -> 1D
//use hashing / rng to check equalities?
//for dp = base case, state, recurrence
//what are your states you need to solve problem... define extra useful states.
//independence, one to one, simplify problem state
//hashing!!!
//bold hypothesis
//count the reverse, build solution backwards, complementary counting
//draw out the example
//look at the other states, use them as dp or states if the current state does not work
//dp = O(N^3), recursive, or LCS, or Knapsack dp...




