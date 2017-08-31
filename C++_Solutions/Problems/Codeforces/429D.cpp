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
    int v, ind;
    bool used;
};
const int maxn = 3e5 + 5;
int n, m, ans;
int d[maxn];
vector<pp> graph[maxn];
bool used[maxn], visited[maxn];

int dfs(int u) {
    int counter = 0, v;
    visited[u] = true;
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i].v;
        if (!visited[v]) {
            int ret = dfs(v);
            counter += ret;
            counter %= 2;
            if (ret) graph[u][i].used = true;
        }
    }
    if (d[u] == -1) {
        return 0;
    }
    counter += d[u];
    counter %= 2;
    return counter;
}

int main() {
    //Rd("input.in");
    memset(used, false, sizeof(used));
    memset(visited, false, sizeof(visited));
    scanf("%d %d", &n, &m);
    int start = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        if (d[i] == -1) start = i;
    }
    int u, v;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back({v, i, false});
        graph[v].push_back({u, i, false});
    }
    if (dfs(start) != 0) {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j].used && !used[graph[i][j].ind]) {
                used[graph[i][j].ind] = true;
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= m; i++) {
        if (used[i]) {
            printf("%d\n", i);
        }
    }
    return 0;
}



