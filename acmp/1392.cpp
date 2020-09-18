/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 1392 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> gr(n);
    for (int m = n * k; m--; ) {
        int a, b; cin >> a >> b;
        a--, b--;
        gr[a].push_back(b);
    }
    vector<int> to (n, -1), pr(n, -1);
    vector<bool> usd;

    function <bool (int)> dfs = [&](int v) {
        if (usd[v]) return false;
        usd[v] = true;
        for (auto &u: gr[v]) {
            if (to[u] == -1 || dfs(to[u])) {
                to[u] = v;
                pr[v] = u;
                return true;
            }
        }
        return false;
    };

    for (bool f = true; f; ) {
        f = false;
        usd.assign(n, false);
        for (int i = 0; i < n; i++) {
            f |= pr[i] == -1 && dfs(i);
        }
    }

    for (int i = 0; i < n; i++) {
        assert(to[i] >= 0);
        cout << to[i] + 1 << ' ' << i + 1 << endl;
    }
}