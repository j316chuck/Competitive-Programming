/*
ID: j316chuck
PROG: 1148
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

int dx[5] = {0, 1, -1, -1, 1};
int dy[5] = {0, 1, 1, -1, -1};
int n;

void reverse_sign(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        vec[i] = -vec[i];
    }
}

int count_sign_changes(vector<int> &sign_changes) {
    int total = 0;
    for (int i = 0; i < sign_changes.size() - 1; i++) {
        if (sign_changes[i] + sign_changes[i + 1] == 0) {
            total++;
        }
    }
    return total;
}

void one_dimension_solve(vector<int> &x, vector<int> &sign_changes, vector<int> &result) {
    int total_changes = count_sign_changes(sign_changes);
    int start = x.size() - total_changes - 1;
    if ((x[start] > 0 && sign_changes[0] < 0) || (x[start] < 0 && sign_changes[0] > 0)) {
        reverse_sign(x);
    }

    result.push_back(x[start]);
    int lower = start, upper = start;
    for (int i = 1; i < sign_changes.size(); i++) {
        if (sign_changes[i] != sign_changes[i-1]) {
            upper++;
            result.push_back(x[upper]);
        } else {
            lower--;
            result.push_back(x[lower]);
        }
    }
}

int main() {

    //time_t start=clock();
    //Rd("1148.in"); //make sure to put it in the correct folder
    scanf("%d", &n);
    vector<int> tmp(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &tmp[i]);
    }
    sort(tmp.begin(), tmp.end());
    vector<int> x(tmp.begin(), tmp.begin() + n);
    vector<int> y(tmp.begin() + n, tmp.end());
    for (int i = 0; i < x.size(); i+= 2) {
        x[i] = -x[i];
        y[i] = -y[i];
    }
    int random;
    vector<int> sign_x(n), sign_y(n), y1, x1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &random);
        sign_x[i] = dx[random];
        sign_y[i] = dy[random];
    }
    //deb(sign_x); deb(sign_y);
    one_dimension_solve(x, sign_x, x1);
    one_dimension_solve(y, sign_y, y1);
    for (int i = 0; i < n; i++) {
        if (x1[i] >= 0) {
            printf("+%d ", x1[i]);
        } else {
            printf("%d ", x1[i]);
        }
        if (y1[i] >= 0) {
            printf("+%d\n", y1[i]);
        } else {
            printf("%d\n", y1[i]);
        }
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




