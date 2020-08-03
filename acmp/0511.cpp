/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0511 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    n--;
    int x = n / 12, y = n % 12 * 5;
    if (x > 12 || (x == 12 && y)) { cout << "NO"; exit(0); }
    cout << x << ' ' << y;
}