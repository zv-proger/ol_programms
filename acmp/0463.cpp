/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0463 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int dig(char c) {
    if (isdigit(c)) return c - '0';
    if (isupper(c)) return c - 'A' + 10;
    if (islower(c)) return c - 'a' + 10;
    return -1;
}

int main() {
    int k, m; string s; cin >> k >> m >> s;
    int a = 0;
    for (auto c: s) {
        a = a * k + dig(c);
        a %= m;
    }
    cout << a;
}