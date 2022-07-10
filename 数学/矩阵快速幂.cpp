typedef long long ll;
ll mod = 1e9 + 7;
vector<vector<ll>> mat_mul(vector<vector<ll>>& a, vector<vector<ll>>& b) { // 矩阵乘法
    ll n = a.size(), m = b[0].size();
    vector<vector<ll>> c(n, vector<ll> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                c[i][j] = ((a[i][k] * b[k][j]) % mod + c[i][j]) % mod;
            }
        }
    }
    return c;
}
vector<vector<ll>> mat_pow(vector<vector<ll>>& a, ll b) {
    int n = a.size();
    vector<vector<ll>> res(n, vector<ll> (n));
    // 把res初始化为n阶单位矩阵
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    while (b) {
        if (b & 1) {
            res = mat_mul(res, a);
        }
        a = mat_mul(a, a);
        b >>= 1;
    } 
    return res;
}
