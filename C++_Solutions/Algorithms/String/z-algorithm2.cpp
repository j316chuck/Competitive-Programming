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

const int maxn = 2e5 + 5;
int z[maxn];

void zscore(string &c, string &s, int *z) {
    int l = 0, r = 0, k = 0, n = 0;
    string str = c + "-" + s;
    n = str.size();
    for (int i = 1; i < n; i++) {
        if (i > r) {
            r = l = i;
            while (r < n && str[r] == str[r - l]) r++;
            z[i] = r - l; r--;
        } else {
            k = i - l;
            if (z[k] < r - i + 1) z[i] = z[k];
            else {
                l = i;
                while (r < n && str[r] == str[r - l]) r++;
                z[i] = r - l; r--;
            }
        }
    }
}

int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    string c, s;
    cin >> c >> s;
    zscore(c, s, z);
    for (int i = c.size() + 1; i < s.size() + c.size() + 1; i++) {
        cout << z[i] << ' ';
    } cout << endl;
    return 0;
}





