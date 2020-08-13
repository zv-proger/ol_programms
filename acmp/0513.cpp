/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0513 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int a; cin >> a;
    cout << (1 << a) - 1 - a;
}