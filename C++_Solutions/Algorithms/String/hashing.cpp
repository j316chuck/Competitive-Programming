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
vector<long long> lhsh;
vector<long long> rhsh;
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

//O(n) function that calculates the left hash and right hash based on index 1
void calc_hashes(string &s) {
    lhsh.push_back(0);
    for (int i = 0; i < s.length(); i++) {
        lhsh.push_back(hext(lhsh.back(), s[i] - 'a'));
    }
    //deb(lhsh);
    rhsh.push_back(0);
    for (int i = s.length() - 1; i >= 0; i--) {
        rhsh.push_back(hext(rhsh.back(), s[i] - 'a'));
    }
    //deb(lhsh);
}

//calculates the hash value of a string in O(n)
long long hsh(string &s) {
    long long total = 0;
    for (int i = 0; i < s.length(); i++) {
        total = hext(total, s[i] - 'a');
    }
    return total;
}

//O(1) function that finds the hash of a substring from l and r inclusive
long long substring_hash(int l, int r) {
    //if (l < 0 || r > s.length()) cout << "Index Out of Bounds" << endl;
    //cout << lhsh[r] << ' ' << lhsh[l] << ' ' << pows[r - l] << ' ' << lhsh[l] * pows[r - l] << endl;
    return (((lhsh[r+1] - lhsh[l] * pows[r - l + 1]) % mod) + mod) % mod;
}


int main() {
    Rd("hashing.in");
    ios_base::sync_with_stdio(0);
    string str, pat;
    cin >> pat >> str;
    int n = str.length(), m = pat.length();
    calc_pows(n);
    calc_hashes(str);
    long long pattern_hash = hsh(pat);
    int repeat = 0;
    for (int i = 0; i + m <= n; i++) {
        //cout << pattern_hash << endl;
        if (pattern_hash == substring_hash(i, i + m - 1)) {
            //substring requires length
            repeat += (pat == str.substr(i, m));
        }
    }
    cout << repeat << endl;
    return 0;
}



