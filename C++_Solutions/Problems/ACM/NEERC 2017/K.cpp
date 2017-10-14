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

const int maxn = 610;
int n, a, b, k, f, cnt;
long long total;
map<string, int> mp;
vector< pair<string, string> > g;
vector< pair<int, int> > graph;
long long cost[maxn][maxn];

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> a >> b >> k >> f;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (!mp[a]) {
            mp[a] = ++cnt;
        } if (!mp[b]) {
            mp[b] = ++cnt;
        }
        g.push_back(make_pair(a, b));
        graph.push_back(make_pair(mp[a], mp[b]));
    }

    int prev = -1;
    for (pair<int, int> p : graph) {
        if (p.first == prev) {
            if (p.first > p.second) {
                cost[p.first][p.second] += b;
            } else {
                cost[p.second][p.first] += b;
            }
            total += b;
        } else {
            if (p.first > p.second) {
                cost[p.first][p.second] += a;
            } else {
                cost[p.second][p.first] += a;
            }
            total += a;
        }
        prev = p.second;
    }

    vector<long long> v;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            if (cost[i][j] > 0) {
                v.push_back(cost[i][j]);
            }
        }
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int i = 0;
    while (k) {
        if (i >= v.size() || v[i] <= f) {
            break;
        }
        total -= (v[i] - f);
        i++;
        k--;
    }

    cout << total << endl;
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




