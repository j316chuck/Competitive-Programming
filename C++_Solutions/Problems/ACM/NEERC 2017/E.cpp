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

int n;
vector<int> pac, reward;
vector<int> r, p;

bool pop_pacman(int position, int t) {
    if (position > r.back()) {
        int d = position - r.back();
        if (d > t) {
            return false;
        }
        int goleft = (t - d) / 2, goright = t - 2 * d;
        if (goleft <= goright) {
            t -= d;
            while (r.back() < position) {
                r.pop_back();
                if (r.empty()) return true;
            }
            t -= d;
            while (t >= r.back() - position) {
                t -= (r.back() - position);
                position = r.back();
                r.pop_back();
                if (r.empty()) return true;
            }
            return true;
        } else {
            t -= d;
            while (r.back() < position) {
                r.pop_back();
                if (r.empty()) return true;
            }
            while (t >= 2 * (r.back() - position)) {
                t -= 2 * (r.back() - position);
                position = r.back();
                r.pop_back();
                if (r.empty()) return true;
            }
            return true;
        }
    } else {
        while (t >= r.back() - position) {
            t -= (r.back() - position);
            position = r.back();
            r.pop_back();
            if (r.empty()) return true;
        }
        return true;
    }
    return true;
}

bool check(int t) {
    p = pac;
    r = reward;

    for (int pp : p) {
        if (!pop_pacman(pp, t)) {
            return false;
        }
        if (r.empty()) {
            return true;
        }
    }
    return false;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char t;
        cin >> t;
        if (t == '*') {
            reward.push_back(i);
        } else if (t == 'P') {
            pac.push_back(i);
        }
    }
    reverse(reward.begin(), reward.end());

    int lo = 0, hi = 2 * n;
    while (lo < hi - 1) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi << endl;
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



