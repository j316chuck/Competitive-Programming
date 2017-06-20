/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <assert.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
#define endl '\n'

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-12;
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
// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b = b - a; d = c - d; c = c - a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b * cross(c, d) / cross(b, d);
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

int main() {

    //time_t start=clock();
    //Rd("1408.in"); //make sure to put it in the correct folder
    int n;
    vector<double> A, B, C, D;
    vector<PT> tmp(4);
    PT intersect;
    while (~scanf("%d", &n) && n != 0) {
        A.clear(); B.clear(); C.clear(); D.clear();
        A.resize(n + 1); B.resize(n + 1); C.resize(n + 2); D.resize(n + 2);
        for (int i = 0; i < n; ++i) scanf("%lf", &A[i]);
        for (int i = 0; i < n; ++i) scanf("%lf", &B[i]);
        for (int i = 0; i < n; ++i) scanf("%lf", &C[i+1]);
        for (int i = 0; i < n; ++i) scanf("%lf", &D[i+1]);
        C[0] = 0, C[n+1] = 1;
        D[0] = 0, D[n+1] = 1;
        A[n] = 1; B[n] = 1;
        sort(C.begin(), C.end()); sort(D.begin(), D.end());
        sort(A.begin(), A.end()); sort(B.begin(), B.end());

        double preva = 0, nexta, prevb = 0, nextb;
        vector<PT> prevln, nextln;
        for (int i = 0; i < C.size(); ++i) prevln.push_back(PT(0, C[i]));
        double maxarea = 0.00;
        for(int i = 0; i <= n; ++i) {
            nexta = A[i];
            nextb = B[i];
            nextln.clear();
            for (int k = 0; k < D.size(); ++k) {
                intersect = ComputeLineIntersection(PT(0, C[k]), PT(1, D[k]), PT(nexta, 0), PT(nextb, 1));
                nextln.push_back(intersect);
            }
            for (int k = 0; k < nextln.size() - 1; ++k) {
                tmp[0] = prevln[k], tmp[1] = prevln[k + 1], tmp[2] = nextln[k + 1], tmp[3] = nextln[k];
                maxarea = max(ComputeArea(tmp), maxarea);
            }
            prevln = nextln;
            preva = A[i];
            prevb = B[i];
        }
        printf("%.6f\n", maxarea);
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



