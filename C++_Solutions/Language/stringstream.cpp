/*
ID: j316chuck
PROG: stringstream
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



int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    /*
    istringstream is for input,
    ostringstream for output.
    stringstream is input and output.
    You can use stringstream pretty much everywhere.
    https://i.stack.imgur.com/0fZlv.gif inheritance relationship
    */

    stringstream ss;
    ss << 100 << ' ' << 200; //reads data into memory block
    int foo, bar;
    ss >> foo >> bar;
    cout << foo << bar << endl;
    ss.str("Example string");
    string s = ss.str();
    //istringstream = precision setf, tie, eof, peek, clear, get, read
    //ostringstream = write, put, seekp, flush, good, bad, eof
    ostringstream os;
    os << s << '\n';
    s = os.str();
    cout << s << '\n';
    //stringstream = memory location
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



