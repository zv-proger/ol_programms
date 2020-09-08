/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0221 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ppp = pair<pair<pii, pii>, int>;
#define f first
#define s second
pii operator + (pii a, pii b) { return {a.f + b.f, a.s + b.s}; }

map<pii, vector<pii>> to = {
    {{0, 1},  {{1, 0},  {0, 1},  {-1, 0} }},
    {{0, -1}, {{-1, 0}, {0, -1}, {1, 0}  }},
    {{1, 0},  {{0, -1}, {1, 0},  {0, 1}  }},
    {{-1, 0}, {{0, 1},  {-1, 0}, {0, -1} }},
};

int main() {
    int k, n, m; cin >> k >> n >> m;
    pii s, e;
    int dt[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dt[i][j];
            if (dt[i][j] == 2) s = {i, j};
            if (dt[i][j] == 3) e = {i, j};
        }
    }


    auto gt = [&](pii a) -> int {
        if (a.f >= n || a.s >= m || a.f < 0 || a.s < 0) return 1;
        return dt[a.f][a.s];
    };

    set<ppp> usd;
    queue<ppp> q;
    ppp seg = {{{-1, -1}, {-1, -1}}, -1};
    for (auto &p: to) {
        q.push({{p.f, s}, k});
        usd.insert({{p.f, s}, k});
    }
    q.push(seg);

    int ans = 0;
    while (1) {
        auto cur = q.front(); q.pop();
        if (cur == seg) {
            if (q.empty()) { cout << -1; return 0; }
            ans++; q.push(seg); continue;
        }
        pii p = cur.f.s, v = cur.f.f;
        int k = cur.s;
        if (p == e) break;

        bool f = true;
        for (auto &d: to[v]) {
            int nk = k - f; f = false;
            ppp nxt = {{d, d + p}, nk};
            if (nk < 0 || gt(d + p) == 1 || usd.count(nxt)) continue;
            usd.insert(nxt);
            q.push(nxt);
        }
    }
    cout << ans;
}