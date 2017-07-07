#include <bits/stdc++.h>
using namespace std;

struct pp {
    long long laps, mod;
    bool operator < (const pp &a) const {
        return laps < a.laps || (laps == a.laps && mod < a.mod);
    }
};

const int maxn = 1e5 + 5;
long long bit[maxn];

long long add(int x) {
    long long total = 0;
    for (; x > 0; x -= x & -x) {
        total += bit[x];
    }
    return total;
}

void update(int x, int val) {
    for (; x < maxn; x += x & -x) {
        bit[x] += val;
    }
}
bool cmp(const pp &a, const pp &b) {
    return a.mod < b.mod || (a.mod == b.mod && a.laps < b.laps);
}

int main() {
    freopen("running.in", "r", stdin);
    int n; long long l, c;
    scanf("%d %lld %lld", &n, &l, &c);
    vector<long long> s(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &s[i]);
    }
    sort(s.begin(), s.end());
    double t = (l * 1.0 * c) / s[n-1];
    vector<pp> cows(n);
    for (int i = 0; i < n; i++) {
        cows[i].laps = (s[i] * l * c) / (c * s[n-1]);
        cows[i].mod = (s[i] * l * c) % (c * s[n-1]);
    }
    sort (cows.begin(), cows.end(), cmp);

    //sliding window
    int left = 0, right = 0, counter = 1;
    while (left < n) {
        right = left+1;
        while (right < n && cows[left].mod == cows[right].mod) {
            right++;
        }
        for (int i = left; i < right; i++) {
            cows[i].mod = counter;
        }
        counter++;
        left = right;
    }
    sort(cows.begin(), cows.end());
    long long cnt = 1, total = 0, sum = 0, subtract = 0;
    for(int i = 1; i < n; i++) {
        total += (cows[i].laps - cows[i-1].laps) * cnt;
        sum += total;
        cnt++;
    }
    reverse(cows.begin(), cows.end());
    for (int i = 0; i < n; i++) {
        subtract += add(cows[i].mod);
        update(cows[i].mod + 1, 1);
    }
    printf("%lld\n", sum - subtract);
}


