// C++ routines for computational geometry.
// all of these were implemented/copied from and off of https://github.com/jaehyunp/stanfordacm/blob/master/code/Geometry.cc

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

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

// tells if the direction between ab -> bc is straight, turns left (counter clockwise), or turns right (clockwise).
// 1 if left counterclockwise turn, 0 if collinear, -1 if right clockwise turn;
int CCW(PT a, PT b, PT c) {
    double cr = cross(b - a, c - a);
    if (fabs(cr) < EPS) return 0;
    else if (cr > 0) return 1;
    else return -1;
}

bool ThreePointsCollinear(PT a, PT b, PT c) {
    return CCW(a, b, c) == 0;
}

//sorts from low to high in x;
struct LowXComparator {
    bool operator () (const PT &p1, const PT &p2) const {
        if (p2.x > p1.x) return true;
        else if (p2.x < p1.x) return false;
        return p2.y > p1.y;
    }
};

//sorts from low to high in x;
inline bool LowXSort(const PT &p1, const PT &p2) {
    if (p2.x > p1.x) return true;
    else if (p2.x < p1.x) return false;
    return p2.y > p1.y;
}

// project c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
    return a + (b-a) * dot(c-a, b-a) / dot(b-a, b-a);
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

// compute distance from c to segment between a and b
double DistancePointSegment(PT a, PT b, PT c) {
    return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}

// compute distance between point (x,y,z) and plane ax+by+cz=d
double DistancePointPlane(double x, double y, double z,
                          double a, double b, double c, double d) {
    return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b-a, c-d)) < EPS;
}

bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS;
}

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

// compute center of circle given three points
PT ComputeCircleCenter(PT a, PT b, PT c) {
  b=(a+b)/2;
  c=(a+c)/2;
  return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}


// determine if line segment from a to b intersects with
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

PT RotateCCW90(PT p)   { return PT(-p.y, p.x); }
PT RotateCW90(PT p)    { return PT(p.y, -p.x); }
PT RotateCCW(PT p, double t) { //t should be in radians
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}

// computes area of a polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.
double ComputeSignedArea(const vector<PT> &p) {
    double area = 0;
    /*for(int i = 0; i < p.size(); i++) {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }*/
    for(int i = 1; i < p.size() - 1; i++) {
        area += cross(p[i] - p[0], p[i + 1] - p[0]);
    }
    return area / 2.0;
}

double ComputeArea(const vector<PT> &p) {
  return fabs(ComputeSignedArea(p));
}

// This code computes the area or centroid of a (possibly nonconvex)
// polygon, assuming that the coordinates are listed in a clockwise or
// counterclockwise fashion.  Note that the centroid is often known as
// the "center of gravity" or "center of mass".
PT ComputeCentroid(const vector<PT> &p) {
  PT c(0,0);
  double scale = 6.0 * ComputeSignedArea(p);
  for (int i = 0; i < p.size(); i++){
    int j = (i+1) % p.size();
    c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
  }
  return c / scale;
}

// determine if point is in a possibly non-convex polygon (by William
// Randolph Franklin); returns 1 for strictly interior points, 0 for
// strictly exterior points, and 0 or 1 for the remaining points.
// Note that it is possible to convert this into an *exact* test using
// integer arithmetic by taking care of the division appropriately
// (making sure to deal with signs properly) and then by writing exact
// tests for checking point on polygon boundary
bool PointInPolygon(const vector<PT> &p, PT q) {
    bool c = 0;
    for (int i = 0; i < p.size(); i++){
    int j = (i+1)%p.size();
    if ((p[i].y <= q.y && q.y < p[j].y ||
        p[j].y <= q.y && q.y < p[i].y) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
        c = !c;
    }
    return c;
}

// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}

// compute intersection of line through points a and b with
// circle centered at c with radius r > 0
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
  vector<PT> ret;
  b = b-a;
  a = a-c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r*r;
  double D = B*B - A*C;
  if (D < -EPS) return ret;
  ret.push_back(c+a+b*(-B+sqrt(D+EPS))/A);
  if (D > EPS)
    ret.push_back(c+a+b*(-B-sqrt(D))/A);
  return ret;
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

// tests whether or not a given polygon (in CW or CCW order) is simple
bool IsSimple(const vector<PT> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i+1; k < p.size(); k++) {
      int j = (i+1) % p.size();
      int l = (k+1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l]))
        return false;
    }
  }
  return true;
}

// distance between parallel planes aX + bY + cZ + d1 = 0 and
// aX + bY + cZ + d2 = 0
double PlanePlaneDist(double a, double b, double c,
      double d1, double d2) {
    return fabs(d1 - d2) / sqrt(a*a + b*b + c*c);
}

//reflection between point x and line m
//uses the concept of finding the projection of x onto m = y
//x = y - (x - y)
PT ReflectionPointLine(const PT &a, const PT &b, const PT &x) {
    PT y = ProjectPointLine(a, b, x);
    return y - (x - y);
}

int main() {

    cout << CCW({0, 0}, {4, 4}, {1, 2}) << endl;
    cout << ReflectionPointLine({3, 3}, {0, 0}, {2, 8}) << endl;
    vector<PT> x = {{3, 4}, {4, 5}, {8, 6}, {9, 11}, {11, 1}};
    //x.push_back(make_pair(10, 11)); wrong
    x.push_back({10, 11});
    sort(x.begin(), x.end(), LowXSort);
    for (auto it = x.begin(); it != x.end(); ++it) {
        cout << *it << endl;
    }
    set<PT, LowXComparator> s(x.begin(), x.end());
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << endl;
    }

    // expected: (5,-2)
    cerr << RotateCW90(PT(2,5)) << endl;
    // expected: (-5, 2)
    cerr << RotateCCW(PT(2,5), acos(-1.0)/2) << endl;
}
