/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0949 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b; cin >> n >> b >> a;
    while (--n) {
        swap(a = a - b, b);
    }
    cout << b << ' ' << a;
}