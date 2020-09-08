/*
    Автор кода: Вадим Зинов (zv.proger@yandex.ru)
    Решение задачи 0462 с сайта acmp.ru
*/

#include<bits/stdc++.h>
using namespace std;

int dt[31];

int main() {
    for (int i = 1; i < 31; i++) {
        dt[i] = (i % 2) * (i % 3) *(i % 5) != 0;
        dt[i] += dt[i-1];
    }
    int n; cin >> n;
    cout << n / 30 * dt[30] + dt[n % 30];
}