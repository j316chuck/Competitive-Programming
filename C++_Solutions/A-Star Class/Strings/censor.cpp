/*
ID: j316chuck
PROG: hashing
LANG: C++
DESC: common hashing functions such as substring, hext (hash), and pow
NOTE: inclusive and 0 indexed
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

const long long mod = 1e9+7;
const long long power = 31;
vector<long long> pows;

long long hext(long long hsh, int ch) {
    return (1LL * hsh * power + ch) % mod;
}

//O(n) function that caculates the powers to the n;
long long calc_pows(int n) {
    long long p = 1;
    for (int i = 0; i <= n; i++) {
        pows.push_back(p);
        p *= power;
        p = p % mod;
    }
    //deb(pows);
}


//calculates the hash value of a string in O(n)
long long hsh(string &s) {
    long long total = 0;
    for (int i = 0; i < s.length(); i++) {
        total = hext(total, s[i] - 'a');
    }
    return total;
}

int main() {
    //freopen("censor.in", "r", stdin);
    //freopen("censor.out", "w", stdout);
    string s, p;
    cin >> s >> p;
    long long cmp = hsh(p);
    vector<long long> rhsh(1,0);
    calc_pows(s.length());
    string r;
    for (int i = 0; i < s.size(); i++) {
        r += s[i];
        rhsh.push_back(hext(rhsh.back(), s[i]-'a'));
        if (r.size() >= p.size()){
            long long sub = (rhsh[r.length() - p.length()] * pows[p.length()]) % mod;
            long long newhash = (mod + rhsh.back() - sub) % mod;
            if (newhash == cmp && r.substr(r.length() - p.length()) == p) {
                r.resize(r.size() - p.size());
                rhsh.resize(rhsh.size() - p.size());
            }
        }
    }
    cout << r << endl;
}


