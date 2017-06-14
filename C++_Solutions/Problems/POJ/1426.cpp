/*
ID: j316chuck
PROG: 1426
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
    //Rd("1426.in"); //make sure to put it in the correct folder
    int x, top, t1, t2;
    map<int, string> results;
    map<int, string> modulos;
    queue<int> q;
    while (scanf("%d", &x) && x != 0) {
        if (results[x] != "") {
            printf("%s\n", results[x].c_str());
            continue;
        }
        modulos.clear();
        modulos[1] = "1";
        q = queue<int>();
        q.push(1);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            if (top == 0) {
                break;
            }
            t1 = (top * 10) % x;
            t2 = (top * 10 + 1) % x;
            if (modulos[t1] == "") {
                modulos[t1] = modulos[top] + "0";
                q.push(t1);
            }
            if (modulos[t2] == "") {
                modulos[t2] = modulos[top] + "1";
                q.push(t2);
            }
        }
        results[x] = modulos[0];
        printf("%s\n", results[x].c_str());
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




