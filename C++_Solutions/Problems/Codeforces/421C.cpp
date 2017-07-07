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

int main() {

    //time_t start=clock();
    Rd("421C.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int a, b, l, r, c;
    cin >> a >> b >> l >> r;
    int m = max(a+1, a+(a-b));
    bool used[m] = {0};
    for (int i = l; i <= r; i++) {
        if (i > l + 100) break;
        c = (i % (a + b)) - 1 + a + b;
        c = c % (a + b);
        if (a <= b) {
            if (c < a) {
                if (used[c]) {
                    cout << a + 1 << endl;
                    return 0;
                }
                used[c] = true;
            } else {
                int m1 = a;
                for (int i = 0; i <= a; i++) {
                    if (used[i]) {
                        m1 = i;
                        break;
                    }
                }
                used[m1] = true;
            }
        } else {
            cout << c << endl;
            if (c < a) {
                m[c] =
            } else {
                int m1 = m - 1;
                for (int i = m - 1; i >= 0; i--) {
                    if (used[i]) {
                        m1 = i; break;
                    }
                }
                used[m1] = true;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < m; i++) {
        total += used[i];
    }
    cout << total << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



