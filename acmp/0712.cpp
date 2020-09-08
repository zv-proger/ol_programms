/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0712 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll w, h, n; cin >> w >> h >> n;
    if (h > w) swap(h, w);
    ll l = w * n, r = w - 1;
    while (r < l - 1) {
        ll m = (l + r) / 2;
        if ((n + m / w - 1) / (m / w) * h > m) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << l;
}