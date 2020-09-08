/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0776 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define f first
#define s second
pii operator + (pii a, pii b) { return { a.f + b.f, a.s + b.s }; }



int main() {
    int n, m;
    cin >> m >> n;
    pii s = {0, 0}, e; cin >> e.s >> e.f;
    e.f--; e.s--;
    int k, D; cin >> k >> D;
    int dt_arr[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dt_arr[i][j];
        }
    }

    auto dt = [&](pii a) -> int& { return dt_arr[a.f][a.s]; };
    auto check = [&](pii a) { return a.f >= 0 && a.f < n && a.s >= 0 && a.s < m; };

    bool usd_arr[100][100][10] = {0};
    auto usd = [&](pair<pii, int> a) -> bool& { return usd_arr[a.f.f][a.f.s][a.s]; };

    int ans = 0;

    pair<pii, int> sep = {{-1, -1}, -1};
    queue<pair<pii, int>> q; q.push({s, k}); q.push(sep);
    usd({s, k}) = true;
    assert(dt(s) != 0);
    while (1) {
        auto cr = q.front(); q.pop();
        if (cr == sep) {
            if (q.empty()) { cout << "IMPOSSIBLE"; return 0;}
            ans++; q.push(sep); continue;
        }
        if (cr.f == e) { cout << ans; return 0; }
        for (auto d: vector<pii>({{0, 1},{0, -1},{1, 0},{-1, 0}})) {
            pii nxt = cr.f + d;
            if (!check(nxt) || usd({nxt, cr.s}) || !dt(nxt) || abs(dt(nxt) - dt(cr.f)) > 1) continue;
            usd({nxt, cr.s}) = true;
            q.push({nxt, cr.s});
        }
        if (!cr.s) continue;
        for (auto d: vector<pii>({{0, 1},{0, -1},{1, 0},{-1, 0}})) {
            int ost = D; pii top = cr.f;
            for (pii nxt = cr.f + d; check(nxt); nxt = nxt + d) {
                ost --;
                if (dt(top) < dt(nxt)) { ost -= dt(nxt) - dt(top); top = nxt; }
                if (ost >= 0 && dt(nxt) != 0 && !usd({nxt, cr.s - 1})) {
                    q.push({nxt, cr.s - 1});
                    usd({nxt, cr.s - 1}) = true;
                }
            }
        }
    }
}