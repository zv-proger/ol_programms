/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0947 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    double x; cin >> x;
    int i = 2;
    double s = 0;
    for (; s < x + 1e-14; i++) s += 1.0 / i;
    cout << i - 2 << " card(s)";
}