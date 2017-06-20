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

const int INF = 0x3f3f3f3f;
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

bool Palindrome(int *s) {
    return s[0] == s[3] && s[1] == s[2];
}

int main() {

    //time_t start=clock();
    //Rd("419A.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int s[4];
    string str;
    cin >> str;
    str.erase(2, 1);
    for (int i = 0; i < 4; ++i) s[i] = str[i] - '0';
    int counter = 0;
    while (!Palindrome(s)) {
        ++counter;
        s[3]++;
        if (s[3] >= 10) {
            s[3] = 0;
            s[2]++;
        }
        if (s[2] >= 6) {
            s[2] = 0;
            s[1]++;
        }
        if (s[1] >= 10) {
            s[1] = 0;
            s[0]++;
        }
        if (s[0] >= 2 && s[1] >= 4) {
            s[0] = 0;
            s[1] = 0;
        }

    }
    cout << counter << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



