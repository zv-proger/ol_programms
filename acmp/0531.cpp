/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0531 с сайта acmp.ru
*/
    
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll x1, y1, x2, y2, xc, yc, r; cin >> x1 >> y1 >> x2 >> y2 >> xc >> yc >> r;
    ll ans = 0;
    for (ll i = y1; i <= y2; i++) {
        if (abs(i - yc) > r) continue;
        ll d = sqrt(r * r - (i - yc) * (i - yc)) + 1e-9;
        ans += max(0LL, min(x2, xc + d) - max(x1, xc - d) + 1);
    }
    cout << ans;
}