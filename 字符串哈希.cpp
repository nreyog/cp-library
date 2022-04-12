// 例题:https://loj.ac/p/103
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
struct String_hash {
    vector<ull> pre, p;

    void init(string s) {
        int n = s.size();
        pre.resize(n + 1);
        p.resize(n + 1);
        p[0] = 1;
        ull base = 131;
        for (int i = 0; i < n; i++) {
            p[i + 1] = p[i] * base;
            pre[i + 1] = pre[i] * base + s[i] - 'a' + 1;
        }
    }

    // 字符串下标从1开始
    ull get_hash(int l, int r) {return pre[r] - pre[l - 1] * p[r - l + 1];}
};

int main() {
    string a, b;
    cin >> a >> b;
    String_hash A, B;
    A.init(a);
    B.init(b);
    int n = a.size(), m = b.size(), res = 0;
    for (int i = 0; i + m - 1 < n; i++) {
        if (A.get_hash(i + 1, i + m) == B.get_hash(1, m)) res++;
    }
    cout << res << endl;
    return 0;
}
