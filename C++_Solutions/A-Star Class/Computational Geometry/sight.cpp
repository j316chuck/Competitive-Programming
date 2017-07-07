#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
#define endl '\n'
using namespace std;

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

const double EPS = 1e-12;
const double PI = acos(-1.0);

struct PT {
    double x, y, ang;
    PT (double xx, double yy) {
        x = xx;
        y = yy;
        ang = atan2(y, x) + PI;
    }
    PT() {};
    //sorts from low to high in y;
    bool operator < (const PT &p) const {
        if (ang < p.ang - EPS) return true;
        else if (abs(ang - p.ang) < EPS) return abs(x*x + y*y) < abs(p.x * p.x + p.y * p.y);
        return false;
    }
};


ostream &operator << (ostream &os, const PT &p) {
    os << "(" << p.x << "," << p.y << "," << p.ang;
    return os << ")";
}

PT RotateCCW(PT p, double t) { //t should be in radians
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}


// tells if the direction between ab -> bc is straight, turns left (counter clockwise), or turns right (clockwise).
// 1 if left counterclockwise turn, 0 if collinear, -1 if right clockwise turn;
//double cr = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
double CCW(PT a, PT b, PT c) {
    return (b.x - a.x) * (c.y - a.y) -  (b.y - a.y) * (c.x - a.x);
}

double dist(PT p, PT q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

//returns point tangent to circle at 0,0 with radius r
PT PointTangentCircle(PT p, double r) {
    double ang = abs(acos(r/dist(p, {0,0}))) + p.ang;
    return RotateCCW({-r, 0}, ang);
}

//radial sweep with points sorted by angle with respect to origin
long long RadialSweep(vector<PT> &pts, double r) {
    sort(pts.begin(), pts.end());
    PT p, c;
    int n = pts.size();
    for (int i = 0; i < n; i++) {
        p = pts[i];
        p.ang += 2*PI;
        pts.push_back(p);
    }
    //deb(pts);
    long long total = 0;
    set<PT> st;
    for (int i = 0; i < n; i++) {
        st.insert(pts[i]);
        c = pts[i];
        p = PointTangentCircle(c, r);
        for (auto it = upper_bound(pts.begin(), pts.end(), (*prev(st.end()))); it != pts.end(); it++) {
            if (CCW(c, p, *it) < 0) {
                st.insert(*it);
            } else {
                break;
            }
        }
        st.erase(pts[i]);
        total += st.size();
    }
    return total;
}


int main() {
    Rd("sight.in");
    Wt("sight.out");
    int n; double r;
    scanf("%d %lf", &n, &r);
    vector<PT> v; double x, y;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        v.push_back({x,y});
        //cout << PointTangentCircle(v[i], r) << endl;
    }
    printf("%lld\n", RadialSweep(v, r));
}
