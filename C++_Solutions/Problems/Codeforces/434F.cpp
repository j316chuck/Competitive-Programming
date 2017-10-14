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

const int INF = 1e9+1;
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

struct pp {
    int a, b, c;
};

const int maxn = 2e5 + 5;

vector<pp> ans;
vector<int> graph[maxn];
int color[maxn], rem[maxn]; //initially 0 = white
int n, m;


int dfs(int u, int par) {
    color[u] = 1; //set to 1 = grey
    vector<int> child;
    for (int v : graph[u]) {
        if (color[v] == 1) {
            continue;
        } else if (color[v] == 2) {
            child.push_back(v);
        } else {
            int ret = dfs(v, u);
            if (ret == 1) {
                ans.push_back({u, v, rem[v]});
            } else {
                child.push_back(v);
            }
        }
        if (child.size() >= 2) {
            int v1 = child.back(); child.pop_back();
            int v2 = child.back(); child.pop_back();
            ans.push_back({v1, u, v2});
        }
    }
    color[u] = 2; //finished state: black = 2
    if (child.size()) {
        rem[u] = child[0];
        return 1;
    } else {
        return 0;
    }
}

int main() {
    //Rd("input.in");
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i] != 2) {
            dfs(i, -1);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].a << ' ' << ans[i].b << ' ' << ans[i].c << endl;
    }
    return 0;
}




