/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0319 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b? gcd(b, a%b): a;
}

int main() {
    int x, y, xx, yy; cin >> x >> y >> xx >> yy;
    cout << gcd(abs(x-xx), abs(y-yy)) + 1;
}