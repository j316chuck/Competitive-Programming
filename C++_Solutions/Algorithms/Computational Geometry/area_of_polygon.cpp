/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = pow(10, -5);
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
    double x, y;
    Point(double xx, double yy) {x = xx; y = yy;}
    bool operator == (const Point &p1) {
        return abs(p1.x - x) < EPS && abs(p1.y - y) < EPS;
    }
};

ostream &operator << (ostream & os, const Point p) {
    os << "Point: (" << p.x << ", " << p.y;
    return os << ")";
}

int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    Rd("1654.in");
    map<int, pair<int, int> > moves = {{8, {0, 1}}, {6, {1, 0}}, {2, {0, -1}}, {4, {-1, 0}},
                                        {9, {1, 1}}, {3, {1, -1}}, {1, {-1, -1}}, {7, {-1, 1}}};
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        string s;
        cin >> s;
        vector<Point> points;
        int x = 0, y = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            auto it = moves.find(s[i] - '0');
            x += (it -> second).first;
            y += (it -> second).second;
            points.push_back(Point((double) x, (double) y));
        }
        //deb(points);
        double result = 0;
        if (points.size() == 0 || points.size() == 1) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < points.size() - 1; i++) {
            result += points[i + 1].x * points[i].y - points[i + 1].y * points[i].x;
        }
        cout << abs(result) / 2.0 << endl;
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




