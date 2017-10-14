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

const int maxn = 4e3 + 5;
long long bit[maxn][maxn];
int n, m, q;

void update(int x, int y, long long val) {
    x++, y++; int l = y;
    for (; x < maxn; x += (x & -x)) {
        y = l;
        for (; y < maxn; y += (y & -y)) {
            bit[x][y] += val;
        }
    }
}

long long sum(int x, int y) {
    long long s = 0;
    x++, y++; int l = y;
    for (; x > 0; x -= x & -x) {
        y = l;
        for (; y > 0; y -= y & -y) {
            s += bit[x][y];
        }
    }
    return s;
}


int rr() {
    return (rand() << 15) + rand();
}

//point update simulating rectangle updates and queries with randoms;
int main() {
    // Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> q;
    int t, r1, r2, c1, c2;
    map< pair< pair<int, int> , pair<int, int> >, int> mp;
    for (int i = 0; i < q; i++) {
        cin >> t >> r1 >> c1 >> r2 >> c2;
        pair< pair<int, int> , pair<int, int> > n = {{r1, c1}, {r2, c2}};
        if (t == 1) {
            int r = rr();
            update(r1, c1, r);
            update(r2 + 1, c1, -r);
            update(r1, c2 + 1, -r);
            update(r2 + 1, c2 + 1, r);
            mp[n] = r;
        } else if (t == 2) {
            int r = mp[n];
            update(r1, c1, -r);
            update(r2 + 1, c1, r);
            update(r1, c2 + 1, r);
            update(r2 + 1, c2 + 1, -r);
            mp.erase(n);
        } else {
            //cout << sum(r1, c1) << ' ' << sum(r2, c2) << ' ' << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 <<endl;
            long long s1 = sum(r1, c1);
            long long s2 = sum(r2, c2);
            if (s1 == s2) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}


//bugs to check
//long long vs int
//mod when subtracting s = (((v1 - v2) % mod) + mod) % mod;
//base case missing
//continue/for loop iteration
//sort(1, n + 1) or sort(1, m + 1)
//uninitialized/wrongly initialized variables
//check if your input file "input.in" is right
//check if your expected answer is what you want
//re-read question / extra constraints
//re-check thought process




