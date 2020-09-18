/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0705 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(), x.end()

using ll = long long;
ll n, m;

ll norm(ll x) {
    return (x % m + m) % m;
}

ll mpow(ll x, ll k) {
    if (k == 0) return 1;
    if (k == 1) return norm(x);
    return norm(mpow(norm(x * x), k / 2) * norm(mpow(x, k % 2)));
}


int main() {
    cin >> n >> m;
    n--;
    ll ans = norm(-6 + mpow(2, n + 1) * norm(3 - 2 * n + n * n));
    cout << ans << endl;
}