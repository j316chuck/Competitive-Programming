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


int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    map<int, int> mp;
    int one = -1, two = -1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
        if (mp[a] == 1) {
            if (one == -1) {
                one = a;
            } else if (two == -1) {
                two = a;
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (mp.size() != 2 || mp[one] != mp[two]) {
        cout << "NO" << endl;
    } else {
        cout << "YES\n" << one << ' ' << two << endl;
    }

    /*if (mp.size() != 2 || (mp.begin() -> second) !=  (prev(mp.end()) -> second)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << (mp.begin() -> first) <<  ' ' << ((mp.begin()++) -> second) << endl;
    }*/
    return 0;
}



