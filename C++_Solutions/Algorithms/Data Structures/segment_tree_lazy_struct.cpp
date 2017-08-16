
struct SegmentTree {
    int lazy[4 * maxn] = {0}, seg[4 * maxn] = {0};
    void push(int x, int st, int en) {
        if (lazy[x]) {
            seg[x] += (en - st + 1) * lazy[x];
            if (st != en) {
                lazy[2 * x] += lazy[x];
                lazy[2 * x + 1] += lazy[x];
            }
            lazy[x] = 0;
        }
    }
    int query_range(int x, int st, int en, int l, int r) {
        push(x, st, en);
        if (r < st || en < l) {
            return 0;
        }
        if (l <= st && en <= r) {
            return seg[x];
        }
        int mid = (st + en) >> 1;
        return query_range(2 * x, st, mid, l, r) + query_range(2 * x + 1, mid + 1, en, l, r);
    }
    void update_range(int x, int st, int en, int l, int r, int val) {
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
        update_range(2 * x, st, mid, l, r, val);
        update_range(2 * x + 1, mid + 1, en, l, r, val);
        seg[x] = seg[2 * x] + seg[2 * x + 1];
    }
} huk, vk;
