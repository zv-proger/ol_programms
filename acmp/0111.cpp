/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0111 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int x; cin >> x;
    int l;
    for (l = 3; l*l <= x; l++) { if (x % l == 0) break; }
    if (x % l != 0) l = x;
    if (x % 2 == 0 && x > 4) l = min(l, x / 2);
    if (l < 3) l = 1;
    cout << l - 1;
}