/*
ID: j316chuck
PROG: template
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

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

class Point {
public:
    double x, y; //may include angle...
    int idx;
    Point(double x = 0, double y = 0) {
        this -> x = x;
        this -> y = y;
    }
    Point(double x, double y, int idx) {
        this -> x = x;
        this -> y = y;
        this -> idx = idx;
    }

    /*bool operator == (const Point &p1) {
        return abs(p1.x - x) < EPS && abs(p1.y - y) < EPS;
    }*/
    // Declare operator < taking precision into account
    bool operator < (const Point& p) const {
        if(x < p.x - EPS) return true;
        if(x > p.x + EPS) return false;
        if(y < p.y - EPS) return true;
        if(y > p.y + EPS) return false;
        return false;
    }
};

ostream &operator << (ostream & os, const Point &p) {
    os << "Point: (" << p.x << ", " << p.y;
    return os << ")";
}


struct cmp {
    int x, y;
    bool operator () (const Point &lhs, const Point &rhs) const {
        return lhs.y < rhs.y;
    }
};

bool comp(const Point &lhs, const Point &rhs) {
    return lhs.y < rhs.y;
}

inline double dist(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
//line-sweep
double closest_pair(vector<Point> &points) {
    //deb(points);
    //set<Point, bool (*)(const Point &lhs, const Point &rhs)> s(&comp);
    /*for (auto it = points.begin(); it != points.end(); ++it) {
        s.insert(*it);
    }
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << it -> x << ' ' << it -> y << endl;
    }*/
    sort(points.begin(), points.end()); //O(n log n)
    set<Point, cmp> box;
    double best = INF;
    int left = 0;
    box.insert(points[0]);
    for (int i = 1; i < points.size(); i++) {
        //O(n log n)
        while (left < i && points[i].x - points[left].x > best) {
            box.erase(points[left++]);
        }
        //this loop has a maximum of 5 iterations
        for (auto it = box.lower_bound({points[i].y - best, points[i].x - best}); it != box.end() && points[i].y + best >= it -> y; ++it) {
            best = min(best, dist(*it, points[i]));
        }
        box.insert(points[i]);
    }

    return best;
}

int main() {

    //time_t start=clock();
    //Rd(""); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    vector<Point> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    cout << closest_pair(points) << endl;
    /*Point pp = {2, 3};
    cmp px = {2, 3};
    cout << pp << endl;
    cout << px.x << ' ' << px.y << endl; */
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



