/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0786 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int i = 1;
    while (i <= n) i *= 2;
    cout << n - i / 2;
}