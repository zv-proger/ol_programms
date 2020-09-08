/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0650 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int t = 0;
long long cnt(long long n) {
    if (t == 2) return n * ((n / 2 - 1) * (n / 2) - (n % 2 == 0) * (n / 2 - 1));
    long long ans = 0;
    n--;
    for (long long i = 0; i <= n; i++) {
        ans += i * (i - 1) / 2;
        ans += (n - i) * ((n - i) - 1) / 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<bool> usd(n + 1);
    vector<vector<int>> gr(n + 1);
    for (; m--; ) {
        int a , b; cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    long long ans = 0;
    function<int(int, int)> dfs = [&](int v, int p) {
        if (usd[v]) { t = 2; return 0; }
        int ans = usd[v] = 1;
        for (auto &x: gr[v]) {
            if (x == p) continue;
            ans += dfs(x, v);
        }
        return ans;
    };

    for (int i = 1; i <= n; i++) {
        t = 1;
        ans += cnt(dfs(i, -1));
    }
    cout << ans;
}