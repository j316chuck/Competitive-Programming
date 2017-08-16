#include <bits/stdc++.h>
using namespace std;

struct pp {
    int st, en;
    bool operator < (const pp &a) const {
        return en > a.en;
    }
};

bool cmp (pp &a, pp &b) {
    return a.st < b.st;
}

const int maxn = 1e6+5;
int lst[26], fst[26];

int main() {
    //freopen("426B.in", "r", stdin);
    int n, max_k; char c;
    scanf("%d %d ", &n, &max_k);
    memset(lst, -1, sizeof(lst));
    memset(fst, 0x3f, sizeof(fst));
    for (int i = 0; i < n; i++) {
        scanf("%c", &c);
        lst[c - 'A'] = max(lst[c - 'A'], i);
        fst[c - 'A'] = min(fst[c - 'A'], i);
    }
    vector<pp> v;
    for (int i = 0; i < 26; i++) {
        if (lst[i] != -1) {
            v.push_back({fst[i], lst[i]});
        }
    }
    sort(v.begin(), v.end(), cmp);
    /*for (int i = 0; i < v.size(); i++) {
        cout << v[i].st << ' ' << v[i].en << endl;
    }*/
    priority_queue<pp> pq;
    for (int i = 0; i < v.size(); i++) {
        pq.push(v[i]);
        while (pq.top().en < v[i].st) {
            pq.pop();
        }
        if (pq.size() > max_k) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
