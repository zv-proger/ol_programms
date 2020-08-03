/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0778 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t = 0;
    for (int x; cin >> x; t += x);
    cout << t / 27;
}