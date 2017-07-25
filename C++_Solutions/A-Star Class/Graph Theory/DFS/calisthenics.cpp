#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;
int n, s;
vector<int> graph[maxn];
int cnt[maxn];
int rem[maxn];

void dfs(int u, int par, int maxk) {
    int v; vector<int> st;
    for (int i = 0; i < graph[u].size(); i++) {
        v = graph[u][i];
        if (v == par) continue;
        dfs(v, u, maxk);
        cnt[u] += cnt[v];
        if (rem[v] == maxk) {
            cnt[u]++;
            st.push_back(0);
        } else {
            st.push_back(rem[v] + 1);
        }
    }
    if (st.size() == 0) return;
    sort(st.begin(), st.end());
    reverse(st.begin(), st.end());
    int k = 0;
    for (; k < st.size() - 1; k++) {
        if (st[k] + st[k+1] <= maxk) {
            break;
        } else {
            cnt[u]++;
        }
    }
    rem[u] = st[k];
}

bool valid(int maxk) {
    memset(cnt, 0, sizeof(cnt));
    memset(rem, 0, sizeof(rem));
    //cout << maxk << endl;
    dfs(0, -1, maxk);
    return cnt[0] <= s;
}

int main() {
    freopen("calisthenics.in", "r", stdin);
    scanf("%d %d", &n, &s);
    int u, v;
    for (int i = 0; i < n - 1 ; i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        //cout << u << ' ' << v << endl;
    }

    if (s >= n-1) {
        printf("0\n");
        return 0;
    }
    int lo = 0, hi = n-1, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        //cout << mid << ' ' << endl;
        if (valid(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    printf("%d\n", hi);
}
