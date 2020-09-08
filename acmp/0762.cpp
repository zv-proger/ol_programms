/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0762 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n > 1) { ans++; n = n - 2 * n / 3; }
    cout << ans;
}