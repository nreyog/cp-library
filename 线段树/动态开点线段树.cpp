struct SegTree {
    
    int cnt;
    vector<int> tr, lson, rson;

    SegTree(int n) {
        cnt = 2;
        int max_len = n * 150;    // 能开多大就开多大
        tr.resize(max_len);
        lson.resize(max_len);
        rson.resize(max_len);
    }

    void change(int p, int l, int r, int x, int v) {
        if (r < x || l > x) {
            return;
        } else if (l == r && l == x) {
            tr[p] = v;
        } else {
            int m = l + r >> 1;
            if (lson[p] == 0) lson[p] = cnt++;
            if (rson[p] == 0) rson[p] = cnt++;
            change(lson[p], l, m, x, v);
            change(rson[p], m + 1, r, x, v);
            tr[p] = tr[lson[p]] + tr[rson[p]];
        }
    }

    int query(int p, int l, int r, int s, int t) {
        if (r < s || l > t) {
            return 0;
        } else if (s <= l && r <= t) {
            return tr[p];
        } else {
            int m = l + r >> 1;
            if (lson[p] == 0) lson[p] = cnt++;
            if (rson[p] == 0) rson[p] = cnt++; 
            return query(lson[p], l, m, s, t) + query(rson[p], m + 1, r, s, t);
        }
    }
};
