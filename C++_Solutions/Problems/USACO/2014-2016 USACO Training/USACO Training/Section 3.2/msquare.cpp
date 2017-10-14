/*ID: j316chuck
PROG: msquare
LANG: C++
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define pii pair<int, int>

using namespace std;

struct pp {
    int t[4];
    int b[4];
    int moves;
    pp (const int *top, const int *bot) {
        memcpy(t, top, sizeof(t));
        memcpy(b, bot, sizeof(b));
    }
    pp movea() {
        return pp(b, t);
    }
    pp moveb() {
        int a1[4] = {t[3], t[0], t[1], t[2]};
        int a2[4] = {b[1], b[2], b[3], b[0]};
        return pp(a1, a2);
    }
    pp movec() {
        int a1[4] = {t[0], b[2], t[1], t[3]};
        int a2[4] = {b[0], t[2], b[1], b[3]};
        return pp(a1, a2);
    }
    int hsh() {
        int h = 0;
        int pw = 1;
        for (int i = 0; i < 4; i++) {
            h += pw * t[i];
            pw *= 10;
        }
        for (int i = 0; i < 4; i++) {
            h += pw * b[i];
            pw *= 10;
        }
        return h;
    }
    bool operator == (const pp &a) const {
        for (int i = 0; i < 4; i++) {
            if (t[i] != a.t[i]) {
                return false;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (b[i] != a.b[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    Rd("msquare.in");
    Wt("msquare.out");
    int top[4], bot[4];
    for (int i = 0; i < 4; i++) cin >> top[i];
    for (int i = 0; i < 4; i++) cin >> bot[i];

    int stop[4] = {1, 2, 3, 4};
    int sbot[4] = {5, 6, 7, 8};
    pp goal(top, bot);
    pp st(stop, sbot);
    int g = goal.hsh();
    cout << g << endl;
    queue< pair<pp, int> > q;
    q.push({st, 0});
    map<int, char> mp;
    mp[st] = 'D';
    while (!q.empty()) {
        pp top = q.front().first;
        int m = q.front().second;
        q.pop();
        cout << top.hsh() << ' ' << m << endl;
        int h = top.hsh();
        if (h == g) {
            cout << m << endl;
            string s;
            while (mp[h] != 'D') {
                s += mp[h];

            }
            reverse(s.begin(), s.end());
            break;
        }
        pp a = top.movea(), b = top.moveb(), c = top.movec();
        int a1 = a.hsh(), b1 = b.hsh(), c1 = c.hsh();
        if (!mp[a1]) {
            mp[a1] = 'A';
            q.push({a, m + 1});
        } if (!mp[b1]) {
            mp[b1] = 'B';
            q.push({b, m + 1});
        } if (!mp[c1]) {
            mp[c1] = 'C';
            q.push({c, m + 1});
        }
    }
    /*for (int i = 0; i < 4; i++) cout << st.b[i] << ' ';
    cout << endl;
    for (int i = 0; i < 4; i++) cout << st.t[i] << ' ';
    cout << endl;*/
}

