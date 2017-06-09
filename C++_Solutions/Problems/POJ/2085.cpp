/*
ID: j316chuck
PROG: 2085
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
#include <assert.h>
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

/*bool swapped[50010];
void recurse(int first, int last, int total, bool* swapped) {
    //assert(2 * total <= (last - first) * (last - first - 1));
    if (total == 0) return;
    if (total == 1) {
        swapped[last - 1] = true;
        return;
    }
    int lo = 0, hi = last + 1, mid; // hi = first - last + 1
    while (lo < hi - 1) { // hi always works, lo never works;
        mid = (hi + lo) >> 1;
        if (mid * (mid - 1) / 2 < total) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << first << ' ' << last << ' ' << total << ' ' << hi << endl;
    swapped[last - hi + 1] = true;
    recurse(total - hi + 2, last, total - hi + 1, swapped);
} */

int main() {

    //time_t start=clock();
    Rd("2085.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int num, total;
    while (~scanf("%d %d", &num, &total) && !(num == -1 && total == -1)) {
        //for (int i = 0; i <= x; i++) swapped[i] = false;
        /*recurse(1, y, x, swapped);
        int right_counter = x;
        int left_counter = 1;
        for (int i = 1; i <= x; i++) {
            if (swapped[i]) {
                printf("%d ", right_counter--);
            } else {
                printf("%d ", left_counter++);
            }
        }
        printf("\n");*/
        int i, sum = 0;
        for (i = num; i >= 1; i--) {
            sum += (num - i);
            if (sum >= total) {
                break;
            }
        }
        //cout << i << ' ' << num << ' ' << total << " " << sum << endl;
        for (int k = 1; k < i; k++) {
            printf("%d ", k);
        }
        int j = i + total - ((num - i) * (num - i - 1) / 2);
        printf("%d ", j);
        for (int k = num; k >= i; k--) {
            if (k != j) {
                printf("%d ", k);
            }
        }
        printf("\n");
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




