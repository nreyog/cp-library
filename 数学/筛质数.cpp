// 例题:https://www.luogu.com.cn/problem/P3383
#include <bits/stdc++.h>

using namespace std;
 
vector<int> Eratosthenes(int n) {  // 埃氏筛,时间复杂度O(nloglogn)
    vector<int> prime;
    vector<bool> is_prime(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = 0;
        }
    }
    return prime;
}

vector<int> Euler(int n) {  // 欧拉筛,时间复杂度O(n)
    vector<int> prime;
    vector<bool> not_prime(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] <= n; j++) {
            not_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return prime;
}

int main() {
    int n, q;
    cin >> n >> q;
    //vector<int> prime = Eratosthenes(n);
    vector<int> prime = Euler(n);
    while (q--) {
        int k;
        cin >> k;
        cout << prime[k - 1] << endl;
    }
    return 0;
}
