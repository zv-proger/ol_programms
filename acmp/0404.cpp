/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0404 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool calc(ll n) {
    if (n == 2 || n == 5 || n == 8) return false;
    if (n < 8) return true;
    ll last = 8, pr, i = 3;
    while (last <= n) {
        i++; pr = last;
        last += (i * i - 1 - last) / i * i;
    }
    return (n - pr) % i != 0;
}

int main() {
    ll n; cin >> n;
    cout << (calc(n) ? "WIN" : "LOSE");
}