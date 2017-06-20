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

const int INF = 0x3f3f3f3f;
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

//O(N) time where N is the largest factorial and inverse factorial you need
const int N(222222);
const int MOD(1e9+7);
long long fac[N + 1], invfac[N + 1], inv[N + 1];
long long Factorial() {
    fac[0] = invfac[0] = 1;
    for (int i = 1; i <= N; ++i) {
        inv[i] = i == 1 ? 1 : inv[i - MOD % i] * ((MOD + i - 1) / i) % MOD; //calculate inv[i]
        invfac[i] = invfac[i - 1] * inv[i] % MOD;
        fac[i] = fac[i-1] * i % MOD;
    }
}

//O(N) + k  where N is the largest factorial you need and k is number of queries to comb
long long CombFact(int n, int k) {
    //cout << fac[n] << ' ' << invfac[k] << ' ' << invfac[n - k] << endl;
    return (((fac[n] * invfac[k] + MOD) % MOD) * invfac[n - k] + MOD) % MOD;
}

int main() {

    //time_t start=clock();
    Rd("419D.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    Factorial();
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int par = 1;
    while (n % 4 != 1) {
        int temp[200005] = {};
        int par = 1;
        for (int i = 0; i < n - 1; i++) {
            if (par) temp[i] = a[i] + a[i+1] % MOD;
            else temp[i] = (a[i] - a[i+1] + MOD) % MOD;
            par ^= 1;
        }
        memcpy(a, temp, sizeof(temp));
        n--;
    }
    LL ret = 0;
    for (int i = 0; i < n; i+= 2) {
        ret = ret + (CombFact(n/2, i/2) * a[i]) % MOD;
        ret %= MOD;
    }
    cout << ret << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



