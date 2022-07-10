// 例题:https://loj.ac/p/130
#include <bits/stdc++.h>
#define int long long

using namespace std;

struct SegTree {
    
    int inf = 2e9;
    vector<int> sum, maxx;
    
    SegTree() {}
    SegTree(int n) {
        sum.resize(n * 4 + 5);
        maxx.resize(n * 4 + 5);
    }

    void change(int p, int l, int r, int x, int t) {    // 单点修改
        if (r < x || l > x) return;
        else if (l == r && l == x) sum[p] = maxx[p] = t;
        else {
            int m = (l + r) / 2;
            change(p * 2, l, m, x, t);
            change(p * 2 + 1, m + 1, r, x, t);
            sum[p] = sum[p * 2] + sum[p * 2 + 1];
            maxx[p] = max(maxx[p * 2], maxx[p * 2 + 1]);
        }
    }

    int query_max(int p, int l, int r, int ql, int qr) {    // 查询区间max
        if (r < ql || l > qr) return -inf;
        else if (ql <= l && r <= qr) return maxx[p];
        else {
            int m = (l + r) / 2;
            return max(query_max(p * 2, l, m, ql, qr), query_max(p * 2 + 1, m + 1, r, ql, qr));
        }
    }

    int query_sum(int p, int l, int r, int ql, int qr) {    // 查询区间sum
        if (r < ql || l > qr) return 0;
        else if (ql <= l && r <= qr) return sum[p];
        else {
            int m = (l + r) / 2;
            return query_sum(p * 2, l, m, ql, qr) + query_sum(p * 2 + 1, m + 1, r, ql, qr);
        }
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    SegTree Seg(n);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        Seg.change(1, 1, n, i, a);
    }
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            int now = Seg.query_sum(1, 1, n, l, l);
            Seg.change(1, 1, n, l, now + r);
        } else {
            cout << Seg.query_sum(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}
