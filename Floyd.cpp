// 例题:https://syzoj.com/problem/446
#include <bits/stdc++.h>

using namespace std;

struct Floyd {
    vector<vector<int>> g;
    int n, inf = 1e9;

    void init(int _n) {  // 初始化,输入点数
        g.resize(_n + 5, vector<int> (_n + 5, inf));
        n = _n + 5;
    }

    void addEdge(int from, int to, int value) { // 添加有向边
        g[from][to] = min(g[from][to], value);
    }

    void get_all() {    // 获取任意两点间的最短路长度
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                }
            }
        }
    }

    int get(int from, int to) { // 获取从from到to的最短路长度
        return g[from][to];
    }
};

int main() {
    int n;
    cin >> n;
    Floyd F;
    F.init(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            cin >> value;
            F.addEdge(i, j, value);
        }
    }
    F.get_all();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << F.get(i, j) << ' ';
        }
        cout << endl;
    }
    return 0;
}
