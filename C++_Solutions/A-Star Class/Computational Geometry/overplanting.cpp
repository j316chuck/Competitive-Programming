/*
ID: j316chuck
PROG: union_area_rectangles
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

ostream &operator << (ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << ")";
    return os << "";
}

struct Segment {
    PT s, e;
    int type, index;
    Segment(PT s, PT e, int type, int index) : s(s), e(e), type(type), index(index) {};
    Segment(){};
};

bool xcmp(const Segment &a, const Segment &b) {
    return make_pair(a.s.x, a.s.y) < make_pair(b.s.x, b.s.y);
}

bool ycmp(const Segment &a, const Segment &b) {
    return make_pair(a.s.y, a.s.x) < make_pair(b.s.y, b.s.x);
}

ostream &operator << (ostream &os, const Segment &s) {
    os << "Segment: " << s.s << ", " << s.e;
    return os << "";
}
//v is sorted by x from small to big
//h is sorted by y from small to big
long long UnionAreaRectangles(vector<Segment> &v, vector<Segment> &h, int n) {
    long long area = 0;
    bool in[n];
    memset(in, false, sizeof(in));
    Segment c;
    double xdelta, ystart, cnt;
    in[v[0].index] = true;
    for (int i = 1; i < v.size(); i++) {
        c = v[i];
        xdelta = c.s.x - v[i-1].s.x;
        if (xdelta < EPS) {
            in[c.index] = c.type;
            continue;
        }
        cnt = 0;
        for (int k = 0; k < h.size(); k++) {
            if (!in[h[k].index]) {
                continue;
            } else if (!h[k].type) {
                if (cnt == 0) ystart = h[k].s.y;
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) area += xdelta * (h[k].s.y - ystart);
            }
        }
        in[c.index] = c.type;
    }
    return area;
}

int main() {
    freopen("overplanting.in", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<Segment> v(2*n);
    vector<Segment> h(2*n);
    double sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf %lf", &sx, &sy, &ex, &ey);
        v[2*i] = {{sx, sy}, {ex, ey}, 1, i};
        v[2*i+1] = {{ex, ey}, {sx, sy}, 0, i};
        h[2*i] = {{sx, sy}, {ex, ey}, 1, i};
        h[2*i+1] = {{ex, ey}, {sx, sy}, 0, i};
    }
    //sorted by x
    sort(v.begin(), v.end(), xcmp);
    sort(h.begin(), h.end(), ycmp);
    printf("%lld\n", UnionAreaRectangles(v, h, n));
    /*for (int i = 0; i < v.size(); i++) {
        cout << v[i].s << endl;
    }*/
}

