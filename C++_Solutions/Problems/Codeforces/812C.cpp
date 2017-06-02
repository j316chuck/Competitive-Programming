/*
ID: j316chuck
PROG: 812C
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


long long P(long long length, int arr[]) {
    long long sum = 0;
    for (int i = 1; i <= length; i++) {
        sum += arr[i];
    }
    sum += (length * length * (length + 1)) /2 ;
    return sum;
}
int main() {

    //time_t start=clock();
    Rd("input.txt");
    ios_base::sync_with_stdio(0);
    int n, max_cost;
    scanf("%d %d", &n, &max_cost);
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + n  + 1);
    //for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    int lo = 0, hi = n + 1; //lo has to be okay hi does not have to be okay
    while (lo < hi - 1) {
        int mid = (lo + hi) / 2;
        //deb(mid); deb(lo); deb(hi); deb(P(mid, arr));
        if (P(mid, arr) <= max_cost) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    printf("%d %I64d\n", lo, P(lo, arr));

    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



