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

int n, x;
const int maxn = 1e6 + 1;
bool mark[maxn];


void output() {
    cout << "YES" << endl;
    for (int i = 0; i < maxn; i++) {
        if (mark[i]) cout << i << ' ';
    }
    cout << endl;
}

void solve(int num) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> distribution(0, 999999);
    int counter = 0;
    for (int i = 1; i <= num; i++) {
        while (true) {
            int k = distribution(gen);
            int k2 = distribution(gen);
            cout << k << ' ' << k2 << endl;
            if (!mark[k] && !mark[k2] && k ^ k2 < maxn && !mark[k ^ k2]) {
                mark[k] = true;
                mark[k2] = true;
                mark[k ^ k2] = true;
                break;
            }
        }
    }
}

/*void solve(int num) {
    int x = 1e5 + 128;
    int y = 5e5 + 128;
    for (int i = 1; i <= num; i++) {
        while (true) {
            x++, y++;
            if (!mark[x] && !mark[y] && !mark[x ^ y] && (x ^ y) < maxn) {
                mark[x] = true;
                mark[y] = true;
                mark[x ^ y] = true;
                break;
            }
        }
    }
}*/

int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> x;
    if (x == 0) {
        if (n == 2) {
            cout << "NO" << endl;
            return 0;
        } else if (n % 3 == 2) {
            mark[0] = true;
            mark[1] = true;
            mark[2] = true;
            mark[4] = true;
            mark[7] = true;
            solve((n - 5) / 3);
        } else if (n % 3 == 1) {
            mark[0] = true;
            solve(n / 3);
        } else {
            solve(n / 3);
        }
        output();
        return 0;
    }
    if ((n % 3) == 0) {
        mark[0] = true;
        mark[x ^ 1] = true;
        mark[1] = true;
        solve((n - 3) / 3);
    } else if (n % 3 == 2) {
        mark[0] = true;
        mark[x] = true;
        solve(n / 3);
    } else {
        mark[x] = true;
        solve(n / 3);
    }
    output();
    return 0;
}



