// 例题: https://www.luogu.com.cn/problem/P3379
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

struct LCA {

    vector<int> depth;
    queue<int> q;
    vector<vector<int>> g, fa;
    int root;

    LCA() {}
    LCA(int n, int _root) {    // 构造函数,传入点数和根节点编号
        root = _root;
        depth.resize(n + 5, 1e9);
        g.resize(n + 5);
        fa.resize(n + 5, vector<int> (21));
        depth[0] = 0, depth[root] = 1;
    }

    void add(int u, int v) {    // 添加一条无向边
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void build() {  // 加边后,bfs进行初始化
        q.push(root);
        while (q.size()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < g[now].size(); i++) {
                int nxt = g[now][i];
                if (depth[nxt] > depth[now] + 1) {
                    depth[nxt] = depth[now] + 1;
                    q.push(nxt);
                    fa[nxt][0] = now;
                    for (int j = 1; j <= 19; j++) {
                        fa[nxt][j] = fa[fa[nxt][j - 1]][j - 1];
                    }
                }
            }
        }
    }

    int get(int a, int b) { // 获取a和b的最近公共祖先
        if (depth[a] < depth[b]) swap(a, b);
        for (int i = 19; i >= 0; i--) {
            if (depth[fa[a][i]] >= depth[b]) {
                a = fa[a][i];
            }
        }
        if (a == b) return a;
        for (int i = 19; i >= 0; i--) {
            if (fa[a][i] != fa[b][i]) {
                a = fa[a][i];
                b = fa[b][i];
            }
        }
        return fa[a][0];
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q, root;
    cin >> n >> q >> root;
    LCA S(n, root);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        S.add(u, v);
    }
    S.build();
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << S.get(a, b) << endl;
    }
    return 0;
}
