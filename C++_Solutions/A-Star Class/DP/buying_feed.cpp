#include <bits/stdc++.h>
using namespace std;

struct pp {
    int x, f; long long c;
    bool operator < (const pp &a) const {
        return x < a.x;
    }
};

const long long INF = 1LL << 60;
const int maxn = 1e4 + 5;
int max_feed, total_distance, n;
long long dp_old[maxn], dp_new[maxn];

int main() {
    freopen("buying_feed.in", "r", stdin);
    scanf("%d %d %d", &max_feed, &total_distance, &n);
    vector<pp> v(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %lld", &v[i].x, &v[i].f, &v[i].c);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= max_feed; i++) {
        i > v[0].f ? dp_old[i] = -1 : dp_old[i] = v[0].c * i;
    }
    for (int i = 1; i < v.size(); i++) {
        long long distance = v[i].x - v[i-1].x;
        priority_queue< pair<long long, int> , vector< pair<long long, int> >, greater< pair<long long, int> > > pq;
        //pq = priority_queue< pair<long long, int> , vector< pair<long long, int> >, greater< pair<long long, int> > > ();
        //priority_queue< pair <long long, int> > pq;
        memset(dp_new, -1, sizeof(dp_new));
        for (int k = 0; k <= max_feed; k++) {
            if (dp_old[k] != -1) {
                pq.push({dp_old[k] - k * v[i].c + k * k * distance, k});
            }
            while (!pq.empty() && pq.top().second + v[i].f < k) {
                pq.pop();
            }
            if (!pq.empty()) dp_new[k] = pq.top().first +  k * v[i].c;
        }
        /*for (int k = 0; k <= max_feed; k++) {
            cout << dp_old[k] << ' ';
        } cout << endl << endl;*/
        memcpy(dp_old, dp_new, sizeof(dp_new));
    }
    printf("%lld\n", max_feed * max_feed * (total_distance - v.back().x) + dp_new[max_feed]);
}
