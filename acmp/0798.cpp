/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0798 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, i, j, c; cin >> n >> m >> i >> j >> c;
    i += c;
    if (n % 2 && m % 2)
        cout << (i + j & 1 ? "black" : "white");
    else
        cout << "equal";
}