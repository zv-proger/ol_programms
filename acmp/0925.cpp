/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 925 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int c, n, a, b, c; cin >> c >> n >> a >> b >> c;
    int x = max (a + b - n, 0);
    x = max (x + c - n, 0);
    cout << (c - 1 ? min(a, min(b, c)) : x);
}