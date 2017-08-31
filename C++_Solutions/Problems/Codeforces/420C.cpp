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

int main() {

    //time_t start=clock();
    Rd("420C.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    priority_queue<int> pq;
    vector<int> stk;
    int next, prev, curr = 1, total = 0;
    for (int kk = 0; kk < 2 * n; kk++) {
        cin >> s;
        if (s[0] == 'a') {
            prev = next;
            cin >> next;
            pq.push(next);
            if (prev > next) {
                stk.push_back(0);
            } else {
                stk.push_back(-1);
            }
        } else {
            if (next == curr) {
                curr++;
                pq.pop();
                stk.pop_back();
            } else {
                pq.pop();
                memset(stk, -1, sizeof(stk));
                next = pq.top();
                curr++;
                total++;
                //cout << total << ' ' << next << endl;
            }
        }
    }
    cout << total << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}


