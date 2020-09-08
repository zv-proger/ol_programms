/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0695 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
#define f first
#define s second
pii operator +(pii a, pii b) { return {a.f + b.f, a.s + b.s}; }

bool check(pii x) {
    if (x.f > 'I' || x.f < 'A' || x.s > '9' || x.s < '1') return false;
    return true;
}

bool usd(pii x) {
    static map<pii, bool> used;
    if (used.count(x)) return true;
    used[x] = true;
    return false;
}

int main() {
    char a, b; cin >> a >> b;
    pii start = {a, b};
    cin >> a >> b;
    pii end = {a, b}, sep = {0, 0};
    queue<pii> q; q.push(start); q.push(sep);
    int ans = 0; usd(start);
    while (true) {
        auto cur = q.front(); q.pop();
        if (cur == sep) {
            if (q.empty()) {
                cout << -1; return 0;
            }
            ans++; q.push(sep);
            continue;
        }
        if (cur == end) {
            cout << ans; return 0;
        }
        if ((cur.f + cur.s) % 2 == 1) {
            for (auto d: vector<pii>({{1, 2},{2, 1},{-1, 2},{-2, 1},{1, -2},{2, -1},{-1, -2},{-2, -1}})) {
                pii nxt = cur + d;
                if (check(nxt) && !usd(nxt)) {
                    q.push(nxt);
                }
            }
        } else {
            for (auto d: vector<pii>({{-1, -1},{1, -1},{-1, 1},{1, 1}})) {
                pii nxt = cur;
                while (check(nxt = nxt + d)) {
                    if (!usd(nxt)) q.push(nxt);
                }
            }
        }
    }
}