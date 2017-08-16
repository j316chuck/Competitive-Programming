struct RMQ {
    long long a[maxn], lazy[4 * maxn], seg[4 * maxn];
    void init(long long *arr, int n) {
        //fill(seg, seg + maxn, INF);
        //fill(a, a + maxn, INF);
        for (int i = 0; i < n; i++) {
            a[i] = arr[i];
        }
    }
    void build(int x, int st, int en) {
        if (st == en) {
            seg[x] = a[st];
            return;
        }
        int mid = (st + en) >> 1;
        build(2 * x, st, mid);
        build(2 * x + 1, mid + 1, en);
        seg[x] = min(seg[2 * x], seg[2 * x + 1]);
    }
    void push(int x, int st, int en) {
        if (lazy[x]) {
            seg[x] += lazy[x];
            if (st != en) {
                lazy[2 * x] += lazy[x];
                lazy[2 * x + 1] += lazy[x];
            }
            lazy[x] = 0;
        }
    }
    void update(int x, int st, int en, int l, int r, long long val) {
        push(x, st, en);
        if (r < st || en < l) {
            return;
        }
        if (l <= st && en <= r) {
            lazy[x] += val;
            push(x, st, en);
            return;
        }
        int mid = (st + en) >> 1;
        update(2 * x, st, mid, l, r, val);
        update(2 * x + 1, mid + 1 , en, l, r, val);
        seg[x] = min(seg[2 * x], seg[2 * x + 1]);
    }
    long long query(int x, int st, int en, int l, int r) {
        push(x, st, en);
        if (r < st || en < l) {
            return INF;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return min(query(2 * x, st, mid, l, r), query(2 * x + 1, mid + 1, en, l, r));
    }
} rmq;
