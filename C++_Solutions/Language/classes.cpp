/*
ID: j316chuck
PROG: classes
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

struct compare {
    bool operator() (const int &l, const int &r) {
        return l < r;
    }
};

class Rectangle {
    int width, height; //members
public:
    //constructors can only be called once
    //default constructor may be called sometimes unless other constructors are there
    Rectangle(int, int); //prototype constructor
    Rectangle(int a) : height(5), width(a) {} //weird syntax to declare class
    Rectangle() {width = 5; height = 5;}
    int area() {return width * height;} //public functions
    bool operator < (const Rectangle &r) const{
        if (width < r.width) return true;
        if (width > r.width) return false;
        return height < r.height;
    }
} rect2; //objects of the class

Rectangle::Rectangle(int a, int b) {
    width = a;
    height = b;
}

int main() {
    Rectangle rect(3, 4), rect1(3);
    cout << rect.area() << ' ' << rect1.area() << endl;
    cout << (rect < Rectangle(5, 3)) << endl;
    Rectangle * foo, * bar, * baz;
    bar = new Rectangle (5, 6);
    cout << bar -> area() << endl;
    baz = new Rectangle[2] {{2, 5}, {3, 6}};
    cout << baz[0].area() << ' ' << baz[1].area() << endl;
    delete bar;
    delete[] baz;
    return 0;
}
