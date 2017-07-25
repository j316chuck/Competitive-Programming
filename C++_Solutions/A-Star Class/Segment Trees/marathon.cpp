#include <bits/stdc++.h>
using namespace std;

struct pp {
    int dis, sub;
};
const int maxn = 1e5+5;
pair<int, int> a[maxn];
pp seg[4*maxn];

int dist(int u, int v) {
    return fabs(a[u].first - a[v].first) + fabs(a[u].second - a[v].second);
}

int manhattan(int mid) {
    return dist(mid, mid+1) + dist(mid-1, mid) - dist(mid-1, mid+1);
}

int combine_sub(int lsub, int rsub, int st, int en) {
    int ret = max(lsub, rsub);
    int mid = (st + en) >> 1;
    if (mid != st && mid != en) ret = max(ret, manhattan(mid));
    if (mid+1 != st && mid+1 != en) ret = max(ret, manhattan(mid+1));
    return ret;
}

int combine_dis(int d1, int d2, int mid) {
    return d1 + d2 + dist(mid, mid+1);
}

void build(int node, int st, int en) {
    if (st == en) {
        seg[node].dis = 0;
        seg[node].sub = 0;
        return;
    }
    int mid = (st + en) >> 1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    seg[node].dis = combine_dis(seg[2*node].dis, seg[2*node+1].dis, mid);
    seg[node].sub = combine_sub(seg[2*node].sub, seg[2*node+1].sub, st, en);
}

pp query(int node, int st, int en, int l, int r) {
    if (en < l || st > r) {
        //cout <<"WRONG " << st << ' ' << en << ' '  << seg[node].dis << ' ' << seg[node].sub <<  endl;
        return {-1, -1};
    } if (l <= st && en <= r) {
        //cout <<"RETURN " << st << ' ' << en << ' '  << seg[node].dis << ' ' << seg[node].sub << endl;
        return seg[node];
    }
    int mid = (st + en) >> 1;
    pp q1 = query(2*node, st, mid, l, r);
    pp q2 = query(2*node+1, mid+1, en, l, r);
    if (q1.dis == -1) return q2;
    if (q2.dis == -1) return q1;
    int d = combine_dis(q1.dis, q2.dis, mid);
    int s = max(q1.sub, q2.sub);
    if (mid != st && mid != en && mid != l && mid != r) s = max(s, manhattan(mid));
    if (mid+1 != st && mid+1 != en && mid+1 != l && mid+1 != r) s = max(s, manhattan(mid+1));
    //cout << "END: " << node << ' ' << d << ' ' << s << ' ' << st << ' ' << en << endl;
    return {d, s};
}

void update(int node, int st, int en, int id, int x, int y) {
    if (st == en) {
        a[id] = make_pair(x, y);
        return;
    }
    int mid = (st + en) >> 1;
    if (st <= id && id <= mid) {
        update(2*node, st, mid, id, x, y);
    } else {
        update(2*node+1, mid+1, en, id, x, y);
    }
    seg[node].dis = combine_dis(seg[2*node].dis, seg[2*node+1].dis, mid);
    seg[node].sub = combine_sub(seg[2*node].sub, seg[2*node+1].sub, st, en);
}

int main() {
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d %d ", &a[i].first, &a[i].second);
    }
    build(1, 0, n-1);
    char c; int l, r, x, y, j; pp ret;
    for (int i = 0; i < q; i++) {
        scanf("%c ", &c);
        if (c == 'Q') {
            scanf("%d %d ", &l, &r);
            l--, r--;
            ret = query(1, 0, n-1, l, r);
            printf("%d\n", ret.dis - ret.sub);
            //cout <<endl << endl;
        } else {
            scanf("%d %d %d ", &j, &x, &y);
            j--;
            update(1, 0, n-1, j, x, y);
        }
    }
}


