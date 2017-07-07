/*
ID: j316chuck
PROG: 2242
LANG: C++
*/



#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = pow(10, -5);
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

const int N(1e6);
const int MOD(1000003);
long long fac[N+1], invfac[N+1], inv[N+1];
void Factorial() { //O(N) time where N is the largest factorial and inverse factorial you need
    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= N; ++i) {
        inv[i] = i == 1 ? 1 : inv[i - MOD % i] * ((MOD + i - 1) / i) % MOD; //calculate inv[i]
        invfac[i] = invfac[i - 1] * inv[i] % MOD;
        fac[i] = fac[i-1] * i % MOD;
    }
}

//O(n + k) where n is the largest factorial you need and k is number of queries to CombFact
long long CombFact(int n, int k) {
    return (fac[n] * invfac[k] % MOD) * invfac[n-k] % MOD;
}

int main() {

    //Rd("1067.in");
    Factorial();
    int t, n, k;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        scanf("%d %d", &n, &k);
        printf("Case %d: %lld\n", i, CombFact(n, k));
    }
}

