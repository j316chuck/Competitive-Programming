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

const long long power = 271;
const long long mod = 1e9+7;
const int maxn = 7e4+5;
vector<string> v;
vector<long long> hsh[maxn];
vector< pair<int, int> > ret;
vector<long long> pows;
map<long long, int> mp[maxn][10];
int n;

long long hext(long long val, char c) {
    return (val * power + c) % mod;
}

void calc_pows() {
    pows.push_back(1LL);
    for (int i = 0; i <= 10; i++) {
        pows.push_back((pows.back() * power) % mod);
    }
}

void calc(int j) {
    hsh[j].push_back(0);
    for (int i = 0; i < v[j].size(); i++) {
        hsh[j].push_back(hext(hsh[j].back(), v[j][i]));
    }
}

long long shsh(int j, int l, int r) {
    return (((hsh[j][r] - hsh[j][l - 1] * pows[r - l + 1]) % mod) + mod) % mod;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    calc_pows();
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        calc(i);
    }
    for (int i = 0; i < n; i++) {
        ret.push_back({-1, -1});
    }
    for (int len = 0; len <= 8; len++) {
        map<long long, int> cnt;
        for (int i = 1; i + len <= 9; i++) {
            for (int j = 0; j < n; j++) {
                long long h = shsh(j, i, i + len);
                mp[j][len][h]++;
                if (!cnt[h]) cnt[h] = 1;
                else cnt[h]++;
            }
        }
        for (int i = 1; i + len <= 9; i++) {
            for (int j = 0; j < n; j++) {
                long long h = shsh(j, i, i + len);
                if (cnt[h] == mp[j][len][h] && ret[j].first == -1) {
                    ret[j] = {i, i + len};
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ret[i].first--, ret[i].second--;
        cout << ret[i].first << ' ' << ret[i].second << ' ';
        for (int j = ret[i].first; j <= ret[i].second; j++) {
            cout << v[i][j];
        } cout << endl;
    }
    return 0;
}


