/*
ID: j316chuck
PROG: pointers
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


void hello(vector<int> v) {
    v.push_back(3);
    cout << &v << endl;
};

void hello2(vector<int> &v) {
    v.push_back(3);
    cout << &v << endl;
}

class cc {
    public:
    int a, b;
};

void hello3(cc &hello) {
    hello.a = 5;
}

void setToNull(int *&tempPtr) {
    tempPtr = nullptr;
}
void setToSix(int *tempPtr) {
    *tempPtr = 6;
}
void setToFive(int *tempPtr) {
    int hello = 5;
    tempPtr = &hello;
}

int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    //void foo(std::string bar); // by copy //GROE making a copy and passing it in
    //void foo(std::string& bar); // by reference //passing in
    //void foo(std::string* bar); // by address //passing in address & = dereference = shows address
    //As a side note, passing by copy is always more
    //expensive than passing by reference or pointer for
    //types that are larger than the size of a pointer.
    //For this reason, you may also often prefer to pass by
    //const reference, which will allow you to read an object
    //without having to copy it.
    /*
    Notes:
    The address-of operator (&) can only be used on the RHS.
    The indirection operator (or dereferencing operator) (*) operates on a pointer, and returns the value stored in the address kept in the pointer variable. For example, if pNumber is an int pointer, *pNumber returns the int value "pointed to" by pNumber.
    The syntax of declaring a pointer is to place a * in front of the name.
    */
    // pass by value for arrays (which are pass by pointers) and regular values. If pass by value for vector then everything is copied = O(n)
    // pass by reference when you want to change the value or are passing STL stuff
    // reference vs pointer = 1. references are immutable 2. pointers can increase and decrease giving u flexibility but causing dangerous problems

    vector<int> example;
    example.push_back(1);
    example.push_back(2);
    cout << &example << endl;
    //hello(example);
    hello2(example);
    deb(example);

    cc mya;
    mya.a = 1; mya.b = 2;
    hello3(mya); //mutation = pass by reference.
    cout << mya.a << endl;

    int p[] = {1,2,3};

    int *ptr = &mya.a;
    setToFive(ptr);
    cout << *ptr << endl;
    setToSix(ptr);
    cout << *ptr << endl;
    setToNull(ptr);
    cout << ptr << endl; //null value in cout is 0

    string s1 = "hello";
    string &s1ref = s1; //pointer = ptr and ref = ref at end;
    s1ref = "hellos";
    cout << s1 << endl;

    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



