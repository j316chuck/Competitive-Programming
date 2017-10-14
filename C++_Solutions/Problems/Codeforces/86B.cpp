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

const long long mod = 1e9 + 7;
const int maxn = 2e3 + 5;
bool o1[maxn], o2[maxn];

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    string s, s1, s2;
    cin >> s >> s1 >> s2;
    int n = s.size(), n1 = s1.size(), n2 = s2.size();
    vector<int> v1, v2;
    for (int i = 0; i < n; i++) {
        if (s.substr(i, n1) == s1) {
            v1.push_back(i);
            o1[i] = true;
        } if (s.substr(i, n2) == s2) {
            v2.push_back(i + n2 - 1);
            o2[i + n2 - 1] = true;
        }
    }


    unordered_set<long long> st;
    for (int i = 0; i < v1.size(); i++) {
        long long hsh = 1;
        for (int j = v1[i]; j < n; j++) {
            hsh = hsh * 8677 + (s[j] - 'a');
            if (o2[j] && j - v1[i] + 1 >= max(n1, n2)) {
                st.insert(hsh);
            }
        }
    }

    cout << st.size() << endl;
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




