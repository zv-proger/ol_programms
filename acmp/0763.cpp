/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0763 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if (a == 1 && b == 1) cout << 0;
    else if (a == b) cout << 2;
         else cout << 1;
}