#include <bits/stdc++.h>
using namespace std;

struct pp {
    double x, y, index;
    bool operator < (const pp &a) const {
        return x < a.x;
    }
};

const int maxn = 1e5+5;
vector<pp> v;
int neighbors[maxn];
int cnt = 0;
int parent[maxn];

double dist(pp &a, pp &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    freopen("4.in", "r", stdin);
    int n, double max_value;
    scanf("%d %lf", &n, &max_value);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v.push_back({x, y, i});
    }
    sort(v.begin(), v.end());
    set<pp> st;
    st.insert(v[0]);
    neighbors[cnt]++;
    parent[0] = cnt;
    for (int i = 1; i < n; i++) {
        while (st.size() && st.begin() -> x + c < v[i].x) {
            st.erase(st.begin());
        }
        int p = cnt+1;
        for (auto it = st.begin(); it != st.end(); it++) {
            if (dist(*it, v[i]) <= c) {
                p = it -> index;
                break;
            }
        }
        if (p == cnt+1) {
            cnt++;
            parent[i] = cnt;
            neighbor[cnt] = 1;
        } else {
            parent[i] = parent[p];
            neighbor[]
        }
        st.insert(v[i]);
    }
    for (int i = 0; i < n; i++) {}
    return 0;
}


