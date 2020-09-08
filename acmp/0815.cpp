/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0815 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<map<int, vector<int>>> gr(n+1);
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        gr[a][c].push_back(b);
    }
    int l; cin >> l;
    vector<int> pth(l);
    for (auto &x: pth) {
        cin >> x;
    }
    int s; cin >> s;

    set<int> ans;
    bool usd[1001][1000] = {0};
    function<void(int, int)> dfs = [&](int v, int i) {
        if (i == l) { ans.insert(v); return; }
        if (usd[v][i]) return;
        usd[v][i] = true;
        for (auto &u: gr[v][pth[i]]) {
            dfs(u, i + 1);
        }
    };
    dfs(s, 0);
    cout << (ans.empty() ? "Hangs" : "OK") << endl;
    if (!ans.empty()) cout << ans.size() << endl;
    for (auto x: ans) cout << x << ' ';
}