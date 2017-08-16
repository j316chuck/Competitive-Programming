#include <bits/stdc++.h>
using namespace std;

bool valid[256];
bool ok(const string &pat,const string &match) {
    if (pat.size() != match.size()) {
        return false;
    }
    for (int i = 0; i < pat.size(); i++) {
        if (pat[i] != '?' && pat[i] != match[i]) {
            return false;
        } else if (pat[i] == '?' && !valid[match[i]]) {
            return false;
        }
    }
    return true;
}

bool ok(const string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (valid[s[i]]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("425B.in", "r", stdin);
    string pat, pat2, good, match;
    getline(cin, good);
    getline (cin, pat);
    int m = -1;
    for (int i = 0; i < pat.size(); i++) {
        if (pat[i] == '*') {
            m = i;
            break;
        }
    }
    memset(valid, false, sizeof(valid));
    for (int i = 0; i < good.size(); i++) {
        valid[good[i]] = true;
    }
    string s, s1, s2;
    int n;
    getline(cin, s);
    n = atoi(s.c_str());
    for (int i = 0; i < n; i++) {
        getline(cin, match);
        bool v = true;
        if (m == -1) {
            v = ok(pat, match);
        } else {
            if (pat.size() - 1 > match.size()) {
                v = false;
            } else {
                //string m1 = match.substr(0, m);
                //string m2 = s2.size() == 0 ? "" : match.substr(match.size() - s2.size());
                //string m3 = match.substr(m, match.size() - pat.size() + 1);
                v &= ok(pat.substr(0, m), match.substr(0, m));
                if (m + 1 < pat.size()) {
                    v &= ok(pat.substr(m + 1), match.substr(match.size() - pat.size() + m +1));
                }
                v &= ok(match.substr(m, match.size() - pat.size() + 1));
            }
        }
        v ? cout << "YES\n" : cout << "NO\n";
    }
}
