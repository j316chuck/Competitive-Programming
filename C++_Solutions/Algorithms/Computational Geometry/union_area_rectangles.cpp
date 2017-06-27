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

long long UnionAreaRectangles(vector<Segment> &v, vector<Segment> &h, int n) {
    long long area = 0.0, ystart, xdelta;
    sort(v.begin(), v.end(), xcmp); //v = process horizontally
    sort(h.begin(), h.end(), ycmp); //h = process vertically
    int cnt = 0;
    bool in[n] = {0};
    in[v[0].index] = true;
    Segment c;

    //horizontal line sweep
    for (int i = 1; i < v.size(); i++) {
        c = v[i];
        xdelta = c.s.x - v[i-1].s.x;
        cnt = 0;
        if (fabs(xdelta) < EPS) {
            in[c.index] = c.type == 0;
            continue;
        }
        //vertical line sweep
        for (int k = 0; k < h.size(); k++) {
            if (!in[h[k].index]) {
                continue;
            } else if (h[k].type == 0) {
                if (cnt == 0) ystart = h[k].s.y;
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) area += (h[k].s.y - ystart) * xdelta;
            }
        }
        in[c.index] = c.type == 0;
    }
    return area;
}

int main() {

    //time_t start=clock();
    Rd("union_area_rectangles.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n, x1, y1, x2, y2;
    cin >> n;
    vector<Segment> v, h;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        v.push_back(Segment({x1, y1}, {x2, y2}, 0, i));
        v.push_back(Segment({x2, y2}, {x1, y1}, 1, i));
        h.push_back(Segment({x1, y1}, {x2, y2}, 0, i));
        h.push_back(Segment({x2, y2}, {x1, y1}, 1, i));
    }

    cout << UnionAreaRectangles(v, h, n) << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



