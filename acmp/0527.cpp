/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0527 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool calc(ll a, ll b, ll c, ll d) {
    if (a == c && d == b) return 1;
    if (b < min(c, d)) return 0;
    if (a < b) swap(a, b);
    if (a == c && d == b) return 1;
    if (b == min(c, d) && a < max(c, d)) return 0;
    if (b == 0) return 0;
    if (b != d) return calc (a % b, b, c, d);
    return (c - a % b) % b == 0;
}

int main() {
    int t; cin >> t;
    for (; t--;) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        cout << (calc(a, b, c, d) ? "YES" : "NO") << endl;
    }
}