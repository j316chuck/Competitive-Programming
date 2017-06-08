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

bool P(int arr[], int n, int number, int max_size, int &total) {
    total = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    //cout << number << endl;
    for (int i = 0; i < n; i++) {
        pq.push(arr[i] + (i + 1) * number);
        //cout << arr[i] + (i + 1) * number << ' ';
    }
    //cout << endl;

    for (int i = 0; i < number; i++) {
        total += pq.top();
        pq.pop();
        if (total > max_size) {
            return false;
        }
    }
    return true;
}

int main() {

    //time_t start=clock();
    //Rd("417C.in");
    ios_base::sync_with_stdio(0);
    int n, S;
    scanf("%d %d", &n, &S);
    int arr[n+1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int lo = 0, hi = n + 1, mid, total = 0;
    while (lo < hi - 1) {
        mid = (lo + hi) / 2;
        if (P(arr, n, mid, S, total)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    P(arr, n, lo, S, total);
    printf("%d %d\n", lo, total);
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



