/*
ID: j316chuck
PROG: 2262
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

const int MAXN = 1000000;
void sieve(bool is_prime[], vector<int> &primes) {
    for (int i = 0; i < MAXN; i++) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 4; i <= MAXN; i += 2) {
        is_prime[i] = false;
    }
    for (int i = 3; i <= MAXN; i += 2) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (long long k = (long long) i * i; k <= MAXN; k += i) {
                is_prime[k] = false;
            }
            /*for (int k = 2 * i; k <= MAXN; k += i) {
                is_prime[k] = false;
            }*/
        }
    }
}

int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    Rd("2262.in");
    int n;
    vector<int> primes;
    bool is_prime[MAXN + 1];
    sieve(is_prime, primes);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] >= n) { //never happens
                printf("Goldbach's conjecture is wrong.\n");
                break;
            } else if (is_prime[n - primes[i]]) {
                printf("%d = %d + %d\n", n, primes[i], n - primes[i]);
                break;
            }
        }
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



