/*
ID: j316chuck
PROG: map
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = pow(10, -5);
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

int main() {
    //multimap and multiset = duplicate elements...
    //log n insert find, erase count lower bound upper bound etc...
    //both map and set = binarysearch tree = O(log n) time;
    //time_t start=clock();
    Rd(""); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    map<int, int> mp = {{1,2}, {3, 4}, {4, 5}};
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << ' ' << it -> second << endl;
    }
    mp.insert({1,2}); mp.insert({3, 5}); deb(mp);
    mp.insert(pair<int, int> (3, 4));
    deb(mp);
    mp[3] = 5;
    deb(mp);
    cout << mp[3] << ' ' << mp[6] << endl;
    if (mp[6]) cout << "has six" << endl;
    mp.erase(3);
    mp.insert({3,9});
    cout << mp[3] << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



