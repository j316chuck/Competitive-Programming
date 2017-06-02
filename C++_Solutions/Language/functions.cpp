/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h> //system header file
#include "library.h" //file in own program under the directory of this file.
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
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

/*
Up to one value may be returned; it must be the same type as the return type.
If no values are returned, give the function a void return type. (e.g.: return 0; or return;)
If there are many functions with the same name, but different arguments, the called function is the one whose arguments match the invocation. C++ Overloads
void type is used when the function has no return value:
Normal function calls are pass by value. (Exactly like Java)
*/

int x; //global variable can be accessed anywhere
int square(int); //prototype that tells compiler you will implement later
int cube (int x) {
    return pow(x, 3);
}

//9 times out of 10 use pass by value
void default_test (int y = 3) { //formal parameters! Normally is pass by value (copy)
    //local variable x shadows global variable x
    printf("local variable y is now %d\n", x);
}

void global_test() {
    x++;
    printf("Global variable x is now %d\n", x);
}

//use if you want to be able to assign the value to null
//like *p = null;
void pass_by_pointer_reference(int *p) {
    *p = *p + 10;
}

//pass by reference legit = 1 copy/same variable
//use if you want to mutate original value in function
//also useful if you want to return more than one value! use pass by reference ya feel like
//result 1 and result 2;
void by_ref(int &arg) {arg += 2;}


int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    x = 5;
    global_test();
    printf("Sample function call of cube: %d\n", cube(3)); //basic function call

    //default arguments
    int y = 70;
    default_test(y); //prints out 70
    default_test(); //formal parameters assignment
    global_test();

    //java is always pass by value -> copying the bits = create two copies that point to same value
    //C++ is sometimes pass by value sometimes pass by reference
    default_test(4); // pass by value
    pass_by_pointer_reference(&x); //value of x changes.
    pass_by_pointer_reference(&y); //value of y changes
    deb(y);
    global_test();
    by_ref(x); printf("x is changed: %d\n", x);
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



