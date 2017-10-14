/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)


const int INF = 1e9+7;
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

const int maxn = 1005;
long long k;
int ca, cb;
int ma[4][4], mb[4][4];
long long sa[maxn], sb[maxn];

int win(int a, int b) {
    if ((a == 2 && b == 1) || (a == 3 && b == 2) || (a == 1 && b == 3)) return 1;
    return 0;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> k >> ca >> cb;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> ma[i][j];
        }
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> mb[i][j];
        }
    }

    int pstart, pend;
    long long inca, incb, len;
    sa[0] = 0, sb[0] = 0;
    map< pair<int, int>, int > mp;
    for (int t = 1; t < maxn; t++) {
        sa[t] = sa[t - 1] + win(ca, cb);
        sb[t] = sb[t - 1] + win(cb, ca);
        if (mp[{ca, cb}] != 0) {
            len = t - mp[{ca, cb}];
            pstart = mp[{ca, cb}];
            pend = t;
            inca = sa[pend - 1] - sa[pstart - 1];
            incb = sb[pend - 1] - sb[pstart - 1];
            break;
        }
        mp[{ca, cb}] = t;
        int pa = ca, pb = cb;
        ca = ma[pa][pb];
        cb = mb[pa][pb];
        //cout << ca << ' ' << cb << ' ' << sa << ' ' << sb << endl;
    }
    if (pend >= k) {
        cout << sa[k] << ' ' << sb[k] << endl;
        return 0;
    }
    long long ra = sa[pstart - 1], rb = sb[pstart - 1];
    k -= (pstart - 1);
    long long rem = k % len;
    ra += (k / len) * inca;
    rb += (k / len) * incb;
    ra += sa[pstart + rem - 1] - sa[pstart - 1];
    rb += sb[pstart + rem - 1] - sb[pstart - 1];
    cout << ra << " " << rb << endl;
    return 0;
}




