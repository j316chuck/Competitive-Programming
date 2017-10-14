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

struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x + p.x, y + p.y); }
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
    PT operator * (double c) const { return PT(x * c, y * c); }
    PT operator / (double c) const { return PT(x / c, y / c); }

    //sorts from low to high in y;
    bool operator < (const PT &p) const {
        if (p.y > y) return true;
        else if (p.y < y) return false;
        return p.x > x;
    }

    bool operator == (const PT &p) const {
         return make_pair(p.x, p.y) == make_pair(x, y);
    }
};

double dot(PT p, PT q)     { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q)   { return dot(p - q, p - q); }
double dist(PT p, PT q)    { return sqrt(dist2(p, q)); }
double cross(PT p, PT q)   { return p.x * q.y - p.y * q.x; }

// tells if the direction between ab -> bc is straight, turns left (counter clockwise), or turns right (clockwise).
// 1 if left counterclockwise turn, 0 if collinear, -1 if right clockwise turn;
//double cr = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
int CCW(PT a, PT b, PT c) {
    double cr = cross(b - a, c - a);
    if (fabs(cr) < EPS) return 0;
    else if (cr > 0) return 1;
    else return -1;
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b-a, c-d)) < EPS;
}

const int maxn = 1e3 + 5;
vector<PT> v;
bool mark[maxn];
int n;
bool one_line;

bool ok(int x) {
    vector<int> no;
    for (int i = 1; i < n; i++) {
        if (CCW(v[0], v[x], v[i]) != 0) {
            no.push_back(i);
        }
    }
    if (no.size() == 1) return true;
    if (no.size() == 0) {
        one_line = true; return false;
    }
    if (!LinesParallel(v[0], v[x], v[no[0]], v[no[1]])) {
        return false;
    }
    for (int i = 2; i < no.size(); i++) {
        if (CCW(v[no[0]], v[no[1]], v[no[i]]) != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].y;
        v[i].x = i + 1;
    }
    for (int i = 1; i < n; i++) {
        if (ok(i)) {
            cout << "YES" << endl;
            return 0;
        }
        if (one_line) {
            cout << "NO" << endl;
            return 0;
        }
    }
    for (int i = 2; i < n; i++) {
        if (CCW(v[1], v[2], v[i]) != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}



