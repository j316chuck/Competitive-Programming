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

const int maxn = 1e6 + 5;
int z[maxn];
int l, r, k, n;
string str;

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> str;
    n = str.size();
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && str[r - l] == str[r]) r++;
            z[i] = r - l; r--;
        } else {
            k = i - l;
            if (z[k] < r - i + 1) z[i] = z[k];
            else {
                l = i;
                while (r < n && str[r - l] == str[r]) r++;
                z[i] = r - l; r--;
            }
        }
    }
    //deb_array(z, n);
    int maxz = 0, res = 0;
    for (int i = 1; i < n; i++) {
        if (z[i] == n - i && maxz >= z[i]) {
            res = i;
            break;
        }
        maxz = max(maxz, z[i]);
    }
    if (res) {
        for (int i = res; i < n; i++) cout << str[i];
        cout << endl;
    } else {
        cout << "Just a legend" << endl;
    }
    return 0;
}





