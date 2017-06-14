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
    int n, x, num;
    map<int, int> parents;
    parents[0] = -1;
    set<int> modulos;
    modulos.insert(0);
    set<int> intersection;
    set<int>::iterator it;
    vector<int> result;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        intersection.clear();
        for (it = modulos.begin(); it != modulos.end(); it++) {
            if ((*it + x) % n == 0) {
                parents[n] = x;
            }
            num = (*it + x) % n;
            intersection.insert(num);
            parents[num] = x;
        }
        //deb(intersection); deb(modulos);
        for (it = intersection.begin(); it != intersection.end(); it++) modulos.insert(*it);
        if (parents[n] != 0) {
            int tmp = n;
            while (tmp != 0) {
                result.push_back(parents[tmp]);
                tmp = (tmp - parents[tmp] + n) % n;
            }
            break;
        }
    }
    printf("%d\n", result.size());
    for (int i = 0; i < result.size(); i++) {
        printf("%d\n", result[i]);
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}




