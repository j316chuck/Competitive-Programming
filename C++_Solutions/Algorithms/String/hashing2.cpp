/*
ID: j316chuck
PROG: hashing
LANG: C++
DESC: solves hackerearth problem that finds the longest length of a substring that exists in a string at least twice
NOTE: inclusive and 0 indexed (has bug)
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

//O(n) function that calculates the left hash and right hash based on index 0
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

bool valid(int len, string &s) {
    map<long, int> mp;
    long long hsh;
    for (int i = 0; i + len <= s.length(); i++) {
        hsh = substring_hash(i, i + len - 1);
        if (mp.find(hsh) != mp.end()) {
            mp[hsh]++;
        } else {
            mp[hsh] = 1;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it -> second >= 2) {
            return true;
        }
    }
    return false;
}


int main() {
    Rd("hashing2.in");
    ios_base::sync_with_stdio(0);
    string str;
    cin >> str;
    int n = str.length();
    calc_pows(n);
    calc_hashes(str);
    int lo = 0, hi = n+1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (valid(mid, str)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
    return 0;
}




