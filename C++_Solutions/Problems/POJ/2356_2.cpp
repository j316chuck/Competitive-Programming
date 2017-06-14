/*
ID: j316chuck
PROG:
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-9;
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

int main() {

    //time_t start=clock();
    //Rd("2356.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n, x;
    scanf("%d", &n);
    vector<int> sums(n, 0);
    vector<int> nums;
    nums.push_back(0);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        nums.push_back(x);
        sums[i] = (x + sums[i - 1]) % n;
    }
    map<int, int> indexes;
    int start, end;
    for (int i = 1; i <= n; i++) {
        if (sums[i] == 0) {
            start = 1; end = i;
            break;
        }
        if (indexes[sums[i]]) {
            end = i;
            start = indexes[sums[i]] + 1;
            break;
        }
        indexes[sums[i]] = i;
    }
    printf("%d\n", end - start + 1);
    for (int i = start; i <= end; i++) {
        printf("%d\n", nums[i]);
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}





