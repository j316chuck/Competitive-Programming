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
const double Pi= acos(-1.0);
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

//can overload
/*+    -    *    /    =    <    >    +=   -=   *=   /=   <<   >>
<<=  >>=  ==   !=   <=   >=   ++   --   %    &    ^    !    |
~    &=   ^=   |=   &&   ||   %=   []   ()   ,    ->*  ->   new
delete    new[]     delete[]
*/
#include<iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
    void print() { cout << real << " + i" << imag << endl; }

// The global operator function is made friend of this class so
// that it can access private members
friend Complex operator + (Complex const &, Complex const &);
};


Complex operator + (Complex const &c1, Complex const &c2)
{
     return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
//syntax is classname operator (operator) and parameters of this;
//in class = can use class variables


class Fraction {
    int num, den;
public:
    Fraction(int n, int d) { num = n; den = d;}
    operator float() const { return float(num)/float(den);}
};


bool mycomp (const pair<int, int> &a, const pair<int, int> &b) { //remember to use & and to use const
    return a.first < b.first;
}

class hello {
public:
    int a, b;
    bool operator < (const hello &c) {
        if (c.a < a) return true;
        else if (c.a > a) return false;
        return c.b < b;
    }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    //works because it matches the const c1 and const c2
    c3.print();
    cout << 1 + 2 << endl;
    Fraction f(3, 5);
    vector<pair<int, int> > v = {{1,9}, {3, 4}, {5,8}, {3, 9}};
    std::sort(v.begin(), v.end(), [](const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second < right.second;
    });

    deb(v);
    sort(v.begin(), v.end(), mycomp);
    deb(v);
    sort(v.begin(), v.end());

    vector<hello> v1;
    hello g;
    g.a = 1; g.b = 2;
    v1.push_back(g); g.a = 2; g.b = 3; //vector is overloaded deep copy!
    v1.push_back(g); g.a = 0; g.b = 2; //vector is deepy copy
    v1.push_back(g); g.a = 1; g.b = 9;
    v1.push_back(g);
    sort(v1.begin(), v1.end());
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i].a << ' ' << v1[i].b << '\n';
    }
    return 0;
}

