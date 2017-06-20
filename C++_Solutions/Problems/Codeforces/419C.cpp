/*
ID: j316chuck
PROG:
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

int graph[110][110];

int main() {

    //time_t start=clock();
    //Rd("419C.in"); //make sure to put it in the correct folder
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int r, c, mini = 100000;
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            cin >> graph[i][k];
            if (graph[i][k] < mini) {
                mini = graph[i][k];
                r = i;
                c = k;
            }
        }
    }
    //cout << mini << ' ' << r <<  ' ' << c << endl;
    vector<int> rows, cols;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            graph[i][j] -= mini;
        }
    }
    if (n <= m) {
        for (int i = 0; i < mini; ++i) {
            for (int j = 0; j < n; ++j) {
                rows.push_back(j);
            }
        }
    } else {
        for (int i = 0; i < mini; ++i) {
            for (int j = 0; j < m; ++j) {
                cols.push_back(j);
            }
        }
    }

    //cout << r << ' ' << c << endl;
    for (int i = 0; i < n; ++i) {
        int x = graph[i][c];
        for (int k = 0; k < x; ++k) {
            rows.push_back(i);
        }
        for (int k = 0; k < m; ++k) {
            graph[i][k] -= x;
            if (graph[i][k] < 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int k = 0; k < m; ++k) {
            cout << graph[i][k] <<' ';
        } cout << endl;
    }*/
    for (int i = 0; i < m; ++i) {
        for (int k = 0; k < n; ++k) {
            if (graph[k][i] != graph[0][i]) {
                cout << -1 << endl;
                return 0;
            }
        }
        for (int k = 0; k < graph[0][i]; k++) {
            cols.push_back(i);
        }
    }

    cout << rows.size() + cols.size() << endl;
    for (int i = 0; i < rows.size(); ++i) {
        cout << "row " << rows[i] + 1 << endl;
    }
    for (int i = 0; i < cols.size(); ++i) {
        cout << "col " << cols[i] + 1 << endl;
    }
    //cerr << "Program has run "<< (double) (clock()-start) / CLOCKS_PER_SEC << " s " << endl;
    return 0;
}



