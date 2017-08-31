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

vector< pair<int, int> > v;
int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int n, l, r;
    cin >> n;
    v.resize(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        v[2 * i] = {l, 1};
        v[2 * i + 1] = {r + 1, -1};
    }
    sort(v.begin(), v.end());
    int cnt = 0, finish = 0, st;
    for (int i = 0; i < v.size(); i++) {
        if (cnt == 0) {
            st = v[i].first;
            finish = 0;
        }
        if (v[i].second == -1) {
            finish++;
            cnt--;
            if ((v[i].first - st) < finish) {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            cnt++;
        }
    }
    cout << "YES" << endl;
    return 0;
}



