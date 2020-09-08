/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0790 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

char dig(int x) {
    if (x < 10) return '0' + x;
    return 'A' + x - 10;
}

string toradix(int x, int d) {
    string v;
    while (x) {
        v = dig(x % d) + v;
        x /= d;
    }
    return v;
}

int main() {
    char c;
    int d, m, y; cin >> d >> c >> m >> c >> y;
    cout << toradix(d, d+1) << c << toradix(m, d+1) << c << toradix(y, d+1);
}