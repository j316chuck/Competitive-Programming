/*ID: j316chuck
PROG: number theory
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

//O(log n)
int base_to_decimal(int n, int b) {
    int result = 0;
    int multiplier = 1;
    while (n > 0) {
        result += (n % 10) * multiplier;
        multiplier *= b;
        n /= 10;
    }
    return result;
}

//use this idea if it requires harder implementation
//String chars="0123456789ABCDEFGHIJ";

int decimal_to_base(int n, int b) {
    int result = 0;
    int multiplier = 1;
    while(n > 0) {
        result += (n % b) * multiplier;
        multiplier *= 10;
        n /= b;
    }
    return result;
}


int main() {
    cout << decimal_to_base(37, 2) << endl;
    cout << base_to_decimal(100101, 2) << endl;
}
