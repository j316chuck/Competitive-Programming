/*
ID: j316chuck
PROG: CRT
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

/*
Given a, b, m, n with gcd(m, n) = 1
Find x with x ≡ a (mod m) and x ≡ b (mod n)
◮ Solution:
Let n-1 be the inverse of n modulo m
Let m-1 be the inverse of m modulo n
Set x = ann−1 + bmm−1
(check this yourself)
◮ Extension: solving for more simultaneous equations
*/
int gcd_iterative (int a, int b) {
    while(b) {int r = a % b; a = b; b = r;}
    return a;
}

//gcd in O(log n)
int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int floor_mod (int mod, int x) {
    return ((x % mod) + mod) % mod;
}

//Extended GCD, ax + by = d. ax = d mod b,  ax = d mod y
int extended_gcd (int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_gcd(b, a % b, x1, y1);
    y = (x1 - (a / b) * y1);
    x = y1;
    return d;
}

//O(n log a-b) where n is number of remainders
int chinese_remainder_theorem(vector<int> &remainders, vector<int> &modulos) {
    int M = 1;
    for (int i = 0; i < modulos.size(); i++) {
        M *= modulos[i];
    }
    int result = 0;
    for (int i = 0; i < modulos.size(); i++) {
        int Mk = M / modulos[i];
        int x, y;
        extended_gcd(Mk, modulos[i], x, y);
        result += x * Mk * remainders[i];
        result = floor_mod(M, result);
    }
    return result;
}

//black magic that calculates the inverse modulo of an array of integers mod m for up to n digits;
vector<int> inverse_array(int n, int m) {
	vector<int> modInverse(n + 1, 0);
	modInverse[1] = 1;
	for(int i = 2; i <= n; i++) {
		modInverse[i] = (-(m/i) * modInverse[m % i]) % m + m;
	}
	return modInverse;
}

int main() {
    //tests
    //cout << gcd (12, 4) << ' ' << gcd(18, 7) << endl;
    //int x, y;
    //cout << extended_gcd(56, 32, x, y); //it doesn't work if you chain it together like << x << ' ' << y << endl;
    //cout << ' ' << x << ' ' << y << endl;
    //modulos must all be pairwise relatively prime;
    vector<int> modulos = {7, 8};
    vector<int> remainders = {6, 4};
    cout << chinese_remainder_theorem(remainders, modulos) << endl;
    vector<int> m = {5, 7, 9, 11};
    vector<int> r = {1, 2, 3, 4};
    printf("%d\n", chinese_remainder_theorem(r, m));
}
