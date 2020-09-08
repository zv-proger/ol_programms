/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0979 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

const int inf = 1e9;

using ll = long long;
using pii = pair<int, int>;
#define f first
#define s second
pii operator+ (pii a, pii b) {return {a.f + b.f, a.s + b.s}; }
using ppp = pair<pii, pii>;


int main() {
    int n; cin >> n;
    map<pii, int> num;
    vector<pii> dt;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        dt.push_back({x, y});
        num[{x, y}] = i + 1;
    }
    queue<ppp> q; q.push({dt.front(), {0, 0}});
    map<ppp, ppp> par; par[{dt.front(), {0, 0}}] = {dt.front(), {0, 0}};
    ppp cr;
    vector<pii> sk = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}};
    while (!q.empty()) {
        cr = q.front(); q.pop();
        pii p = cr.f, v = cr.s;
        if (p == dt.back()) break;
        for (auto d: sk) {
            pii nv = v + d, np = p + nv;
            ppp nxt = {np, nv};
            if (!num.count(np) || par.count(nxt)) continue;
            par[nxt] = cr;
            q.push(nxt);
        }
    }
    if (cr.f != dt.back()) { cout << -1; return 0; }
    vector<int> ans;
    while (cr != par[cr]) {
        ans.push_back(num[cr.f]);
        cr = par[cr];
    }
    reverse(ALL(ans));
    cout << ans.size() << endl << 1;
    for (auto &x: ans) cout << ' ' << x;

}