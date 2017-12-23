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

long long solve() {
    long long a, n, p;
    scanf("%lld %lld %lld ", &a, &n, &p);

    if (n <= 10) {
        long long prod = 1;
        for (long long i = 1; i <= n; i++) {
            prod *= i;
        }
        long long ret = 1;
        for (long long i = 1; i <= prod; i++) {
            ret *= a;
            ret %= p;
        }
        return ret;
    } else {
        map<long long, int> mp;
        map<long long, long long> result;
        //cout << a << ' ' << n << ' ' << p << endl;
        long long c = 1, mod, rem = 0;
        for (int i = 1; i < maxn; i++) {
            c *= a;
            c %= p;
            if (!mp[c]) {
                mp[c] = i;
            } else {
                int cur = mp[c];
                rem = cur - 1;
                mod = i - cur;
                for (pair<int, int> pp : mp) {
                    if (pp.second >= cur) {
                        result[pp.second - cur + 1] = pp.first;
                    }
                }
                break;
            }
        }
        if (mod == 1) {
            return result.begin() -> second;
        }
        //deb(result);
        long long prod = 1;
        for (long long i = 1; i <= n; i++) {
            prod *= i;
            prod %= mod;
        }
        prod -= rem;
        prod = (prod + mod) % mod;
        if (prod == 0) {
            prod = mod;
        }
        return (int) result[prod];
    }
}

int main() {
    Rd("input.in");
    //Wt("output.out");
    ios_base::sync_with_stdio(0);
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: %lld\n", i, solve());
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




