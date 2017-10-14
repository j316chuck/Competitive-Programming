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

const int maxm = 1e5 + 5;
vector<int> v;
int n, x, cnt;
int a[26];

void calc() {
    for (int i = 0; (i * (i + 1)) / 2 < maxm; i++) {
        v.push_back((i * (i + 1)) / 2);
    }
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    calc();
    cin >> n;
    if (n == 0)  {
        cout << 'a' << endl;
        return 0;
    }
    while (n != 0) {
        x = upper_bound(v.begin(), v.end(), n) - v.begin() - 1;
        n -= v[x];
        a[cnt] = x;
        cnt++;
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j <= a[i]; j++) {
            cout << (char) ('a' + i);
        }
    }
    cout << endl;
    return 0;
}



