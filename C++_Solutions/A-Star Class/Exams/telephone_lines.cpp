#include <bits/stdc++.h>
using namespace std;

struct pp {
    int v, w;
    bool operator < (const pp &a) const {
        return w < a.w;
    }
};

const int maxn = 1005;
const int INF = 1e7+1;
vector<pp> graph[maxn];
vector<pp> graph2[maxn];
int n, p, k;
int dist[maxn];
bool wrong = false;

void construct_graph(int len) {
    for (int i = 1; i <= n; i++) {
        graph2[i].clear();
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j].w > len) {
                graph2[i].push_back({graph[i][j].v, 1});
            } else {
                graph2[i].push_back({graph[i][j].v, 0});
            }
        }
    }
}

bool bfs() {
    /*queue<int> q;
    q.push(1);
    dist[1] = 0;
    int v, w, u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int i = 0; i < graph2[u].size(); i++) {
            w = graph2[u][i].w;
            v = graph2[u][i].v;
            if (dist[v] == -1 || dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    } */
    memset(dist, -1, sizeof(dist));
    priority_queue<pp> pq;
    pq.push({1, 0});
    dist[1] = 0;
    int v, w, u;
    while (!pq.empty()) {
        u = pq.top().v;
        pq.pop();
        for (int i = 0; i < graph2[u].size(); i++) {
            //cout << "(" << graph2[u][i].v <<","<< graph2[u][i].w << ") ";
            v = graph2[u][i].v;
            w = graph2[u][i].w;
            if (dist[v] == -1 || dist[u] + w  < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        } //cout << endl;
    }
    /*for (int i = 0; i <= n; i++){
        cout << dist[i] << ' ';
    } cout << endl;
    cout << (dist[n] <= k) << endl;*/
    if (dist[n] == -1) {
        wrong = true;
        return 0;
    }
    return dist[n] <= k;
}

bool check(int len) {
    construct_graph(len);
    return bfs();
}

int main() {
    freopen("telephone_lines.in", "r", stdin);
    scanf("%d %d %d", &n, &p, &k);
    int u, v, w;
    for (int i = 0; i < p; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    //construct_graph(4);
    /*for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph2[i].size(); j++) {
            cout << "(" << graph2[i][j].v <<","<< graph2[i][j].w << ") ";
        } cout << endl;
    }*/
    //bfs();
    //cout << endl << endl << endl;
    /*for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    } cout << endl;
    cout << endl;
    cout << check(4) << ' '  << check(5) << check(7) << endl;*/
    int lo = -1, hi = 1e6 + 5, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (check(mid)) { //check means you can walk to point n in less than equal to k steps.
            hi = mid;
        } else {
            lo = mid;
        }
        if (wrong) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", hi);
}
