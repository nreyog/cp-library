// 例题:https://loj.ac/p/119
#include <bits/stdc++.h>

using namespace std;

struct Dijkstra {

    vector<int> dist;
    vector<vector<pair<int, int>>> g;

    Dijkstra(int n) {   // 构造函数
        dist.resize(n + 5, 1e9);
        g.resize(n + 5);
    }

    void addEdge(int from, int to, int value) { // 添加有向边
        g[from].push_back({to, value});
    }

    void get_dist(int start) {  // 获取从start到其他点的最短路径长度
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({0, start});
        while (!q.empty()) {
            auto [u, t] = q.top();
            q.pop();
            if (u > dist[t]) continue;
            for (auto [v, w] : g[t]) {
                if (u + w < dist[v]) {
                    dist[v] = u + w;
                    q.push({u + w, v});
                }
            }
        }
    }
};

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    Dijkstra D(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        D.addEdge(u, v, w);
        D.addEdge(v, u, w);
    }
    D.get_dist(s);
    cout << D.dist[t] << endl;
    return 0;
}
