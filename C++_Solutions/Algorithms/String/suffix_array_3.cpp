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

const int maxn = 21;
const int maxm = 1 << maxn;

struct pp {
    int nr[2], ind;
    bool operator < (const pp &a) const {
        return a.nr[0] == nr[0] ? nr[1] < a.nr[1] : nr[0] < a.nr[0];
    }
} L[maxm];

int P[maxn][maxm];
int SA[maxm];
int n, stp;
string s, t;

void construct_suffix_array(string &str) {
    n = str.size();
    memset(P, -1, sizeof(P));
    memset(SA, 0, sizeof(SA));
    for (int i = 0; i < n; i++) {
        P[0][i] = str[i] - 'a';
    }
    stp = 0;
    for (int i = 1; (1 << stp) < n; i++, stp++) {
        for (int j = 0; j < n; j++) {
            L[j].ind = j;
            L[j].nr[0] = P[i - 1][j];
            L[j].nr[1] = j + (1 << stp) < n ? P[i - 1][j + (1 << stp)] : -1;
        }
        sort(L, L + n);
        for (int j = 0; j < n; j++) {
            P[i][L[j].ind] = j > 0 && L[j].nr[0] == L[j - 1].nr[0] && L[j].nr[1] == L[j - 1].nr[1] ? P[i][L[j - 1].ind]: j;
        }
    }
    if (n == 1) {
        P[0][0] = 0;
        stp = 1;
    }
    stp--;
    for (int j = 0; j < n; j++) {
        SA[j] = P[stp][j];
    }
}

int LCP(int i, int j) {
    if (i == j) return n - j;
    int ret = 0;
    for (int x = stp; x >= 0; x--) {
        if (i + (1 << x) <= n && j + (1 << x) <= n && P[x][i] == P[x][j]) {
            ret += (1 << x);
            i += (1 << x);
            j += (1 << x);
        }
    }
    return ret;
}

int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> s >> t;
    s += t;
    construct_suffix_array(s);
    //deb_array(SA, s.size());
    //cout << LCP(1, 4) << " " << LCP(1, 9) << " " << LCP(1, 1);
    return 0;
}




