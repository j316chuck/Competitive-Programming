/*
ID: j316chuck
PROG: butter
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
    int v, w;
    bool operator < (const pp &a) const {
        return w < a.w;
    }
};

const int maxn = 805;
int n, p, c, level[maxn], mycow[maxn];
vector<pp> graph[maxn];
int dist[maxn];
bool visited[maxn];

int dijstrka(int st) {
    int cost = 0;
    memset(dist, 0x3f, sizeof(dist));
    memset(visited, false, sizeof(visited));
    dist[st] = 0;
    priority_queue<pp> pq;
    pq.push({st, 0});
    while (!pq.empty()) {
        int u = pq.top().v;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cost += (level[u] * dist[u]);
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].v;
            int w = graph[u][i].w;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
    /*for (int i = 0; i < n; i++) {
        cost += dist[mycow[i]];
    }*/
    return cost;
}

int main() {
    Rd("input.in");
   //Rd("butter.in");
    //Wt("butter.out");
    ios_base::sync_with_stdio(0);
    int cow;
    cin >> n >> p >> c;
    for (int i = 0; i < n; i++) {
        cin >> cow;
        level[cow]++;
        mycow[i] = cow;
    }
    int u, v, w;
    for (int i = 0; i < c; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int ans = INF;
    for (int i = 1; i <= p; i++) {
        ans = min(ans, dijstrka(i));
    }
    cout << ans << endl;
    return 0;
}




