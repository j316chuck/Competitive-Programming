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

bool is_prime(int n) { //O(sqrt(N) / 2);
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void sieve(int n, bool prime[], int phi[]) { //O(nlogn logn) can be up to 10 million
    for (int i = 0; i <= n; i++) prime[i] = true, phi[i] = i;
    prime[0] = false; prime[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (prime[i]) {
            phi[i] = i - 1;
            for (int k = i + i; k <= n; k += i) { //not 2 * i or 3 * i or 4 * i... because already covered until i
                phi[k] /= i;
                phi[k] *= i - 1;
                prime[k] = false;
            }
            /* for (long long k = (long long) i * i; k <= MAXN; k += i) { // a little bit faster
                is_prime[k] = false;
            } */
        }
    }
    //return prime;
}


int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    /*for (int i = 0; i <= 100; i++) {
        cout << is_prime(i) << endl;
    }*/
    //arrays are annoying af just pass it in instead of trying to return one
    bool result[101];
    int phi[101];
    sieve(100, result, phi);
    for (int i = 0; i <= 100; i++) {
        cout << i << " is prime? " << result[i] << endl;
        cout << i << " phi counter: " << phi[i] << endl;
    }
    return 0;
}


