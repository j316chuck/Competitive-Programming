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

string s;
int n;
int solve(int dig) {
    return 9 * pow(10, ((dig  - 1) / 2));
}

int pal(long long num) {
    if (num < 10) return num + 1;
    stringstream ss;
    ss << num;
    s = ss.str();
    n = s.size();
    int total = 1;
    for (int i = 1; i < n; i++) {
        total += solve(n - i);
    }
    bool under = true;
    for (int i = 0; i <= (n - 1) / 2; i++) {
        if (s[i] > s[n - i - 1]) {
            under = false;
        } else if (s[i] < s[n - i - 1]) {
            under = true;
        }
        if (i == (n - 1) / 2) {
            total += (s[i] - '0');
            if (under)
                total++;
        } else {
            int a = s[i] - '0';
            if (i == 0) a--;
            total += a * pow (10, ((n - 2 * (i + 1)) + 1) / 2);
        }
    }
    if (num < 100) total--;
    return total;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        long long a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << "Case " << tt << ": " << pal(b) - pal(a - 1) << endl;
    }
    return 0;
}




