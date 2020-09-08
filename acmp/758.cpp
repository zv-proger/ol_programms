/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 758 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int dt[100000];
    for (int i = 0; i < n; i++) {
        cin >> dt[i];
    }
    sort(dt, dt + n);
    if (n == 1) { cout << *dt; return 0; }
    int a = dt[0], b = dt[1];
    ll ans = 0;
    while (n > 3) {
        ans += 2 * b + a + dt[n - 1];
        n -= 2;
    }
    if (n == 3) {
        ans += a + b + dt[2];
    } else {
        ans += b;
    }
    cout << ans;
}