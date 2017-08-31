struct SegmentTree {
    long long seg[4 * maxn];
    void init() {
        memset(seg, 0, sizeof(seg));
    }
    long long query(int x, int st, int en, int l, int r) {
        if (r < st || en < l) {
            return 0;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return query(2 * x, st, mid, l, r) + query(2 * x + 1, mid + 1, en, l, r);
    }
    void update(int x, int st, int en, int id, long long val) {
        if (st == en) {
            seg[x] += val;
            return;
        }
        int mid = (st + en) >> 1;
        if (id <= mid) {
            update(2 * x, st, mid, id, val);
        } else {
            update(2 * x + 1, mid + 1, en, id, val);
        }
        seg[node] = seg[2 * x] + seg[2 * x + 1];
    }
} tree[11];
