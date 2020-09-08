/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0703 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using st = vector<string>;
using pii = pair<int, int>;

#define f first
#define s second
pii operator + (pii a, pii b) { return {a.f + b.f, a.s + b.s}; }

vector<pii> to = {{1, 2}, {2, 1}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, -1}, {-1, -2}};

bool check (pii x) { return x.f >= 0 && x.s >= 0 && x.f < 3 && x.s < 3; }

vector<st> next(const st &s) {
    vector<st> ans;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (s[i][j]) {
                for (auto &d: to) {
                    pii nxt = pii(i, j) + d;
                    if (!check(nxt) || s[nxt.f][nxt.s]) continue;
                    st x = s; x[nxt.f][nxt.s] = x[i][j];
                    x[i][j] = 0;
                    ans.push_back(x);
                }
            }
        }
    }
    return ans;
}

int main() {
    st s, e;
    for (string a, b; cin >> a >> b; ) {
        s.push_back(a); e.push_back(b);
        for (auto &c: s.back()) c = (c == 'W'? 1: c == 'B'? 2: 0);
        for (auto &c: e.back()) c = (c == 'W'? 1: c == 'B'? 2: 0);
    }
    st seg;
    queue<st> q; q.push(s); q.push(seg);
    set<st> usd = {s};

    int ans = 0;
    while (1) {
        st cr = q.front(); q.pop();
        if (cr == seg) {
            if (q.empty()) { ans = -1; break; }
            ans ++; q.push(seg); continue;
        }
        if (cr == e) break;
        for (st nxt: next(cr)) {
            if (usd.count(nxt)) continue;
            usd.insert(nxt);
            q.push(nxt);
        }
    }
    cout << ans;
}