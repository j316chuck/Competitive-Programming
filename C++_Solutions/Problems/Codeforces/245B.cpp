#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("245B.in", "r", stdin);
    string pat, good, match;
    getline(cin, good);
    getline (cin, pat);
    bool valid[256];
    memset(valid, false, sizeof(valid));
    for (int i = 0; i < good.size(); i++) {
        valid[good[i]] = true;
    }
    string s;
    int n;
    getline(cin, s);
    n = atoi(s.c_str());
    for (int i = 0; i < n; i++) {
        getline(cin, match);
        bool v = true;
        if (match.size() > pat.size()) {
            v = false;
            goto second;
        }
        for (int k = 0; k < pat.size(); k++) {
            if (pat[k] == '*') continue;
            if (pat[k] == '?') {
                if (k >= pat.size() || valid[match[k]] == false) {
                    v = false;
                    break;
                }
            } else {
                if (k >= pat.size() || pat[k] != match[k]) {
                    v = false;
                    break;
                }
            }
        }
        second:
        v ? cout << "YES\n" : cout << "NO\n";
    }
}
