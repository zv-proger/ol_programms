/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0464 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

char nxt(char a) {
    return ((a - '0') + 1) % 3 + '0';
}

int main() {
    long long x, y = 1; cin >> x;
    char a = '0';
    while (y < x) y *= 2;
    while (x != y) {
        if (y > x) y /= 2;
        if (x > y) { x -= y; a = nxt(a); }
    }
    while (y != 1) { y /= 2; a = nxt(a); }
    cout << a;
}