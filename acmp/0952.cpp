/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0952 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if (!a && b) cout << "Impossible";
    else
        cout << max(0, b - a) + a << ' ' << a + b - !!b;
}