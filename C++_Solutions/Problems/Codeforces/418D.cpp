/*
ID: j316chuck
PROG: 418D
LANG: C++
*/

#include <bits/stdc++.h>
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define deb(x) cerr << "DEBUG: "<< #x << " = " << x << endl;
#define endl '\n'

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

struct Circle {
    double x, y, r;
};

vector<int> graph[1005];
bool add[1005];

bool CircleContains(const Circle &c1, const Circle &c2) {
    return sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y)) <= (c1.r - c2.r);
}

void dfs(int i, bool c) {
    add[i] = c;
    for (int child : graph[i]) {
        dfs(child, !c);
    }
}

int main() {

    //time_t start=clock();
    //good debug by just looking at it.
    //Rd("418D.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<Circle> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y >> v[i].r;
    }

    //build graph with parent
    int par[n];
    for (int i = 0; i < n; i++) {
        par[i] = -1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (CircleContains(v[j], v[i]) && (par[i] == -1 || v[par[i]].r > v[j].r)) {
                par[i] = j;
            }
        }
        if (par[i] != -1) graph[par[i]].push_back(i);
    }
    //deb_array(par, n);
    //dfs on graph to determine true/false -- greedy solution
    for (int i = 0; i < n; i++) {
        if (par[i] == -1)
            dfs(i, false);
    }

    //calculate area
    double area = 0;
    for (int i = 0; i < n; i++) {
        if (par[i] == -1 || add[i]) {
            area += (v[i].r * v[i].r);
        } else {
            area -= (v[i].r * v[i].r);
        }
    }
    printf("%.9f\n", area * PI);
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



