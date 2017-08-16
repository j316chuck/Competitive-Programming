#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const long long mod = 1e9+7;
const long long power = 31;
vector<long long> lhsh;
vector<long long> rhsh;
vector<long long> pows;
string s;

long long hext(long long hsh, int ch) {
    return (1LL * hsh * power + ch) % mod;
}

long long calc_pows(int n) {
    long long p = 1;
    for (int i = 0; i <= n; i++) {
        pows.push_back(p);
        p *= power;
        p = p % mod;
    }
}

void calc_hashes(string &s) {
    lhsh.push_back(0);
    for (int i = 0; i < s.length(); i++) {
        lhsh.push_back(hext(lhsh.back(), s[i] - 'a'));
    }
    rhsh.push_back(0);
    for (int i = s.length() - 1; i >= 0; i--) {
        rhsh.push_back(hext(rhsh.back(), s[i] - 'a'));
    }
}

long long substring_hash(int l, int r) {
    if (l < 0 || r > s.length()) cout << "Index Out of Bounds" << endl;
    return (((lhsh[r+1] - lhsh[l] * pows[r - l + 1]) % mod) + mod) % mod;
}

long long rsubstring_hash(int l, int r) {
    if (l < 0 || r > s.length()) cout << "Index Out of Bounds" << endl;
    return (((rhsh[r+1] - rhsh[l] * pows[r - l + 1]) % mod) + mod) % mod;
}

pair<int, int> calc_mid(int l, int r) {
    if ((l + r) % 2 == 1) {
        return {(l + r) / 2, (l + r) / 2 + 1};
    } else {
        return {(l + r) / 2 - 1, (l + r) / 2 + 1};
    }
}

set < pair<int, int> > pals;
int main() {
    freopen("427D.in", "r", stdin);
    cin >> s;
    calc_pows(s.length());
    calc_hashes(s);
    for (int i = 0; i < s.length(); i++) {
        pals.insert({i, i});
    }
    //solves palindrome substring problem...
    for (int len = 1; len < s.length(); len++) {
        for (int j = 0; j + len < s.length(); j++) {
            if (substring_hash(j, j + len) == rsubstring_hash(s.length() - 1 - j - len, s.length() - 1 - j)) {
                pals.insert({j, j + len});
            }
        }
    }
    //too much memory used because of tmp copying...
    for (int i = 1; i <= s.length(); i++) {
        cout << pals.size() << ' ';
        set < pair<int, int> > tmp;
        for (auto it = pals.begin(); it != pals.end(); it++) {
            pair<int, int> m = calc_mid(it -> first, it -> second);
            if (pals.find({it -> first, m.first}) != pals.end() && pals.find({m.second, it -> second}) != pals.end()) {
                tmp.insert({it -> first, it -> second});
            }
        }
        pals = tmp;
    }
    cout << endl;
}

