/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0782 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;
    int ans = 0;
    while (n > 1) {
        ans += n / 2;
        n = (n + 1) / 2;
    }
    return ans + 1;
}

int main() {
    ll n; cin >> n;
    cout << solve(n);
}