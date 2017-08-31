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

const int maxn = 305;
const long long mod = 1e9 + 7;
int n;
long long a[maxn], fac[maxn];
long long comb[maxn][maxn], dp[maxn][maxn];
vector<int> group;
map<int, int> mp;

void calc() {
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0) comb[i][j] = 1;
            else comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
        }
    }
    fac[0] = 1;
    for (int i = 1; i < maxn; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
    //deb_array(fac, maxn);
    //deb_array(comb[6], maxn);
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int b = a[i], num;
        for (int j = 2; j * j <= b; j++) {
            num = 0;
            while (b % j == 0) {
                num++;
                b /= j;
            }
            if (num & 1) {
                b *= j;
            }
        }
        mp[b]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        group.push_back(it -> second);
    }
    calc();
    //deb(group);
    dp[0][group[0] - 1] = fac[group[0]];
    int sum = group[0] + 1;
    for (int x = 1; x < group.size(); x++) {
        for (int y = 0; y <= sum; y++) {
            for (int ij = 1; ij <= group[x]; ij++) {
                for (int j = 0; j <= min(ij, y); j++) {
                    long long cur = dp[x - 1][y];
                    if (cur == 0) continue;
                    cur *= fac[group[x]];
                    cur %= mod;
                    cur *= comb[y][j];
                    cur %= mod;
                    cur *= comb[sum - y][ij - j];
                    cur %= mod;
                    cur *= comb[group[x] - 1][ij - 1];
                    dp[x][y - j + group[x] - ij] += cur;
                    dp[x][y - j + group[x] - ij] %= mod;
                }
            }
        }
        sum += group[x];
    }
    cout << dp[group.size() - 1][0] << endl;
    return 0;
}




