
/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <bits/stdc++.h>
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



int main() {

    //time_t start=clock();
    ios_base::sync_with_stdio(0);
    int a[100], p[100];
    int n;
    scanf("%d", &n);
    // receive input
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), scanf("%d", p + i); //, to separate new syntax

    sort(p, p+n, [=](int i, int j) { return a[i] < a[j]; }); //sort by a[i] the p[i];
    for (int i = 0; i < n; i++) {
        printf("%d", p[i]);
    }
    printf('\n');
    auto lambda = [] {cout << "Code within lambda" << endl;};
    auto lambda = [](void) -> void {cout << "Code within lambda" << endl;}; //parameter and return type = void

    lambda();
    /*
    //assume Foo class;
    sort(v.begin(), v.end(), [](const Foo& a, const Foo &b) { return a.i > b.i;});
    sort(v.begin(), v.end(),
            [](const Foo& a, const Foo& b)
            {
                return a.i > b.i;
            });
    */
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}


