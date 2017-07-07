/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const double Pi= acos(-1.0);
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

//o(n ^ 1/2)
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

//O(n log n) can be up to 10 million
//made small mistake initially of going from 0 to sqrt(maxn) instead of n
//n (1/2 + 1/3 + 1/4 + 1/5 ...) is harmonic sum bounded by nlogn
const int maxn = 1e6 + 5;
bool prime[maxn];
int phi[maxn];
vector<int> primes;
void sieve() {
    for (int i = 0; i < maxn; i++) prime[i] = true, phi[i] = i;
    prime[0] = false; prime[1] = false;
    for (int i = 2; i < maxn; i++) {
        if (prime[i]) {
            phi[i] = i - 1;
            for (int k = i + i; k < maxn; k += i) {
                phi[k] /= i;
                phi[k] *= i - 1;
                prime[k] = false;
            }
            primes.push_back(i);
        }
    }
}

//formula: sum of all gcd of n from 1 - n is
//summation of d * phi(n/d) for all d that divides n
//this is because gcd(a, n) = d if and only if gcd(1, n/a) = 1 = phi(n/a)
//complexity O(n * (1 + 1/2 + 1/3 + .. 1/n)) = O(n log n)
int gcdsum[maxn];
void GCDSum() {
    for (int gcd = 1; gcd < maxn; gcd++) {
        for (int n = gcd; n < maxn; n += gcd) {
            gcdsum[n] += gcd * phi[n/gcd];
        }
    }
}


int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    sieve();
    for (int i = 0; i <= 100; i++) {
        cout << i << " is prime? " << prime[i] << endl;
        cout << i << " phi counter: " << phi[i] << endl;
    }
    cout << "First 100 primes are: ";
    for (int i = 0; i < 100; i++) {
        cout << primes[i] << ' ';
    }
    cout << endl;
    return 0;
}


