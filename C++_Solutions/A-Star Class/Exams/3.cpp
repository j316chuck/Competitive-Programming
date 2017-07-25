#include <bits/stdc++.h>
using namespace std;

struct pp {
    long long cost, coupon;
    bool operator < (const pp &a) const {
        return cost < a.cost;
    }
};

const int maxn = 1e5+5;
int n, k;
long long max_value;
vector<pp> v;
bool mark[maxn];

int main() {
    freopen("3.in", "r", stdin);
    scanf("%d %d %lld", &n, &k, &max_value);
    for (int i = 0; i < n; i++) {
        long long cost, coupon;
        scanf("%lld %lld", &cost, &coupon);
        v.push_back({cost, coupon});
    }
    sort(v.begin(), v.end());
    /*for (int i = 0; i < v.size(); i++)
        cout << v[i].cost << ' ' << v[i].coupon << endl;*/

    priority_queue< pair<long long, int>, vector< pair<long long, int> >, greater< pair<long long, int> > > pq;
    long long sub = 0, total = 0; int break_index, old_pop;
    for (int i = 0; i < n; i++) {
        total += v[i].cost;
        sub += v[i].cost - v[i].coupon;
        pq.push(make_pair(v[i].cost - v[i].coupon, i));
        if (pq.size() > k) {
            sub -= pq.top().first;
            old_pop = pq.top().second;
            pq.pop();
        }
        if (total - sub > max_value) {
            break_index = i;
            break;
        }
    }
    pq.push({v[old_pop].cost - v[old_pop].coupon, old_pop});
    memset(mark, false, sizeof(mark));
    while (!pq.empty()) {
        int index = pq.top().second;
        if (index != break_index) mark[index] = true;
        //cout << pq.top().second << endl;
        pq.pop();
    }
    total = 0;
    for (int i = 0; i < break_index; i++) {
        mark[i] = !mark[i];
        if (mark[i]) {
            total += v[i].cost;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mark[i] << endl;
    }
    priority_queue< pair<long long, int> > q;
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {

            q.push({v[i].coupon, i});
            if (q.size() > k) {
                q.pop();
            }
        }
    }
    sub = 0;
    while (!q.empty()) {
        int index = q.top().second;
        mark[index] = true;
        sub += q.top().first;
        q.pop();
    }
    total += sub;
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            if (total + v[i].cost > max_value) {
                break;
            }
            mark[i] = true;
            total += v[i].cost;
        }
    }
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (mark[i]) counter++;
    }
    printf("%d\n", counter);
    //cout << break_index << endl;
}

