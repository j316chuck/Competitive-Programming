/*
ID: j316chuck
PROG: http://www.geeksforgeeks.org/pollards-rho-algorithm-prime-factorization/
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
//random thoughts--okay I get the really cool implementation of this random algorithm
//this is cool let me implement this random factorization algorithm
long long int modular_pow(long long int base, int exponent,
                          long long int modulus) {
    /* initialize result */
    long long int result = 1;

    while (exponent > 0) {
        /* if y is odd, multiply base with result */
        if (exponent & 1) result = (result * base) % modulus;

        /* exponent = exponent/2 */
        exponent = exponent >> 1;

        /* base = base * base */
        base = (base * base) % modulus;
    }
    return result;
}

long long PollardRho(long long n) {
    srand(time(NULL));
    if (n == 1) return n;
    if (n % 2 == 0) return 2;
    long long x = (rand() % (n - 2)) + 2;
    long long y = x;
    long long c = (rand() % (n - 1)) + 1;

    long long d = 1;
    while (d == 1) {
        //tortoise
        x = (modular_pow(x, 2, n) + c + n) % n;
        //hare
        y = (modular_pow(y, 2, n) + c + n) % n;
        y = (modular_pow(y, 2, n) + c + n) % n;
        d = __gcd(abs(x - y), n);
        if (d == n) {
            return PollardRho(n);
        }
    }
    return d;
}
int main() {

    //time_t start=clock();
    Rd(""); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    long long n = (long long) 10967535067;
    printf("One of the divisors for %lld is %lld.", n, PollardRho(n));
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




