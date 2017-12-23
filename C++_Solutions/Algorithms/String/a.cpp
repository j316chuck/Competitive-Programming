#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.in", "r", stdin);

    string str, file_name; int id;
    map<string, vector<int> > mp;
    while (getline(cin, str)) {
        cout << str.substr(0, str.find(",")) << ' ' << str.substr(str.find(",") + 1) << endl;

    }
    /*for (pair<string, vector<int> > pp : mp) {
        cout << pp.first << endl;
        bool mark[10000 + 5] = {false};
        int maximum = -1;
        for (int i = 0; i < pp.second.size(); i++) {
            mark[pp.second[i]] = true;
            maximum = max(pp.second[i], maximum);
        }
        for (int i= 1; i <= maximum; i++) {
            if (!mark[i]) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }*/
}
