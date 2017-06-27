/*
ID: j316chuck
PROG: line_intersection
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
    int type;
    Segment(PT s, PT e, int type) : s(s), e(e), type(type) {};
};

bool cmp(const Segment &a, const Segment &b) {
    return make_pair(a.s.x, a.s.y) < make_pair(b.s.x, b.s.y);
}

void LineIntersection(const vector<Segment> &segs, vector<PT> &res) {
    set<PT> s;
    for (int i = 0; i < segs.size(); i++) {
        if (segs[i].type == 0) {
            s.insert(segs[i].s);
        } else if (segs[i].type == 1) {
            s.erase(segs[i].e);
        } else {
            for (auto it = s.lower_bound({-INF, segs[i].s.y}); it != s.end() && it -> y <= segs[i].e.y; ++it) {
                res.push_back({segs[i].s.x, it -> y});
            }
        }
    }
}

int main() {

    //time_t start=clock();
    //Rd("line_intersection.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n, x1, y1, x2, y2;
    cin >> n;
    vector<Segment> segs;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) {
            segs.push_back(Segment({x1, y1}, {x2, y2}, 2));
        } else {
            segs.push_back(Segment({x1, y1}, {x2, y2}, 0));
            segs.push_back(Segment({x2, y2}, {x1, y1}, 1));
        }
    }

    sort(segs.begin(), segs.end(), cmp);
    vector<PT> res;
    LineIntersection(segs, res);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].x << ' ' << res[i].y << endl;
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



