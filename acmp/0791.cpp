/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0791 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int i; cin >> i;
    i--;
    if (i >= 8) { cout << i - 8 + 1 << ' '; }
    if (i % 8) { cout << i << ' '; }
    if ((i + 1) % 8) { cout << i + 2 << ' '; }
    if (i + 8 < 64) { cout << i + 8 + 1 << ' '; }
}