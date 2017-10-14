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

long long x, y;
long long dp[50][50][2][2]; //int pos, int val, int und, int is0
int n;
string s;

long long calc(int target, int target_2) {
    memset(dp, 0, sizeof(dp));
    dp[0][25][0][1] = 1;
    for (int pos = 0; pos < n; pos++) {
        for (int num = 0; num < 50; num++) {
            for (int und = 0; und < 2; und++) {
                for (int is0 = 0; is0 < 2; is0++) {
                    long long cur = dp[pos][num][und][is0];
                    if (!cur) continue;
                    for (int i = 0; i <= 9; i++) {
                        if (target_2 != -1 && !(is0 && !i) && !(i == target || i == target_2)) continue;
                        if (!und && i > s[pos] - '0') break;
                        bool new_is0 = is0 && !i;
                        int new_num = num;
                        if (!new_is0) {
                            new_num = new_num + ((i == target) ? 1 : -1);
                        }
                        int new_und = und || i < s[pos] - '0';
                        dp[pos + 1][new_num][new_und][new_is0] += cur;
                    }
                }
            }
        }
    }
    long long total = 0;
    if (target_2 != -1) {
        for (int i = 0; i < 2; i++) {
            total += dp[n][25][i][0];
        }
        return total;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 25; j < 50; j++) {
            total += dp[n][j][i][0];
        }
    }
    return total;
}

long long solve(long long num) {
    long long total = 0;
    stringstream ss;
    ss << num;
    s = ss.str();
    n = s.size();
    for (int i = 0; i <= 9; i++) {
        total += calc(i, -1);
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = i + 1; j <= 9; j++) {
            total -= calc(i, j);
        }
    }
    return total;
}

int main() {
    //Rd("input.in");
    Rd("odometer.in");
    Wt("odometer.out");
    ios_base::sync_with_stdio(0);
    cin >> x >> y;
    cout << solve(y) - solve(x - 1) << endl;
    return 0;
}




