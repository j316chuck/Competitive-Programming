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
    string s;
    int l = 0, r = 0, d, m = 0;
    cin >> s;
    vector<int> ll(3), lu(3), rl(3), ru(3), chk;
    for (int i = 0; i < 3; i++) {
        int k = s[i] - '0';
        l += k;
        ll[i] = k;
        lu[i] = 9 - (k);
    }
    for (int i = 3; i < 6; i++) {
        int k = s[i] - '0';
        r += k;
        rl[i - 3] = k;
        ru[i - 3] = 9 - (k);
    }

    d = fabs(l - r);
    if (l <= r) {
        sort (lu.begin(), lu.end());
        sort(rl.begin(), rl.end());
        merge(lu.begin(), lu.end(), rl.begin(), rl.end(), back_inserter(chk));
        reverse(chk.begin(), chk.end());
        for (int i = 0; i < chk.size(); i++) {
            if (d <= 0) {
                cout << i << endl;
                return 0;
            }
            d -= chk[i];
        }
    } else {
        sort(ll.begin(), ll.end());
        sort(ru.begin(), ru.end());
        merge(ll.begin(), ll.end(), ru.begin(), ru.end(), back_inserter(chk));
        reverse(chk.begin(), chk.end());
        for (int i = 0; i < chk.size(); i++) {
            if (d <= 0) {
                cout << i << endl;
                return 0;
            }
            d -= chk[i];
        }
    }
    return 0;
}




