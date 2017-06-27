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
const long double PI = 3.1415926535897932384;
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

double dot(PT p, PT q)     { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q)   { return dot(p - q, p - q); }
double dist(PT p, PT q)    { return sqrt(dist2(p, q)); }
double cross(PT p, PT q)   { return p.x * q.y - p.y * q.x; }

PT RotateCCW90(PT p)   { return PT(-p.y, p.x); }
PT RotateCW90(PT p)    { return PT(p.y, -p.x); }
PT RotateCCW(PT p, double t) { //t should be in radians
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

// compute intersection of circle centered at a with radius r
// with circle centered at b with radius R
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
  vector<PT> ret;
  double d = sqrt(dist2(a, b));
  if (d > r+R || d+min(r, R) < max(r, R)) return ret;
  double x = (d*d-R*R+r*r)/(2*d);
  double y = sqrt(r*r-x*x);
  PT v = (b-a)/d;
  ret.push_back(a+v*x + RotateCCW90(v)*y);
  if (y > 0)
    ret.push_back(a+v*x - RotateCCW90(v)*y);
  return ret;
}

// compute area of two circles intersection with circle centered at c1 with radius r1
// with circle centered at c2 with radius r2
//this is wrong and too complicated
double AreaCircleCircleIntersection(PT c1, PT c2, double r1, double r2) {
    vector<PT> intersection = CircleCircleIntersection(c1, c2, r1, r2);
    if (intersection.size() == 0) {
        if (dist(c1, c2) >= (r1 + r2)) {
            return 0.0;
        } else if (r1 > r2) {
            return PI * r2 * r2;
        } else {
            return PI * r1 * r1;
        }
    }
    if (intersection.size() == 1) {
        if (dist(c1, c2) >= (r1 + r2)) {
            return 0.0;
        } else {
            return min(r1, r2) * min(r1, r2) * PI;
        }
    }
    //parallelogram areas
    double t1 = fabs(cross(intersection[0] - c1, intersection[1] - c1));
    double t2 = fabs(cross(intersection[0] - c2, intersection[1] - c2));
    //cout << t1 << ' '  << t2 << endl;
    //cout <<sqrt(dot(intersection[0] - c1, intersection[0] - c1)) << " " << sqrt(dot(intersection[1] - c1, intersection[1] - c1)) << endl;
    double theta1 = asin(t1 / (sqrt(dot(intersection[0] - c1, intersection[0] - c1)) * sqrt(dot(intersection[1] - c1, intersection[1] - c1))));
    double theta2 = asin(t2 / (sqrt(dot(intersection[0] - c1, intersection[0] - c1)) * sqrt(dot(intersection[1] - c1, intersection[1] - c1))));
    double circlepart1 = r1 * r1 * theta1 / 2;
    double circlepart2 = r2 * r2 * theta2 / 2;
    return circlepart1 - t1/2 + circlepart2 - t2/2;
}

//CircleCircleArea2
double CircleCircleIntersection2(PT c1, PT c2, long double r11, long double r22) {
	long double d = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));
    long double r1 = r11, r2 = r22;
	if (d > r1 + r2) return 0.00;
	if (d <= abs(r1 - r2) && r1 >= r2) return PI * r2 * r2;
	if (d <= abs(r1 - r2) && r2 >= r1) return PI * r1 * r1;
    long double t1 =  2.00 * acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    long double t2 =  2.00 * acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d));
    long double a1 = (long double) 0.5 * t1 * r1 * r1 - (0.5 * r1 * r1 * sin(t1));
    long double a2 = (long double) 0.5 * t2 * r2 * r2  - (0.5 * r2 * r2 * sin(t2));
    return a1 + a2;
}

int main() {

    //time_t start=clock();
    Rd("600C.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    double r1, r2;
    PT c1, c2;
    scanf("%lf %lf %lf", &c1.x, &c1.y, &r1);
    scanf("%lf %lf %lf", &c2.x, &c2.y, &r2);
    printf("%.9f\n", CircleCircleIntersection2(c1, c2, r1, r2));
    //printf("%.9f\n", AreaCircleCircleIntersection(c1, c2, r1, r2));

    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



