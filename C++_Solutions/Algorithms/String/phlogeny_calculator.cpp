#include <bits/stdc++.h>
using namespace std;

//O(n^3) phylogeny calculator
double g[50][50], q[50][50], r[50];
map<int, string> mp;
int n;
int iteration;

void solve() {
    cout << "ITERATION " << ++iteration << endl << endl;
    cout << "The R-values are: " << endl;
    memset(r, 0, sizeof(r));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            r[i] += g[i][j];
        }
        r[i] /= (n - 2);
        cout << mp[i] << ": " << r[i] << endl;
    } cout << endl;

    int minValue = INT_MAX, minOne = -1, minTwo = -1;
    cout << "Constructing Q-Matrix: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << "None ";
                continue;
            }
            q[i][j] = g[i][j] - r[i] - r[j];
            if (q[i][j] < minValue) {
                minValue = q[i][j];
                minOne = i;
                minTwo = j;
            }
            cout << q[i][j] << ' ';
        } cout << endl;
    } cout << endl;

    cout << "The two values we join are: " << minOne  << " and " << minTwo << endl << endl;
    double wi = (g[minOne][minTwo] + r[minOne] - r[minTwo]) / 2;
    double wj = g[minOne][minTwo] - wi;
    cout << "The edge weights are: " << mp[minOne] << ": " << wi << ", " << mp[minTwo] << ": " << wj << endl << endl;

    map<int, string> newMap;
    newMap[1] = mp[minOne] + mp[minTwo];
    mp.erase(mp.find(minOne)), mp.erase(mp.find(minTwo));
    auto it = mp.begin();
    map<int, int> oldToNew;
    for (int i = 2; i <= n - 1; i++) {
        newMap[i] = it -> second;
        oldToNew[it -> first] = i;
        it++;
    }

    cout << "The Joined Map is" << endl;
    for (int i = 1; i <= n - 1; i++) {
        cout << newMap[i] << endl;
    } cout << endl;

    cout << "New Matrix is: " << endl;
    double newMatrix[n + 1][n + 1] = {0.0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (i != minOne && j != minTwo) {
                int ii = oldToNew[i], jj = oldToNew[j];
                newMatrix[ii][jj] = g[i][j];
            } else if (i == minOne && j != minTwo) {
                int jj = oldToNew[j];
                newMatrix[1][jj] = (g[minOne][j] + g[minTwo][j] - g[minOne][minTwo]) / 2;
            } else if (j == minTwo && i != minOne) {
                int ii = oldToNew[i];
                newMatrix[ii][1] = (g[minOne][j] + g[minTwo][j] - g[minOne][minTwo]) / 2;
            }
        }
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) g[i][j] = newMatrix[i][j];
    for (int i = 1; i <= n; i++) g[i][1] = g[1][i], g[i][i] = 0;
    mp.clear();
    for (pair<int, string> pp : newMap) {
        mp[pp.first] = pp.second;
    }
    for (int i = 1; i <= n - 1; i++) {
        cout << newMap[i] << ": ";
        for (int j = 1; j <= n - 1; j++) {
            cout << g[i][j] << ' ';
        } cout << endl;
    }
    cout << endl << endl << endl;
}

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) g[i][j] = 0, q[i][j] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[i] = s;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    while (n > 2) {
        solve();
        n--;
    }
}

