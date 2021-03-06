/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
const double Pi= acos(-1.0);
typedef long long LL;
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

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


int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0); //does not allow cin and scanf to be in same stream
    //cin.tie(0);  //prevents cin from automatically flushing, be careful in interactive programs
    double x;
    cin >> x;
    cout << x; //pretty standard
    //from iostream
    //A stream is an entity where a program can either insert or extract characters to/from
    //streams are a source/destination of characters, and that these characters are provided/accepted sequentially (i.e., one after another).
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    //<< = insertion operator
    //<< endl; = flushes but '\n' does not
    //>> extraction operator
    /*while (cin >> x) {
        cout << fixed << showpoint; //fixed //showpoint //setprecision(2)
        cout << setprecision(2);
        cout << x;
    }*/
    //cin >> x >> ":" >> x;
    //cout << x << endl;
    return 0;
}


