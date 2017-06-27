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

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

bool check(int *a, int *b, int *c, int n) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != c[i]) counter++;
    }
    if (counter >= 2) return false;
    counter = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] != c[i]) counter++;
    }
    return counter < 2;
}
int main() {

    //time_t start=clock();
    //Rd("418B.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n], b[n];
    vector<int> rep; vector<int> miss;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        miss.push_back(i + 1);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            miss.erase(find(miss.begin(), miss.end(), a[i]));
        } else {
            rep.push_back(i);
        }
    }
    if (rep.size() == 1) {
        for (int i = 0; i < n; i++) {
            if (i != rep[0]) {
                cout << a[i] << ' ';
            } else {
                cout << miss[0] << ' ';
            }
        } cout << endl;
    } else {
        int c[n];
        memcpy(c, a, sizeof(a));
        c[rep[0]] = miss[0];
        c[rep[1]] = miss[1];
        if (check(a, b, c, n)) {
            output(c, n);
            return 0;
        }
        c[rep[0]] = miss[1];
        c[rep[1]] = miss[0];
        output(c, n);
    }

    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



