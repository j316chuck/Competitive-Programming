#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int maxn = 755;
int nr, nc, nk;
int grid[maxn][maxn];
int dp[maxn][maxn];
int psum[maxn];
vector<int> bit[maxn * maxn];
vector<int> columns[maxn * maxn];

void update(int id, int x, int val) {
    while (x < bit[id].size()) {
        bit[id][x] += val;
        if (bit[id][x] >= mod) bit[id][x] -= mod;
        x += x & - x;
    }
}

int query(int id, int x) {
    int total = 0;
    while (x > 0) {
        total += bit[id][x];
        if (total >= mod) total -= mod;
        x -= x & -x;
    }
    return total;
}

/*struct BIT {
    vector<int> indices;
    vector<int> tree;

    void initialize(vector<int> &index) {
        indices.push_back(-1);
        copy(index.begin(), index.end(), back_inserter(indices));
        tree.resize(indices.size());
        fill(tree.begin(), tree.end(), 0);
    }

    void update(int index, int val) {
        index = lower_bound(indices.begin(), indices.end(), index) - indices.begin();
        while (index < tree.size()) {
            tree[index] += val;
            if (tree[index] >= mod) tree[index] -= mod;
            index += index & -index;
        }
    }

    int query(int index) {
        index = upper_bound(indices.begin(), indices.end(), index) - indices.begin() - 1;
        int total = 0;
        while (index > 0) {
            total += tree[index];
            if (total >= mod) total -= mod;
            index -= index & -index;
        }
        return total;
    }
};*/


int main() {
    freopen("hopscotch_seg.in", "r", stdin);
    //freopen("hopscotch_seg.out", "w", stdout);
    //freopen("hopscotch.in", "r", stdin);
    //freopen("hopscotch.out", "w", stdout);
    scanf("%d %d %d", &nr, &nc, &nk);
    for (int i = 1; i <= nr; i++) {
        for (int j = 1; j <= nc; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    for (int j = 1; j <= nc; j++) {
        for (int i = 1; i <= nr; i++) {
            columns[grid[i][j]].push_back(j);
        }
    }
    for (int j = 0; j <= nk; j++) {
        sort(columns[j].begin(), columns[j].end());
        columns[j].resize(unique(columns[j].begin(), columns[j].end()) - columns[j].begin());
        bit[j].resize(columns[j].size() + 1);
    }

    dp[1][1] = 1; update(grid[1][1], 1, 1);
    for (int j = 1; j <= nc; j++) psum[j] = 1;

    for (int i = 2; i <= nr; i++) {
        for (int j = 1; j <= nc; j++) {
            dp[i][j] = psum[j-1] - query(grid[i][j], upper_bound(columns[j].begin(), columns[j].end(), j) - columns[j].begin());
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
        psum[0] = 0;
        for (int j = 1; j <= nc; j++) {
            psum[j] = psum[j-1] + dp[i][j];
            psum[j] = (psum[j] + mod) % mod;
            update(grid[i][j], lower_bound(columns[j].begin(), columns[j].end(), j) - columns[j].begin() + 1, dp[i][j]);
        }
    }
    printf("%d\n", dp[nr][nc]);
}

