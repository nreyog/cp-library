// 例题:https://loj.ac/p/132
#include <bits/stdc++.h>
#define int long long

using namespace std;

struct SegTree {

    vector<int> d, lazy;

    SegTree() {}
    SegTree(int n) {
        d.resize(n * 4 + 5);
        lazy.resize(n * 4 + 5);
    }

    void push_down(int p, int l, int r, int m) {
        d[p << 1] += lazy[p] * (m - l + 1);
        d[p << 1 | 1] += lazy[p] * (r - m);
        lazy[p << 1] += lazy[p];
        lazy[p << 1 | 1] += lazy[p];
        lazy[p] = 0;
    }

    void change(int p, int l, int r, int s, int t, int v) {
        if (r < s || l > t) {
            return;
        } else if (s <= l && r <= t) {
            d[p] += (r - l + 1) * v;
            lazy[p] += v;
            return;
        } else {
            int m = l + r >> 1;
            push_down(p, l, r, m);
            change(p << 1, l, m, s, t, v);
            change(p << 1 | 1, m + 1, r, s, t, v);
            d[p] = d[p << 1] + d[p << 1 | 1];
        }
    }

    int query(int p, int l, int r, int s, int t) {
        if (r < s || l > t) {
            return 0;
        } else if (s <= l && r <= t) {
            return d[p];
        } else {
            int m = l + r >> 1;
            push_down(p, l, r, m);
            return query(p << 1, l, m, s, t) + query(p << 1 | 1, m + 1, r, s, t);
        }
    }

};

signed main() {
    int n, m;
    cin >> n >> m;
    SegTree S(n);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        S.change(1, 1, n, i, i, a);
    }
    while (m--) {
        int op, l, r, v;
        cin >> op;
        if (op == 1) {
            cin >> l >> r >> v;
            S.change(1, 1, n, l, r, v);
        } else {
            cin >> l >> r;
            cout << S.query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}
