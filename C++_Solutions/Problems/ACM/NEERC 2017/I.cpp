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

struct pp {
    int r, c; long long v;
};

const int maxn = 255;
const int dr[4] = {0, 1, 0, -1}; //NESW
const int dc[4] = {1, 0, -1, 0}; //NESW
int n, m;
long long qq, p;
char graph[maxn][maxn];
long long sum[maxn][maxn];
bool mark[maxn][maxn];

bool valid (int r, int c, long long v) {
    if (v == 0 || r < 1 || r > n || c < 1 || c > m || mark[r][c] || graph[r][c] == '*') return false;
    return true;
}

void bfs(long long val, int row, int col) {
    memset(mark, false, sizeof(mark));
    queue<pp> q;
    q.push({row, col, val});
    int r, c, nr, nc; long long v, nv;
    while (!q.empty()) {
        r = q.front().r;
        c = q.front().c;
        v = q.front().v;
        if (!valid(r, c, v)) {
            q.pop();
            continue;
        }
        mark[r][c] = true;
        sum[r][c] += v;
        q.pop();
        for (int i = 0; i < 4; i++) {
            nr = r + dr[i];
            nc = c + dc[i];
            nv = v / 2;
            //if (valid(nr, nc, nv)) {
            q.push({nr, nc, nv});
            //}
        }
    }
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> qq >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ('A' <= graph[i][j] && graph[i][j] <= 'Z') {
                long long v = (graph[i][j] - 'A' + 1) * qq;
                bfs(v, i, j);
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sum[i][j] > p) {
                result++;
            }
        }
    }
    cout << result << endl;
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
//use cerr when debugging

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




