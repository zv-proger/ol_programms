/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0842 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll x) {
    while (x % 2 == 0) x /= 2;
    while (x % 5 == 0) x /= 5;
    return x == 1;
}

int main() {
    ll x; cin >> x;
    cout << (check(x)? "NO": "YES");
}