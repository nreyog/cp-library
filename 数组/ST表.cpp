// 例题: https://loj.ac/p/10119
#include <bits/stdc++.h>

using namespace std;

struct ST {

    vector<vector<int>> st;

    ST() {}
    ST(vector<int> &a) {
        int n = a.size();
        int k = __lg(n);
        st.resize(n + 5, vector<int> (20));
        for (int i = 0; i < n; i++) st[i + 1][0] = a[i];
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j + (1 << i) - 1 <= n; j++) {
                st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
    
    int query(int l, int r) {   // 下标从1开始
        int k = __lg(r - l + 1);
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ST S(a);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << S.query(l, r) << endl;
    }
    return 0;
}
