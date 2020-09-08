/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0526 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string a; cin >> a;
    for (auto &c: a) c = tolower(c);
    int b, x = 2; cin >> b;
    char buf[100];
    for (int i = x; i < 37; i++) {
        if (itoa(b, buf, i) == a) {
            cout << i; return 0;
        }
    }
    cout << 0;
}