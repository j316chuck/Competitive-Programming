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

//calculates prime factors in O(n ^ 1/2);
void prime_factor(int n, vector<int> &v) {
    while (n % 2 == 0) {
        n /= 2;
        v.push_back(2);
    }
    //n must be odd;
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            n /= i;
            v.push_back(i);
        }
    }
    //when n is prime;
    if (n > 2) {
        v.push_back(n);
    }
}

//calculates phi in O(n ^ 1/2)
int phi(int n) {
    double result = n;
    if (n % 2 == 0) {
         while (n % 2 == 0) {
            n /= 2;
        } result /= 2;
    }
    for (int p = 3; p <= sqrt(n); p += 2) {
        if (n % p == 0) { //p must be prime for it to divide trick because of the fact that 2 goes first then 3 then 5 then etc.
            while (n % p == 0) {
                n /= p;
            }
            result *= (1.0 - (1.0)/(double) p);
        }
    }

    if (n > 1) result *= (1.0 - (1.0)/(double) n);
    return (int) result;
}

//calculate prime factor in O(log n)
//basic idea is calculate sieve and record the first prime
//then use while loop to keep on recording the least prime of n
const int maxn = 1e7 + 1;
bool prime[maxn];
int divisor[maxn];
void sieve() {
    for(int i = 2; i < maxn; i++) {
        prime[i] = true;
    }
    for(int i = 2; i < maxn; i++) {
        if(prime[i]) {
            divisor[i] = i;
            for(int j = 2; i * j < maxn; j++) {
                prime[i*j] = false;
                if(divisor[i*j] == 0) {
                    divisor[i*j] = i;
                }
            }
        }
    }
}

//factorizes n in O(1) after calculating the sieve
int prime_factorize(int n, vector<int> &divisors) {
    while(n != 1) {
        divisors.push_back(divisor[n]);
        n /= divisor[n];
    }
    /*for (int j = n; j > 1; j /= divisor[j]) {
            fn[divisor[j]]++;
            divisors.push_back(divisor[j]);
    } */
}


int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    vector<int> factors;
    prime_factor(315, factors);
    deb(factors);
    sieve();
    factors.clear();
    prime_factorize(289, factors);
    deb(factors);
    for (int i = 1; i <= 10; i++) cout << phi(i) << endl;
    return 0;
}


