/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0257 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

void doans(vector<long long> d) {
    for (auto &x: d) cout << x << ' ';
    exit(0);
}

void doanss(set<long long> d) {
    cout << d.size() << ' ';
    for (auto &x: d) cout << x << ' ';
    exit(0);
}

map<int, int> cnt;
set<long long> ans;
long long a, b, c, d;

void step(__int128_t x, std::map<int, int>::iterator cr) {
    if (a * x * x * x + b * x * x + c * x + d == 0) ans.insert(x);
    x = - x;
    if (a * x * x * x + b * x * x + c * x + d == 0) ans.insert(x);
    if (cr == cnt.end()) return;
    auto nxt = cr; nxt++;
    step(x, nxt);
    int ct = cr -> second;
    while (ct--) step(x *= cr -> first, nxt);
}

int main() {
    cin >> a >> b >> c >> d;
    if (!a && !b && !c && !d) doans({-1});
    if (!a && !b && !c && d) doans({0});
    while (!d && (a || b)) { ans.insert(0); d = c; c = b; b = a; a = 0; }
    if (!a && !b ) {
        if (d % c == 0) ans.insert(-d / c);
        doanss(ans);
    }
    int x = abs(d);
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            x /= i;
            cnt[i--]++;
        }
    }
    if (x > 1) cnt[x]++;
    step(1, cnt.begin());
    doanss(ans);
}