#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("425B.in", "r", stdin);
    string pat, pat2, good, match;
    getline(cin, good);
    getline (cin, pat);
    for (int i = 0; i < pat.size(); i++) {
        if (pat[i] != '*') {
            pat2 += pat[i];
        }
    }
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
        if (match.size() == pat.size()) {
            for (int k = 0; k < pat.size(); k++) {
                if (pat[k] == '*') continue;
                if (pat[k] == '?' && !valid[match[k]]) {
                    v = false;
                    break;
                } else if (pat[k] != '?' && pat[k] != match[k]) {
                    v = false;
                    break;
                }
            }
        } else if (match.size() == pat2.size()) {
            for (int k = 0; k < pat2.size(); k++) {
                if (pat2[k] == '?' && !valid[match[k]]) {
                    v = false;
                    break;
                } else if (pat2[k] != '?' && pat2[k] != match[k]) {
                    v = false;
                    break;
                }
            }
        } else {
            v = false;
        }
        v ? cout << "YES\n" : cout << "NO\n";
    }
}
