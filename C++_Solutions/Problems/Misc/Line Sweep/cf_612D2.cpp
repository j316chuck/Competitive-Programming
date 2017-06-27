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

/*struct event {
    bool s;
    int x;
    bool operator < (const event &a) const {
        if (x < a.x) return true;
        if (x > a.x) return false;
        if (s) return true;
        return false;
    }
};*/

int main() {

    //time_t start=clock();
    //Rd("cf_612D.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vector< pair<int, int> > v(2*n);
    for (int i = 0; i < n; i++) {
        cin >> v[2*i].first >> v[2*i+1].first;
        v[2*i].second = 0;
        v[2*i+1].second = 1;
    }
    sort(v.begin(), v.end());
    vector< pair<int, int> > result;
    //line sweep;
    int counter = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].second == 0) {
            counter++;
            if (counter == k) result.push_back(make_pair(v[i].first, -1));
        } else {
            counter--;
            if (counter == k - 1) result.back().second = v[i].first;
        }
        //cout << counter << endl;
        //cout << counter <<' ' << v[i].x << ' ' << v[i].s << endl;
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].first << ' ' << result[i].second << endl;
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




