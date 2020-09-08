/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0184 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
ll readTm() {
    ll ans = 0, d, m, h, mn; char c;
    vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> d >> c >> m >> c >> h >> c >> mn;
    for (int i = 0; i < m; i++) ans += days[i];
    ans += d; ans *= 24; ans += h; ans *= 60; ans += mn;
    return ans;
}

void printTmDlta(ll tm) {
    cout << tm / 60 << ':';
    tm %= 60; if (tm < 10) cout << 0;
    cout << tm;
}

int main() {
    int n; cin >> n;
    vector<ll> dt(n); for (auto &x: dt) x = readTm();
    sort(dt.begin(), dt.end());
    ll ans = 0;
    for (; !dt.empty();) {
        ll e = dt.back(); dt.pop_back();
        ll s = dt.back(); dt.pop_back();
        ans += (e - s) / 24 / 60 * 8 * 60;
        e %= 24 * 60; s %= 24 * 60;
        ans += (e - s + 8 * 60) % (8 * 60) + 1;
    }
    printTmDlta(ans);
}