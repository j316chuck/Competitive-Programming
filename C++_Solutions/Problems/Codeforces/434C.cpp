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

const int maxn = 3e3 + 5;
string s;
int n;
int space[maxn];
map<char, int> vowels;

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> s;
    int n = s.length();
    if (n <= 2) {
        cout << s << endl;
        return 0;
    }
    vowels['a'] = 1; vowels['e'] = 1; vowels['i'] = 1; vowels['o'] = 1; vowels['u'] = 1;
    for (int i = 2; i < n; i++) {
        if (vowels[s[i]] || vowels[s[i - 1]] || vowels[s[i - 2]]) {
            continue;
        } if (space[i] || space[i - 1] || space[i - 2]) {
            continue;
        } if (s[i] != s[i - 1] || s[i - 1] != s[i - 2]) {
            space[i - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (space[i]) cout << ' ';
    }
    cout << endl;
    return 0;
}




