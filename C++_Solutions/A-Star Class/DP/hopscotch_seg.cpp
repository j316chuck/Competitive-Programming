#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int maxn = 755;
int nr, nc, nk;
int grid[maxn][maxn];

struct BIT {
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
};

BIT bit[maxn * maxn];
vector<int> columns[maxn * maxn];

int main() {
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    scanf("%d %d %d", &nr, &nc, &nk);
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    BIT total; vector<int> c;
    for (int j = 0; j < nc; j++) {
        for (int i = 0; i < nr; i++) {
            if (!columns[grid[i][j]].empty() && columns[grid[i][j]].back() == j) {
                continue;
            }
            columns[grid[i][j]].push_back(j);
        }
        c.push_back(j);
    }
    total.initialize(c);

    for (int j = 0; j <= nk; j++) {
        bit[j].initialize(columns[j]);
    }
    
    total.update(0, 1);
    bit[grid[0][0]].update(0, 1);
    for (int i = 1; i < nr - 1; i++) {
        for (int j = nc - 2; j > 0; j--) {
            int val = total.query(j-1) - bit[grid[i][j]].query(j-1);
            val = (val + mod) % mod;
            total.update(j, val);
            bit[grid[i][j]].update(j, val);
        }
    }
    int ret = total.query(nc - 2) - bit[grid[nr - 1][nc - 1]].query(nc - 2);
    ret = (ret + mod) % mod;
    printf("%d\n", ret);
}
