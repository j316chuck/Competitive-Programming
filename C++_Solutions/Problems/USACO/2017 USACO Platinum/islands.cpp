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

char graph[55][55];
int grid[55][55];
bool visited[55][55];
int graph2[16][16];
int dp[1 << 16][16];
int n, r, c;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
vector< pair<int, int> > islands;

bool valid(int i, int j) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

void dfs(int i, int j, int counter) {
    if (!valid(i, j) || graph[i][j] == '.' || graph[i][j] == 'S' || visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    grid[i][j] = counter;
    for (int k = 0; k < 4; k++) {
        dfs(i + dr[k], j + dc[k], counter);
    }
}

void input() {
    cin >> r >> c;
    memset(grid, -1, sizeof(grid));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
        }
    }
}

void construct_islands() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!visited[i][j] && graph[i][j] == 'X') {
                dfs(i, j, n); n++;
                islands.push_back({i, j});
            }
        }
    }
    /*for (int i = 0; i < r; i++) {
        deb_array(grid[i], c);
    }*/
}

struct pp {
    int i, j, w;
};

void bfs(int si, int sj, int id) {
    memset(visited, false, sizeof(visited));
    queue<pp> q;
    q.push({si, sj, 0});
    while (!q.empty()) {
        int i = q.front().i, j = q.front().j, w = q.front().w;
        q.pop();
        if (!valid(i, j) || visited[i][j] || graph[i][j] == '.') continue;
        visited[i][j] = true;
        if (graph[i][j] == 'S') {
            w++;
        } else if (graph[i][j] == 'X') {
            int id2 = grid[i][j];
            graph2[id][id2] = graph2[id2][id] = min(graph2[id2][id], w);
        } else {
            cout << "ERROR" << endl;
        }
        for (int k = 0; k < 4; k++) {
            q.push({i + dr[k], j + dc[k], w});
        }
    }
}

void construct_graph2() {
    n = islands.size();
    memset(graph2, 0x3f, sizeof(graph2));
    for (int i = 0; i < n; i++) {
        bfs(islands[i].first, islands[i].second, i);
    }
    for (int i = 0; i < n; i++) {
        graph2[i][i] = INF;
        //deb_array(graph2[i], n);
    }
}

/*const int inf = 1e8 + 1;
void hamiltonian_path() {
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
    for (int i = 1; i < (1 << n) - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] > inf) continue;
            for (int k = 0; k < n; k++) {
                if (graph2[j][k] > inf || (1 << k) & i || j == k) continue;
                dp[(1 << k) | i][k] = min(dp[(1 << k) | i][k], graph2[j][k] + dp[i][j]);
            }
        }
    }
    int ret = INF;
    for (int i = 0; i < n; i++) {
        ret = min(ret, dp[(1 << n) - 1][i]);
    }
    cout << ((ret < inf) ? ret : -1)  << endl;
}*/

void hamiltonian_path() {
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) if (i & 1 << j) {
            for (int k = 0; k < n; k++) {
                if (j != k && graph2[k][j] < INF && (i & 1 << k) && dp[i ^ (1 << j)][k] < INF) {
                    dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + graph2[k][j]);
                }
            }
        }
    }
    int ret = INF;
    for (int i = 0; i < n; i++) {
        ret = min(ret, dp[(1 << n) - 1][i]);
    }
    cout << ret << endl;
}

int main() {
    //Rd("input.in");
    Rd("island.in");
    //Wt("island.out");
    ios_base::sync_with_stdio(0);
    input();
    construct_islands();
    construct_graph2();
    hamiltonian_path();
    return 0;
}




