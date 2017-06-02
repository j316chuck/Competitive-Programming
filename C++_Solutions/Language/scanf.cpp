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
    int x;
    /*while (scanf("%d", &x)) {
        printf("%d", x);
    }*/
    x = 3;
    printf("message: %d %d\n", x, x);

    long long y;
    scanf("%I64d", &y); //remember to put pointer
    printf("%I64d\n", y);
    printf("%lld\n", y);

    double d;
    scanf("%lf", &d); //double is lf
    //cout << d << endl;
    printf("%.4f\n", d); //float is f

    char str1[20];
    scanf("%s", str1); //no &
    printf(str1);

    /*string s;
    //scanf("%s", &s); //doesn't work
    cout << s << endl; */

    //fscanf = file
    //sscanf :)
    //reading in from a storage sentence;
    char sentence []="Rudolph is 12 years old";
    char str[20];
    int i;
    sscanf(sentence, "%s %*s %d", str, &i); //*s = not scanned :D
    printf("%s -> %d\n", str, i); //c-string style has weirder stuff
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



