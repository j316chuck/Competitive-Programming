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



int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    //gets is dangerous does not take length parameter
    //should use fgets with if
    char str[100];
    fgets(str, 10, stdin); //maximum = 10;
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len-1] = '\0'; //does not remove '\n'
    cout << str << endl;
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    char str2[] = "Hello World!";
    puts(str2); //prints and adds newline
    int c;
    do {
        c = getchar();
        putchar(c);
    } while (c != '.');
    //reads in the entire string with white spaces;
    string str3;
    getline(cin, str3);
    cout << str3;
    while (getline(cin, str3)) {
        if (cin.eof()) {
                break;
        }
        cout << str3 << '\n';
    }
    return 0;
}



