/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0841 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    if (!n) cout << 1;
    else cout << n*(n-1) + 2;
}