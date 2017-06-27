/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#include <cmath>
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

class pp {
public:
    int id, h, x;
    bool operator < (const pp &a) const {
        return (x < a.x) || (x == a.x && h < a.h);
    }
};

struct cmp {
    bool operator () (const pp &a, const pp &b) const {
        return a.h > b.h;
    }
};


void sweep (const vector<pp> &v, bool left[], int d) {

}

int main() {

    //time_t start=clock();
    Rd("crowded.in"); //make sure to put it in the correct folder
    Wt("crowded.out");
    ios_base::sync_with_stdio(0);
    int n, d;
    scanf("%d %d", &n, &d);
    vector<pp> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].x, &v[i].h);
        v[i].id = i;
    }

    sort(v.begin(), v.end());
    //sweep(v, left, d);
    multiset<int, greater<int> > lo, hi;

    int total = 0, l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        while (l < n && v[l].x  + d < v[i].x) {
            lo.erase(lo.find(v[l++].h));
        }
        lo.insert(v[i].h);
        while (r < n && v[r].x <= v[i].x + d) {
            hi.insert(v[r++].h);
        }
        if (*hi.begin() >= 2 * v[i].h && *lo.begin() >= 2 * v[i].h) {
            total++;
            //cout << *hi.begin() << " " << *lo.begin() << " " << i << endl;
        }
        //to make sure there's at least one element
        hi.erase(hi.find(v[i].h));
    }
    //for (int i = 0; i < n; i++) if(left[i] && right[i]) total++;
    printf("%d\n", total);
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



