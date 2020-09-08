/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0971 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y; cin >> x >> y;
    if (abs(x) == 1000'000'000 || abs(y) == 1000'000'000) {
        cout << "NO"; return 0;
    }
    cout << "YES" << endl;
    cout << x - 1 << ' ' << y + 1 << endl;
    cout << x + 1 << ' ' << y << endl;
    cout << x << ' ' << y - 1 << endl;
}