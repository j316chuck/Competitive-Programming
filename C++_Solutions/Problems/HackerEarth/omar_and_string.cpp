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

const int maxn = 2e5 + 5;
long long mod = 1e9 + 7;
long long prime = 31;
string s;
vector<long long> lhsh, rhsh, pows;
int n, cnt[maxn], z[maxn];

void calc_hashes() {
    n = s.size();
    lhsh.resize(n + 1);
    lhsh[0] = 0, rhsh.push_back(0);
    for (int i = 0; i < n; i++) {
        lhsh[i + 1] = (lhsh[i] * prime + 1LL * (s[i] - 'a')) % mod;
    }
    for (int i = n - 1; i >= 0; i--) {
        rhsh.push_back((rhsh.back() * prime + 1LL * (s[i] - 'a')) % mod);
    }
    pows.push_back(1);
    for (int i = 0; i < n; i++) {
        pows.push_back((pows.back() * prime) % mod);
    }
}



int main() {
    Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> s;
    calc_hashes();
    //deb(pows); deb(rhsh); deb(lhsh);
    int left, right;
    for (int i = 0; i < n; i++) {
        //rhsh of palindrome
        long long l = lhsh[i + 1];
        long long r = (rhsh[n] - (rhsh[n - i - 1] * pows[i + 1]) % mod);
        r = (r + mod) % mod;
        if (r == l) {
            left = i;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        //lhsh of palindrome
        long long r = rhsh[n - i];
        long long l = lhsh[n] - ((lhsh[i] * pows[n - i]) % mod);
        l = (l + mod) % mod;
        if (r == l) {
            right = i;
        }
    }
    string str = s.substr(right) + s.substr(0, left + 1);
    n = str.size();
    int l = 0, r = 0, k = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) {
            r = l = i;
            while (r < n && str[r - l] == str[r]) r++;
            z[i] = r - l; r--;
        } else {
            k = i - l;
            if (z[k] < r - i + 1) {z[i] = z[k];}
            else {
                l = i;
                while (r < n && str[r - l] == str[r]) r++;
                z[i] = r - l; r--;
            }
        }
        cnt[z[i]]++;
    }
    cnt[n]++;
    for (int i = n - 1; i >= 1; i--) {
        cnt[i] += cnt[i + 1];
    }
    cout << str << endl;
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << ' ';
    } cout << endl;
    return 0;
}




