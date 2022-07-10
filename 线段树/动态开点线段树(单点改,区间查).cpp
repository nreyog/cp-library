struct SegTree {
    
    int cnt;
    vector<int> tr, lson, rson;

    SegTree() {}
    SegTree(int n) {    // 能开多大就开多大
        cnt = 2;
        tr.resize(n);
        lson.resize(n);
        rson.resize(n);
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
