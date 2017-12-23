#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    double g[n + 1][n + 1], q[n + 1][n + 1];
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) g[i][j] = 0, q[i][j] = INT_MAX;
    map<int, string> mp;
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

    cout << "The R-values are: " << endl;
    double r[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            r[i] += g[i][j];
        }
        r[i] /= (n - 2);
        cout << mp[i] << ": " << r[i] << endl;
    }

    int minValue = INT_MAX, minOne = -1, minTwo = -1;
    cout << "Constructing Q-Matrix: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << "- ";
                continue;
            }
            q[i][j] = g[i][j] - r[i] - r[j];
            if (q[i][j] < minValue) {
                minValue = q[i][j];
                minOne = i;
                minTwo = j;
            }
            cout << q[i][j] << ' ';
        } cout << endl << endl;
    }

    cout << "The two values we join are: " << minOne  << " and " << minTwo << endl << endl;
    //mp[minOne * 10 + minTwo] = mp[minOne] + mp[minTwo];
    double wi = (g[minOne][minTwo] + r[minOne] - r[minTwo]) / 2;
    double wj = g[minOne][minTwo] - wi;
    cout << "The edge weights are: " << mp[minOne] << ": " << wi << "  " << mp[minTwo] << ": " << wj << endl << endl;

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
                //cout << minOne << ' ' << jj << ' ' << g[minOne][j] << ' ' << g[minTwo][j] << ' ' << g[minOne][minTwo] << ' ' << newMatrix[1][jj] << endl;
            } else if (j == minTwo && i != minOne) {
                int ii = oldToNew[i];
                newMatrix[ii][1] = (g[minOne][j] + g[minTwo][j] - g[minOne][minTwo]) / 2;
            }
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) g[i][j] = newMatrix[i][j];
    for (int i = 1; i <= n; i++) g[i][i] = 0;
    for (int i = 1; i <= n - 1; i++) {
        cout << newMap[i] << ": ";
        for (int j = 1; j <= n - 1; j++) {
            cout << g[i][j] << ' ';
        } cout << endl;
    }
}
