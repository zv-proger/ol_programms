/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0730 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using piii = pair<int, pii>;

int main() {
    int n, m; cin >> n >> m;
    map<int, map<int, int>> gr;
    map<pii, int> bk;
    vector<pii> dt;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        dt.push_back({a, b});
        if (!gr[a].count(b) || gr[a][b] > c) gr[a][b] = c, bk[{a, b}] = i;
    }
    int e = (1 << n) - 1;
    map<int, int> eg;
    priority_queue<piii, vector<piii>, greater<piii>> q; q.push({0, {1, 1}});
    while (q.size()) {
        int cr = q.top().second.first;
        int p = q.top().second.second;
        int w = q.top().first;
        q.pop();
        if (eg.count(cr)) continue;
        eg[cr] = p;
        if (cr == e) {
            cout << w << ' '; break;
        }
        for (auto &o: gr) {
            if (cr & (1 << o.first))
                for (auto &p: o.second) {
                    int nxt = cr | (1 << p.first);
                    if (nxt == cr) continue;
                    if (eg.count(nxt)) continue;
                    q.push({w + p.second, {nxt, bk[{o.first, p.first}]}});
                }
        }
    }
    list<int> ans;
    int c = e;
    while (c != 1) {
        int e = eg[c];
        ans.push_front(e + 1);
        c ^= 1 << dt[e].second;
    }
    cout << ans.size() << endl;
    for (auto &x: ans) cout << x << ' ';
}