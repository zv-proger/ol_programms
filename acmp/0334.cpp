/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0334 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll total = 43200;

ll readTime() {
    int h, m, s; char c; cin >> h >> c >> m >> c >> s;
    return h * 60 * 60 + m * 60 + s;
}

void printTime(ll tm) {
    cout << tm / 3600 << ':';
    tm %= 3600; if (tm < 600) cout << 0;
    cout << tm / 60 << ":";
    tm %= 60; if (tm < 10) cout << 0;
    cout << tm << endl;
}

int main() {
    map<ll, int> cnt;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cnt[readTime()] ++;
    }

    ll ans = cnt.begin() -> first, best = 0;

    ll cur = ans, curc = best;
    for (auto &p: cnt) {
        if (p.first == cur) continue;
        curc += n * (p.first - cur);
        curc -= total * p.second;
        cur = p.first;
        if (curc < best || curc == best && ans / 3600 == 0 && cur / 3600 != 0) { ans = cur; best = curc; }
    }
    printTime(ans);
}